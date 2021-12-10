using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using System.Net.Http.Headers;
using Microsoft.AspNetCore.Http.Extensions;

using SpotifyAPI.Web;
using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class SpotifyModel : PageModel
    {

        // CLASSES
        public class Settings
        {
            public bool logged = false;
            public string method = "post";
            public string url = "https://accounts.spotify.com/api/token";
            public string grant_type = "authorization_code";
            public string code = "code";
            public string redirect_uri = "http://0.0.0.0:8080/Callback";
            public string client_secret = "3369eaad77154324befde25c26f0f401";
            public string client_id = "b2aab053fc67420abcde533046c2da7e";
            public string scope = "user-read-private user-read-email user-modify-playback-state user-read-playback-position user-library-read streaming user-read-playback-state user-read-recently-played playlist-read-private";
        };

        public class SUser
        {
            public string id = null;
            public string email = null;
            public string name = null;
            public string followers = null;
            public List<SpotifyUser.Image> images = null;
            public string token = null;
        };
        
        Settings settings = new Settings();
        static Authentification authentification = new Authentification("spotify");
        SUser user = new SUser();
        Requests requests = new Requests(authentification);
        Password password = new Password();
        Html html = new Html();
        SpotifyToken.Root spotify_token = new SpotifyToken.Root();
        SpotifyUser.Root spotify_user = new SpotifyUser.Root();


        // VARIABLES
        SpotifyClient client;
        public string login_url = null;

        private Task load_cache()
        {
            string[] files = null;
    
            if (Directory.Exists("cache") == true) {
                files = Directory.GetFiles("cache");
                foreach (string file in files) {
                    if (file.StartsWith($"cache/{authentification.module}.") == true) {
                        authentification.fetch = System.IO.File.ReadAllText(file);
                        Console.WriteLine($"token restored: {authentification.fetch}");
                    }
                }
            }

            return (Task.CompletedTask);
        }

        private async Task<Task> create_client(string token)
        {
            SpotifyClientConfig config = SpotifyClientConfig.CreateDefault();
            ClientCredentialsRequest request = new ClientCredentialsRequest(settings.client_id, settings.client_secret);  var response = await new OAuthClient(config).RequestToken(request);
            client = new SpotifyClient(config.WithToken(token));

            return (Task.CompletedTask);
        }

        private async Task<Task> login_user()
        {
            string state = await password.generate(16);
            string result = null;
            Dictionary<string, string> headers = new Dictionary<string, string>()
            {
                {"Accept-Encoding", "deflate, gzip"},
                {"Accept", "*/*"},
                {"Content-Type", "application/json"}
            };
            login_url = await html.encode($"https://accounts.spotify.com/authorize?response_type=code&client_id={settings.client_id}&redirect_uri={settings.redirect_uri}&scope={settings.scope}&state={state}");

            Dictionary<string, string> informations_ = await requests.create(
                login_url,
                headers,
                null,
                null
            );

            result = await requests.get(informations_);

            return (Task.CompletedTask);
        }

        private async Task<Task> login()
        {
            string fetched = null;

            await load_cache();
            await login_user();
            fetched = await fetch_token(authentification.fetch);
            if (fetched != null && authentification.token != null) {
                Console.WriteLine("TOKEN FETCHED");
                await create_client(authentification.token);
                await me(authentification.token);
                user.id = spotify_user.id;
                user.name = spotify_user.display_name;
                user.email = spotify_user.email;
                user.images = spotify_user.images;
                if (spotify_user.followers != null)
                    user.followers = $"{spotify_user.followers.total}";
                user.token = spotify_token.access_token;
                await user_informations();
                settings.logged = true;
            } else {
                Console.WriteLine("fetch invalid, waiting to new fetch");
            }

            return (Task.CompletedTask);
        }

        public async Task<Task> me(string token)
        {
            Dictionary<string, string> headers = null;
            Dictionary<string, string> data = null;
            string user_data = null;

            headers = new Dictionary<string, string>()
            {
                {"Authorization", $"Bearer {token}"},
                {"Accept-Encoding", "deflate, gzip"},
                {"Accept", "*/*"},
                {"Content-Type", "application/json"}
            };
            data = await requests.create("https://api.spotify.com/v1/me", headers, null, null);
            user_data = await requests.get(data);
            Console.WriteLine($"TOKEN : {token}");
            Console.WriteLine(user_data);
            spotify_user = JsonConvert.DeserializeObject<SpotifyUser.Root>(user_data);

            return (Task.CompletedTask);
        }

        public async Task<Dictionary<string, string>> user_informations()
        {
            Dictionary<string, string> data = new Dictionary<string, string>()
            {
                {"id", user.id},
                {"name", user.name},
                {"email", user.email},
                {"followers", user.followers}
            };
            if (user.images != null) {
                for (int i = 0; i < user.images.Count; i++) {
                    data.Add($"image_{i}", user.images[i].url);
                }
                Console.WriteLine(data.Count);
            }
            foreach (var item in data) {
                Console.WriteLine($"{item.Key} : {item.Value}");
            }
    
            return (data);
        }

        // EVENTS
        public async Task<string> call_login()
        {
            await login();

            return (login_url);
        }

        public async Task<bool> is_logged()
        {
            return (settings.logged);
        }


        public async Task logout()
        {
            user.id = null;
            user.name = null;
            user.email = null;
            user.images = null;
            user.followers = null;
            user.token = null;

            settings.logged = false;
        }

        public async Task<string> fetch_token(string token)
        {
            string result = null;
            Dictionary<string, string> data = null;

            Dictionary<string, string> headers = new Dictionary<string, string>()
            {
                {"Authorization", $"Basic {System.Convert.ToBase64String(System.Text.Encoding.UTF8.GetBytes($"{settings.client_id}:{settings.client_secret}"))}"},
                {"Content-Type", "application/x-www-form-urlencoded"}
            };
            data = await requests.create(
                $"https://accounts.spotify.com/api/token?grant_type=authorization_code&code={token}&redirect_uri={settings.redirect_uri}",
                headers,
                null,
                null
            );

            result = await requests.post(data);
            if (result.Contains("Invalid") == false) {
                spotify_token = JsonConvert.DeserializeObject<SpotifyToken.Root>(result);
                authentification.token = spotify_token.access_token;
                return (result);
            }
            return (null);
        }


        // WIDGETS

        public async Task<SpotifyTrack.Root> search_track(string data)
        {
            SpotifyTrack.Root result = new SpotifyTrack.Root();
            Dictionary<string, string> headers = new Dictionary<string, string>()
            {
                {"Accept-Encoding", "deflate, gzip"},
                {"Accept", "*/*"},
                {"Content-Type", "application/json"},
                {"Authorization", $"Bearer {authentification.token}"}
            };
            data = data.Replace(" ", "+");

            Dictionary<string, string> track = await requests.create(
                $"https://api.spotify.com/v1/search?q=track%3A{data}&type=track&limit=10",
                headers,
                null,
                null
            );

            string t_data = await requests.get(track);

            if (t_data.Contains("Only valid bearer authentication supported") == false) {
                result = JsonConvert.DeserializeObject<SpotifyTrack.Root>(t_data);
                return (result);
            }

            return (null);
        }

        public async Task<SpotifyArtist.Root> search_artist(string data)
        {
            SpotifyArtist.Root result = new SpotifyArtist.Root();
            Dictionary<string, string> headers = new Dictionary<string, string>()
            {
                {"Accept-Encoding", "deflate, gzip"},
                {"Accept", "*/*"},
                {"Content-Type", "application/json"},
                {"Authorization", $"Bearer {authentification.token}"}
            };
            data = data.Replace(" ", "+");

            Dictionary<string, string> artist = await requests.create(
                $"https://api.spotify.com/v1/search?q=artist%3A{data}&type=artist&limit=10",
                headers,
                null,
                null
            );

            string a_data = await requests.get(artist);

            if (a_data.Contains("Only valid bearer authentication supported") == false) {
                result = JsonConvert.DeserializeObject<SpotifyArtist.Root>(a_data);
                return (result);
            }

            return (null);
        }

        public async Task<Paging<SimpleAlbum>> search_album(string artist)
        {
            SpotifyArtist.Root artist_data = null;
            Paging<SimpleAlbum> albums = null;
            Paging<SimpleAlbum> cleared = new Paging<SimpleAlbum>();

            artist_data = await search_artist(artist);
            if (artist_data != null) {
                if (artist_data.artists != null) {
                    for (int a = 0; a < artist_data.artists.items.Count; a++) {
                        if (artist_data.artists.items[a].id != null) {
                            albums = await get_albums(artist_data.artists.items[a].id);
                            cleared.Items = new List<SimpleAlbum>();
                            for (int i = 0; i < albums.Items.Count; i++) {
                                for (int artist_al = 0; artist_al < albums.Items[i].Artists.Count; artist_al++) {
                                    if (compare(albums.Items[i].Artists[artist_al].Name, artist) == true) {
                                        if (cleared.Items.Contains(albums.Items[i]) == false) {
                                            //Console.WriteLine($"{albums.Items[i].Name} {albums.Items[i].Id} {albums.Items[i].ReleaseDate}");
                                            cleared.Items.Add(albums.Items[i]);
                                        }
                                    }
                                }
                            }
                            return (cleared);
                        }
                    }
                    return (cleared);
                }
                return (null);
            }

            return (null);
        }

        public async Task<List<FullTrack>> search_top(string artist)
        {
            SpotifyArtist.Root artist_data = null;
            ArtistsTopTracksResponse top = null;
            List<FullTrack> cleared = new List<FullTrack>();
            int limit = 10;

            artist_data = await search_artist(artist);
            if (artist_data != null) {
                if (artist_data.artists != null) {
                    if (artist_data.artists.items.Count > 0) {
                        top = await get_top(artist_data.artists.items[0].id);
                        for (int j = 0; j < top.Tracks.Count && j < limit; j++) {
                            //Console.WriteLine(top.Tracks[j].Name);
                            cleared.Add(top.Tracks[j]);
                        }
                    }
                    return (cleared);
                }
                return (null);
            }

            return (null);
        }

        public async Task<SpotifyPlaylist.Root> search_playlist()
        {
            SpotifyPlaylist.Root result = new SpotifyPlaylist.Root();
            Dictionary<string, string> headers = new Dictionary<string, string>()
            {
                {"Accept-Encoding", "deflate, gzip"},
                {"Accept", "*/*"},
                {"Content-Type", "application/json"},
                {"Authorization", $"Bearer {authentification.token}"}
            };
            Dictionary<string, string> playlists = await requests.create(
                "https://api.spotify.com/v1/me/playlists",
                headers,
                null,
                null
            );

            string p_data = await requests.get(playlists);

            if (p_data.Contains("Only valid bearer authentication supported") == false) {
                result = JsonConvert.DeserializeObject<SpotifyPlaylist.Root>(p_data);
                //Console.WriteLine(p_data);
                return (result);
            }

            return (null);
        }

        private bool compare(string a, string b)
        {
            if (a.Length == b.Length) {
                for (int i = 0; i < a.Length; i++) {
                    if (char.ToUpper(a[i]) != char.ToUpper(b[i]))
                        return (false);
                }

                return (true);
            }
            return (false);
        }

        public async Task<Paging<SimpleAlbum>> get_albums(string id)
        {
            return (await client.Artists.GetAlbums(id));               
        }

        public async Task<ArtistsTopTracksResponse> get_top(string id)
        {
            ArtistsTopTracksRequest request_top = new ArtistsTopTracksRequest("US");
            return (await client.Artists.GetTopTracks(id, request_top));
        }

        public async Task<Task> follow(string playlistid)
        {
            //Console.WriteLine($"Following {playlistid}");
            await client.Follow.FollowPlaylist(playlistid);
            //Console.WriteLine($"Followed {playlistid}");

            return (Task.CompletedTask);
        }

        public async Task<Task> unfollow(string playlistid)
        {
            //Console.WriteLine($"Unfollowing {playlistid}");
            await client.Follow.UnfollowPlaylist(playlistid);
            //Console.WriteLine($"Unfollowed {playlistid}");

            return (Task.CompletedTask);
        }

        public async Task<string> get_user_name()
        {
            return (user.name);
        }

        public async Task<string> get_user_id()
        {
            return (user.id);
        }

        public async Task<string> get_user_email()
        {
            return (user.email);
        }

        public async Task<string> get_user_followers()
        {
            return (user.followers);
        }

        public async Task<string> get_user_token()
        {
            return (user.token);
        }

        public async Task<List<SpotifyUser.Image>> get_user_image()
        {
            return (user.images);
        }
    }
}
