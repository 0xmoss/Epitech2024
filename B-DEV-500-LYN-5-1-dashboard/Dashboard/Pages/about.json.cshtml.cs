using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class AboutModel : PageModel
    {
        // TEST
        public class Spotify
        {
            public string name = "spotify";

            public About_json.Service service = new About_json.Service();

            public List<About_json.Widget> widgets = new List<About_json.Widget>()
            {
                search_artist,
                search_track,
                search_top_track,
                search_album,
                get_playlists,
                follow_playlist,
                unfollow_playlist
            };

            // WIDGETS
                // SEARCH
                static public About_json.Param p_artist = create_parameters("artist name", "string");
                static public About_json.Param p_track = create_parameters("track name", "string");
                static public About_json.Param p_t_track = create_parameters("artist name", "string");
                static public About_json.Param p_al = create_parameters("artist name", "string");
                static public About_json.Param p_p_follow = create_parameters("playlist id", "string");
                static public About_json.Param p_p_unfollow = create_parameters("playlist id", "string");
                static public List<About_json.Param> s_a_param = new List<About_json.Param>()
                {
                    p_artist
                };
                static public List<About_json.Param> s_t_param = new List<About_json.Param>()
                {
                    p_track
                };
                static public List<About_json.Param> s_t_t_param = new List<About_json.Param>()
                {
                    p_t_track
                };
                static public List<About_json.Param> s_al_param = new List<About_json.Param>()
                {
                    p_al
                };
                static public List<About_json.Param> p_f_param = new List<About_json.Param>()
                {
                    p_p_follow
                };
                static public List<About_json.Param> p_u_param = new List<About_json.Param>()
                {
                    p_p_unfollow
                };
                static public About_json.Widget search_artist = create_widget("search_artist", "search for artist", s_a_param);
                static public About_json.Widget search_track = create_widget("search_track", "search for track", s_t_param);
                static public About_json.Widget search_top_track = create_widget("search_top_track", "search for top track", s_t_t_param);
                static public About_json.Widget search_album = create_widget("search_album", "search for artist albums", s_al_param);

                // PLAYLISTS
                static public About_json.Widget get_playlists = create_widget("get_playlists", "get your own playlists", null);
                static public About_json.Widget follow_playlist = create_widget("follow_playlist", "follow a specific playlist", p_f_param);
                static public About_json.Widget unfollow_playlist = create_widget("unfollow_playlist", "unfollow a specific playlist", p_u_param);
        }

        public class Quote
        {
            public string name = "quote";

            public About_json.Service service = new About_json.Service();

            public List<About_json.Widget> widgets = new List<About_json.Widget>()
            {
                get_random
            };

            // WIDGETS
                // RANDOM
                static public About_json.Widget get_random = create_widget("get_random", "get a random anime quote", null);
        }

        public class Meme
        {
            public string name = "meme";

            public About_json.Service service = new About_json.Service();

            public List<About_json.Widget> widgets = new List<About_json.Widget>()
            {
                get_random
            };

            // WIDGETS
                // RANDOM
                static public About_json.Widget get_random = create_widget("get_random", "get a random meme", null);
        }

        public class Duck
        {
            public string name = "duck";

            public About_json.Service service = new About_json.Service();

            public List<About_json.Widget> widgets = new List<About_json.Widget>()
            {
                get_random
            };

            // WIDGETS
                // RANDOM
                static public About_json.Widget get_random = create_widget("get_random", "get a random duck", null);
        }

        public class Dog
        {
            public string name = "dog";

            public About_json.Service service = new About_json.Service();

            public List<About_json.Widget> widgets = new List<About_json.Widget>()
            {
                get_random
            };

            // WIDGETS
                // RANDOM
                static public About_json.Widget get_random = create_widget("get_random", "get a random dog", null);
        }

        public class Insult
        {
            public string name = "insult";

            public About_json.Service service = new About_json.Service();

            public List<About_json.Widget> widgets = new List<About_json.Widget>()
            {
                get_random
            };

            // WIDGETS
                // RANDOM
                static public About_json.Widget get_random = create_widget("get_random", "get a random insult for free (and fun)", null);
        }

        public class Coffee
        {
            public string name = "coffee";

            public About_json.Service service = new About_json.Service();

            public List<About_json.Widget> widgets = new List<About_json.Widget>()
            {
                subscribers,
                supporters,
                extras
            };

            // WIDGETS
                // SUBSCRIBERS
                static public About_json.Widget subscribers = create_widget("subscribers", "get all your subscribers", null);
                static public About_json.Widget supporters = create_widget("supporters", "get all your supporters", null);
                static public About_json.Widget extras = create_widget("extras", "get all your extras", null);
        }

        public class Weather
        {
            public string name = "weather";

            public About_json.Service service = new About_json.Service();

            public List<About_json.Widget> widgets = new List<About_json.Widget>()
            {
                temperature,
                wind_speed,
                humidity,
                name_w,
                country,
                region,
                latitude,
                longitude
            };

            // WIDGETS
                // SUBSCRIBERS
                static public About_json.Widget temperature = create_widget("temperature", "get current city temperature", null);
                static public About_json.Widget wind_speed = create_widget("wind_speed", "get current city windspeed", null);
                static public About_json.Widget humidity = create_widget("humidity", "get current city humidity", null);
                static public About_json.Widget name_w = create_widget("name", "get current city name", null);
                static public About_json.Widget country = create_widget("country", "get current city country", null);
                static public About_json.Widget region = create_widget("region", "get current city region", null);
                static public About_json.Widget latitude = create_widget("latitude", "get current city latitude", null);
                static public About_json.Widget longitude = create_widget("longitude", "get current city longitude", null);

        }


        About_json.Root rootobject = new About_json.Root();
        Spotify spotify = new Spotify();
        Quote quote = new Quote();
        Meme meme = new Meme();
        Insult insult = new Insult();
        Coffee coffee = new Coffee();
        Duck duck = new Duck();
        Dog dog = new Dog();
        Weather weather = new Weather();


        public string host = null;

        public async Task<string> load()
        {
            string about = null;
            string output = "Pages/about_data.json";

            // CLIENT INFORMATIONS
            rootobject.Client = new About_json.Client();
            rootobject.Client.host = host;

            // SERVER INFORMATIONS
            rootobject.Server = new About_json.Server();
            rootobject.Server.CurrentTime = DateTimeOffset.Now.ToUnixTimeSeconds();

            rootobject.Server.Services = new List<About_json.Service>();

            spotify.service = new About_json.Service();
            spotify.service.name = spotify.name;
            spotify.service.Widgets = spotify.widgets;

            quote.service = new About_json.Service();
            quote.service.name = quote.name;
            quote.service.Widgets = quote.widgets;

            meme.service = new About_json.Service();
            meme.service.name = meme.name;
            meme.service.Widgets = meme.widgets;

            duck.service = new About_json.Service();
            duck.service.name = duck.name;
            duck.service.Widgets = duck.widgets;

            dog.service = new About_json.Service();
            dog.service.name = dog.name;
            dog.service.Widgets = dog.widgets;

            insult.service = new About_json.Service();
            insult.service.name = insult.name;
            insult.service.Widgets = insult.widgets;

            coffee.service = new About_json.Service();
            coffee.service.name = coffee.name;
            coffee.service.Widgets = coffee.widgets;

            weather.service = new About_json.Service();
            weather.service.name = weather.name;
            weather.service.Widgets = weather.widgets;

            rootobject.Server.Services.Add(spotify.service);
            rootobject.Server.Services.Add(quote.service);
            rootobject.Server.Services.Add(meme.service);
            rootobject.Server.Services.Add(duck.service);
            rootobject.Server.Services.Add(dog.service);
            rootobject.Server.Services.Add(insult.service);
            rootobject.Server.Services.Add(coffee.service);
            rootobject.Server.Services.Add(weather.service);

            about = JsonConvert.SerializeObject(rootobject, Formatting.Indented);

            System.IO.File.WriteAllText("wwwroot/about_data.json", about);

            return (about);
        }

        static private About_json.Widget create_widget(string name, string description, List<About_json.Param> parameters)
        {
            About_json.Widget widget = new About_json.Widget();

            widget.name = name;
            widget.Description = description;
            widget.Params = parameters;

            return (widget);
        }

        static private About_json.Param create_parameters(string name, string type)
        {
            About_json.Param parameters = new About_json.Param();

            parameters.name = name;
            parameters.type = type;

            return (parameters);
        }
    }
}
