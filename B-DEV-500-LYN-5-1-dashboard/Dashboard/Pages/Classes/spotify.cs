using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class SpotifyToken
    {
        public class Root
        {
            public string access_token { get; set; }
            public string token_type { get; set; }
            public int expires_in { get; set; }
            public string refresh_token { get; set; }
            public string scope { get; set; }
        }
    }

    public class SpotifyUser
    {
        public class ExplicitContent
        {
            public bool filter_enabled { get; set; }
            public bool filter_locked { get; set; }
        }

        public class ExternalUrls
        {
            public string spotify { get; set; }
        }

        public class Followers
        {
            public object href { get; set; }
            public int total { get; set; }
        }

        public class Image
        {
            public object height { get; set; }
            public string url { get; set; }
            public object width { get; set; }
        }

        public class Root
        {
            public string country { get; set; }
            public string display_name { get; set; }
            public string email { get; set; }
            public ExplicitContent explicit_content { get; set; }
            public ExternalUrls external_urls { get; set; }
            public Followers followers { get; set; }
            public string href { get; set; }
            public string id { get; set; }
            public List<Image> images { get; set; }
            public string product { get; set; }
            public string type { get; set; }
            public string uri { get; set; }
        }

    }

    public class SpotifyTrack
    {
        public class ExternalUrls
        {
            public string spotify { get; set; }
        }

        public class Artist
        {
            public ExternalUrls external_urls { get; set; }
            public string href { get; set; }
            public string id { get; set; }
            public string name { get; set; }
            public string type { get; set; }
            public string uri { get; set; }
        }

        public class Image
        {
            public int height { get; set; }
            public string url { get; set; }
            public int width { get; set; }
        }

        public class Album
        {
            public string album_type { get; set; }
            public List<Artist> artists { get; set; }
            public ExternalUrls external_urls { get; set; }
            public string href { get; set; }
            public string id { get; set; }
            public List<Image> images { get; set; }
            public string name { get; set; }
            public string release_date { get; set; }
            public string release_date_precision { get; set; }
            public int total_tracks { get; set; }
            public string type { get; set; }
            public string uri { get; set; }
        }

        public class ExternalIds
        {
            public string isrc { get; set; }
        }

        public class Item
        {
            public Album album { get; set; }
            public List<Artist> artists { get; set; }
            public int disc_number { get; set; }
            public int duration_ms { get; set; }
            public bool @explicit { get; set; }
            public ExternalIds external_ids { get; set; }
            public ExternalUrls external_urls { get; set; }
            public string href { get; set; }
            public string id { get; set; }
            public bool is_local { get; set; }
            public bool is_playable { get; set; }
            public string name { get; set; }
            public int popularity { get; set; }
            public string preview_url { get; set; }
            public int track_number { get; set; }
            public string type { get; set; }
            public string uri { get; set; }
        }

        public class Tracks
        {
            public string href { get; set; }
            public List<Item> items { get; set; }
            public int limit { get; set; }
            public string next { get; set; }
            public int offset { get; set; }
            public string previous { get; set; }
            public int total { get; set; }
        }

        public class Root
        {
            public Tracks tracks { get; set; }
        }
    }

    public class SpotifyArtist
    {
        public class ExternalUrls
        {
            public string spotify { get; set; }
        }

        public class Followers
        {
            public object href { get; set; }
            public int total { get; set; }
        }

        public class Image
        {
            public int height { get; set; }
            public string url { get; set; }
            public int width { get; set; }
        }

        public class Item
        {
            public ExternalUrls external_urls { get; set; }
            public Followers followers { get; set; }
            public List<object> genres { get; set; }
            public string href { get; set; }
            public string id { get; set; }
            public List<Image> images { get; set; }
            public string name { get; set; }
            public int popularity { get; set; }
            public string type { get; set; }
            public string uri { get; set; }
        }

        public class Artists
        {
            public string href { get; set; }
            public List<Item> items { get; set; }
            public int limit { get; set; }
            public string next { get; set; }
            public int offset { get; set; }
            public string previous { get; set; }
            public int total { get; set; }
        }

        public class Root
        {
            public Artists artists { get; set; }
        }
    }

    public class SpotifyPlaylist
    {
        public class ExternalUrls
        {
            public string spotify { get; set; }
        }

        public class Image
        {
            public object height { get; set; }
            public string url { get; set; }
            public object width { get; set; }
        }

        public class Owner
        {
            public string display_name { get; set; }
            public ExternalUrls external_urls { get; set; }
            public string href { get; set; }
            public string id { get; set; }
            public string type { get; set; }
            public string uri { get; set; }
        }

        public class Tracks
        {
            public string href { get; set; }
            public int total { get; set; }
        }

        public class Item
        {
            public bool collaborative { get; set; }
            public string description { get; set; }
            public ExternalUrls external_urls { get; set; }
            public string href { get; set; }
            public string id { get; set; }
            public List<Image> images { get; set; }
            public string name { get; set; }
            public Owner owner { get; set; }
            public object primary_color { get; set; }
            public bool @public { get; set; }
            public string snapshot_id { get; set; }
            public Tracks tracks { get; set; }
            public string type { get; set; }
            public string uri { get; set; }
        }

        public class Root
        {
            public string href { get; set; }
            public List<Item> items { get; set; }
            public int limit { get; set; }
            public object next { get; set; }
            public int offset { get; set; }
            public object previous { get; set; }
            public int total { get; set; }
        }
    }
}