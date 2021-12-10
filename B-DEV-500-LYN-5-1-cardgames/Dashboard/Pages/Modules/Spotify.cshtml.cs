using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using System.Net.Http.Headers;
using Microsoft.AspNetCore.Http.Extensions;

using System.IO;

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
            public string redirect_uri = "http://localhost:8080/Callback";
            public string client_secret = "3369eaad77154324befde25c26f0f401";
            public string client_id = "b2aab053fc67420abcde533046c2da7e";
            public string scope = "user-read-private user-read-email user-modify-playback-state user-read-playback-position user-library-read streaming user-read-playback-state user-read-recently-played playlist-read-private";
        };

        public class User
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
        User user = new User();
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
    
            Console.WriteLine("Loading cache...");
            if (Directory.Exists("cache") == true) {
                files = Directory.GetFiles("cache");
                foreach (string file in files) {
                    if (file.StartsWith($"cache/{authentification.module}.") == true) {
                        Console.WriteLine("Loading cache data");
                        authentification.fetch = System.IO.File.ReadAllText(file);
                        Console.WriteLine($"token restored: {authentification.fetch}");
                    }
                }
            } else {
                Console.WriteLine("No cache to load");
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
            Console.WriteLine(result);

            return (Task.CompletedTask);
        }

        private async Task<Task> login()
        {
            string fetched = null;

            await load_cache();
            await login_user();
            if (authentification.fetch != null) {
                fetched = await fetch_token(authentification.fetch);
                if (fetched != null) {
                    await create_client(authentification.token);
                    await me();
                    user.id = spotify_user.id;
                    user.name = spotify_user.display_name;
                    user.email = spotify_user.email;
                    user.images = spotify_user.images;
                    user.followers = $"{spotify_user.followers.total}";
                    user.token = spotify_token.access_token;
                    await user_informations();
                } else {
                    Console.WriteLine("fetch invalid, waiting to new fetch");
                }
            }

            return (Task.CompletedTask);
        }

        private async Task<Task> me()
        {
            Dictionary<string, string> headers = null;
            Dictionary<string, string> data = null;
            string user_data = null;

            headers = new Dictionary<string, string>()
            {
                {"Authorization", $"Bearer {authentification.token}"},
                {"Accept-Encoding", "deflate, gzip"},
                {"Accept", "*/*"},
                {"Content-Type", "application/json"}
            };
            data = await requests.create("https://api.spotify.com/v1/me", headers, null, null);
            user_data = await requests.get(data);
            spotify_user = JsonConvert.DeserializeObject<SpotifyUser.Root>(user_data);

            return (Task.CompletedTask);
        }

        private async Task<Dictionary<string, string>> user_informations()
        {
            Dictionary<string, string> data = new Dictionary<string, string>()
            {
                {"id", user.id},
                {"name", user.name},
                {"email", user.email},
                {"followers", user.followers}
            };

            for (int i = 0; i < user.images.Count; i++) {
                data.Add($"image_{i}", user.images[i].url);
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

            settings.logged = true;

            return (login_url);
        }

        public async Task<bool> is_logged()
        {
            return (settings.logged);
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

        public async Task<string> search(string data)
        {
            int limit = 2;
            Dictionary<string, string> headers = new Dictionary<string, string>()
            {
                {"Accept-Encoding", "deflate, gzip"},
                {"Accept", "*/*"},
                {"Content-Type", "application/json"},
                {"Authorization", $"Bearer {authentification.token}"}
            };
            data = data.Replace(" ", "+");

            Dictionary<string, string> artist = await requests.create(
                $"https://api.spotify.com/v1/search?q=artist%3A{data}&type=artist&market=ES&limit={limit}&offset=5",
                headers,
                null,
                null
            );
            Dictionary<string, string> track = await requests.create(
                $"https://api.spotify.com/v1/search?q=track%3A{data}&type=track&market=ES&limit={limit}&offset=5",
                headers,
                null,
                null
            );

            string a_data = await requests.get(artist);
            string t_data = await requests.get(track);

            Console.WriteLine(a_data);
            Console.WriteLine(t_data);

            return (null);
        }

        public async Task<Task> follow(string playlistid)
        {
            Console.WriteLine($"Following {playlistid}");
            await client.Follow.FollowPlaylist(playlistid);
            Console.WriteLine($"Followed {playlistid}");

            return (Task.CompletedTask);
        }

        public async Task<Task> unfollow(string playlistid)
        {
            Console.WriteLine($"Unfollowing {playlistid}");
            await client.Follow.UnfollowPlaylist(playlistid);
            Console.WriteLine($"Unfollowed {playlistid}");

            return (Task.CompletedTask);
        }
    }
}
