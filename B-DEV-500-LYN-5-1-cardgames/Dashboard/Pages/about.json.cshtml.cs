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

        public class Spotify
        {
            public string name = "spotify";

            public About_json.Service service = new About_json.Service();

            public List<About_json.Widget> widgets = new List<About_json.Widget>()
            {
                search
            };

            // WIDGETS
                // SEARCH
                static public List<About_json.Param> search_parameters = new List<About_json.Param>()
                {
                    p_artist_music
                };
                static public About_json.Param p_artist_music = create_parameters("artist name / music", "string");
                static public About_json.Widget search = create_widget("search", "search for artist and music in spotify", search_parameters);
        }

        About_json.Root rootobject = new About_json.Root();
        Spotify spotify = new Spotify();
        public string host = null;

        public async Task<Task> load()
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

            rootobject.Server.Services.Add(spotify.service);

            about = JsonConvert.SerializeObject(rootobject, Formatting.Indented);
            Console.WriteLine(about);
            if (System.IO.File.Exists(output) == true)
                System.IO.File.Delete(output);
            System.IO.File.WriteAllText(output, about);

            return (Task.CompletedTask);
        }

        static private About_json.Widget create_widget(string name, string description, List<About_json.Param> parameters)
        {
            About_json.Widget widget = new About_json.Widget();

            widget.name = name;
            widget.Description = description;
            Console.WriteLine(parameters.Count);
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
