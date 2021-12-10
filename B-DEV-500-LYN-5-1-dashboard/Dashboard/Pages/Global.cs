using System.Timers;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using SpotifyAPI.Web;
using Newtonsoft.Json;
using System;
using System.IO;
using System.Net.Http.Headers;
using Microsoft.AspNetCore.Http.Extensions;

namespace Dashboard.Pages
{
    public static class Globals
    {
        public enum EImageWidget {
            Meme = 1,
            Duck = 1,
            Dog = 1,
            Cat = 1,
        }

        public static API.User CurrentUser { get; set; }
        public static string LastLoginError { get; set; }
        public static string LastRegisterError { get; set; }

        public static EImageWidget imageWidget { get; set; }
        public static bool factsWidget { get; set; }
        public static bool quoteWidget { get; set; }
        public static bool insultWidget { get; set; }

        public static List<string> CurrentWidgets = new List<string>();
        public static Paging<SimpleAlbum> SpotifySearchResultsAlbum = null;
        public static SpotifyTrack.Root SpotifySearchResultsTrack = null;
        public static SpotifyArtist.Root SpotifySearchResultsArtist = null;
        public static SpotifyPlaylist.Root SpotifySearchResultsPlaylist = null;
        public static List<FullTrack> SpotifySearchResultsTop = null;
    }

    public class GlobalModels
    {
        public static SpotifyModel spotifyModel { get; set; }
        public static PanelModel panelModel { get; set; }
        public static CoffeeModel coffeeModel { get; set; }
        public static WeatherModel weatherModel { get; set; }
    }

    public class Clocks
    {
        SettingsWidgets.Root settingsWidgets = null;

        public Task load()
        {
            string path = "settings.json";
        
            if (File.Exists(path) == true) {
                settingsWidgets = JsonConvert.DeserializeObject<SettingsWidgets.Root>(
                    File.ReadAllText(path)
                );
            }

            return (Task.CompletedTask);
        }

        public int get(string widget)
        {
            if (settingsWidgets == null) {
                load().Wait();
            }

            foreach (SettingsWidgets.Clock clock in settingsWidgets.clocks) {
                if (clock.widget == widget)
                    return (clock.time);
            }

            return (120);
        }

        public Task set(string widget, int value)
        {
            if (settingsWidgets == null) {
                load().Wait();
            }

            foreach (SettingsWidgets.Clock clock in settingsWidgets.clocks) {
                if (clock.widget == widget) {
                    clock.time = value;
                }
            }

            save().Wait();

            return (Task.CompletedTask);
        }

        private Task save()
        {
            string path = "settings.json";
        
            if (File.Exists(path) == true)
                File.Delete(path);
            File.WriteAllText(path, JsonConvert.SerializeObject(settingsWidgets));

            return (Task.CompletedTask);
        }
    }

    public class ClockBuilder
    {
        public class Settings
        {
            public System.Timers.Timer timer = new System.Timers.Timer();
            public int starter = -1;
            public int limit = 0;
            public string widget = null;
            public bool refresh = true;
            public int current = 0;
        }

        public Settings settings = new Settings();
        Clocks clocks = new Clocks();

        public ClockBuilder(string widget)
        {
            if (widget != null) {
                settings.widget = widget;
                settings.limit = clocks.get(settings.widget);
            }
        }

        public async Task<Task> edit(string item, int value)
        {
            if (File.Exists("settings.json") == true) {
                clocks.set(item, value);
                clocks = new Clocks();
            } else {
                throw new Exception("widgets settings file not found");
            }

            return (Task.CompletedTask);
        }

        public async Task start()
        {
            Console.WriteLine($"Starting clock {settings.widget} for {settings.limit}s");
            settings.timer.Elapsed += new ElapsedEventHandler(OnTimedEvent);
            settings.timer.Interval = 1000;
            settings.timer.Enabled = true;
            settings.timer.AutoReset = true;
            settings.starter = -1;
            settings.refresh = false;
            settings.current = 0;

            settings.timer.Start();
        }

        private void OnTimedEvent(object source, ElapsedEventArgs e)
        {
            if (settings.starter < 0)
                settings.starter = e.SignalTime.Second;
            if (settings.current >= settings.limit) {
                Console.WriteLine($"It's time to refresh: {settings.widget}");
                settings.refresh = true;
                settings.current = 0;
                settings.timer.Stop();
            }
            settings.current++;
        }
    }
}