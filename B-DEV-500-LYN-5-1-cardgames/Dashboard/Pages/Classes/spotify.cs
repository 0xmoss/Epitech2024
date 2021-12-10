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
}