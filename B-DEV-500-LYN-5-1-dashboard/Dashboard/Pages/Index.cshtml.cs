using System;
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
    public class IndexModel : PageModel
    {
        Database db = new Database();
        private readonly ILogger<IndexModel> _logger;


        public IndexModel(ILogger<IndexModel> logger)
        {
            _logger = logger;
        }
        
        public async Task InitPanel()
        {
            if (GlobalModels.panelModel == null)
            {
                GlobalModels.panelModel = new PanelModel();
            }
        }

        public async Task InitDuck()
        {
            await InitPanel();

            if (GlobalModels.panelModel != null)
                await GlobalModels.panelModel.start_duck();
        }
        public async Task InitDog()
        {
            await InitPanel();

            if (GlobalModels.panelModel != null)
                await GlobalModels.panelModel.start_dog();
        }
        public async Task InitCat()
        {
            await InitPanel();

            if (GlobalModels.panelModel != null)
                await GlobalModels.panelModel.start_cat();
        }

        public async Task InitInsult()
        {
            await InitPanel();

            if (GlobalModels.panelModel != null)
                await GlobalModels.panelModel.start_insult();
        }

        public async Task InitMeme()
        {
            await InitPanel();

            if (GlobalModels.panelModel != null)
                await GlobalModels.panelModel.start_meme();
        }

        public async Task InitMeow()
        {
            await InitPanel();

            if (GlobalModels.panelModel != null)
                await GlobalModels.panelModel.start_meow();
        }

        public async Task InitQuote()
        {
            await InitPanel();

            if (GlobalModels.panelModel != null)
                await GlobalModels.panelModel.start_quote();
        }

        public async Task InitNumber()
        {
            await InitPanel();

            if (GlobalModels.panelModel != null)
                await GlobalModels.panelModel.start_number();
        }

        public async Task InitSpotify()
        {
            if (GlobalModels.spotifyModel == null)
                GlobalModels.spotifyModel = new SpotifyModel();
        }

        public async Task InitCoffee()
        {
            if (GlobalModels.coffeeModel == null)
            {
                GlobalModels.coffeeModel = new CoffeeModel();

                await GlobalModels.coffeeModel.start();
                await GlobalModels.coffeeModel.key(null);
                await GlobalModels.coffeeModel.get_subscriptions();
                await GlobalModels.coffeeModel.get_supporters();
                await GlobalModels.coffeeModel.get_extras();
            }
        }
        
        public async Task InitWeather()
        {
            if (GlobalModels.weatherModel == null)
            {
                GlobalModels.weatherModel = new WeatherModel();

                await GlobalModels.weatherModel.start();
                await GlobalModels.weatherModel.key(null);
                await GlobalModels.weatherModel.city(null);
                await GlobalModels.weatherModel.search();
            }
        }

        public async Task<bool> SpotifyIsConnected()
        {
            if (GlobalModels.spotifyModel != null)
            {
                return await GlobalModels.spotifyModel.is_logged();
            }
            return false;
        }

        public ActionResult OnPostSetDuckSettings(int reloadRate)
        {
            GlobalModels.panelModel.duckModel.stop();

            ClockBuilder clock = new ClockBuilder(null);
            clock.edit("duck", reloadRate).Wait();

            return Redirect("/");
        }

        public ActionResult OnPostSetDogSettings(int reloadRate)
        {
            GlobalModels.panelModel.dogModel.stop();

            ClockBuilder clock = new ClockBuilder(null);
            clock.edit("dog", reloadRate).Wait();

            return Redirect("/");
        }

        public ActionResult OnPostSetMemeSettings(int reloadRate)
        {
            GlobalModels.panelModel.memeModel.stop();

            ClockBuilder clock = new ClockBuilder(null);
            clock.edit("meme", reloadRate).Wait();

            return Redirect("/");
        }

        public ActionResult OnPostSetCatSettings(int reloadRate, string key)
        {
            if (reloadRate != 0) {
                GlobalModels.panelModel.catModel.stop();

                ClockBuilder clock = new ClockBuilder(null);
                clock.edit("cat", reloadRate).Wait();
            }

            if (key != null) {
                GlobalModels.panelModel.catModel.key(key);
            }

            return Redirect("/");
        }

        public ActionResult OnPostSetMeowSettings(int reloadRate)
        {
            if (reloadRate != 0) {
                GlobalModels.panelModel.meowModel.stop();

                ClockBuilder clock = new ClockBuilder(null);
                clock.edit("meow", reloadRate).Wait();
            }

            return Redirect("/");
        }

        public ActionResult OnPostSetNumberSettings(int reloadRate)
        {
            if (reloadRate != 0) {
                GlobalModels.panelModel.numberModel.stop();

                ClockBuilder clock = new ClockBuilder(null);
                clock.edit("number", reloadRate).Wait();
            }

            return Redirect("/");
        }

        public ActionResult OnPostSetQuoteSettings(int reloadRate)
        {
            if (reloadRate != 0) {
                GlobalModels.panelModel.quoteModel.stop();

                ClockBuilder clock = new ClockBuilder(null);
                clock.edit("quote", reloadRate).Wait();
            }

            return Redirect("/");
        }

        public ActionResult OnPostSetInsultSettings(int reloadRate)
        {
            if (reloadRate != 0) {
                GlobalModels.panelModel.insultModel.stop();

                ClockBuilder clock = new ClockBuilder(null);
                clock.edit("insult", reloadRate).Wait();
            }

            return Redirect("/");
        }

        public ActionResult OnPostSetCoffeeSettings(int reloadRate, string key)
        {
            if (reloadRate != 0) {
                GlobalModels.coffeeModel.stop();

                ClockBuilder clock = new ClockBuilder(null);
                clock.edit("coffee", reloadRate).Wait();
            }

            if (key != null) {
                GlobalModels.coffeeModel.key(key);
            }

            return Redirect("/");
        }

        public async Task OnPostSpotifyConnect()
        {
            Console.WriteLine("OnPostSpotifyConnect()");

            if (GlobalModels.spotifyModel != null)
            {
                string state = await GlobalModels.spotifyModel.call_login();
                Globals.SpotifySearchResultsPlaylist = await GlobalModels.spotifyModel.search_playlist(); // Fetch user playlists at login time

                this.HttpContext.Response.Redirect(state);
            }
        }

        public async Task OnPostSpotifyLogout()
        {
            Console.WriteLine("OnPostSpotifyLogout()");

            if (GlobalModels.spotifyModel != null)
            {
                await GlobalModels.spotifyModel.logout();
            }
        }

        public async Task OnPostSpotifySearch(string search)
        {
            Console.WriteLine("OnPostSpotifySearch() ");

            if (GlobalModels.spotifyModel != null)
            {
                Globals.SpotifySearchResultsAlbum = await GlobalModels.spotifyModel.search_album(search);
                Globals.SpotifySearchResultsArtist = await GlobalModels.spotifyModel.search_artist(search);
                Globals.SpotifySearchResultsTrack = await GlobalModels.spotifyModel.search_track(search);
                Globals.SpotifySearchResultsTop = await GlobalModels.spotifyModel.search_top(search);
            }
        }

        public async Task OnPostLogout()
        {
            await db.logoutUser();

            this.HttpContext.Response.Redirect("/");
        }

        public async Task OnPostLogin(string username, string password)
        {
            bool status = await db.loginUser(username, password);
            if (status == false)
            {
                Globals.LastLoginError = "Password does not match username.";
                return;
            }

            Globals.LastLoginError = null;
            //this.HttpContext.Response.Redirect("/");
        }

        public async Task OnPostRegister(string username, string password, string confirm)
        {
            if (username != null)
            {
                if (username.Length < 3)
                {
                    Globals.LastRegisterError = "Your username needs to be at least 3 characters long.";
                    return;
                }
            }
            else
            {
                Globals.LastRegisterError = "You need to type a username.";
                return;
            }

            if (password != null)
            {
                if (password.Length < 6)
                {
                    Globals.LastRegisterError = "Your password needs to be at least 6 characters long.";
                    return;
                }
            }
            else
            {
                Globals.LastRegisterError = "You need to type a password.";
                return;
            }

            if (password != confirm)
            {
                Globals.LastRegisterError = "Passwords doesn't match.";
                return;
            }

            bool status = await db.regiserUser(username, password);
            if (status == false)
            {
                Globals.LastRegisterError = "Username already exists.";
                return;
            }

            status = await db.loginUser(username, password);
            if (status == false)
            {
                Globals.LastRegisterError = "Unknown error while trying to login.";
                return;
            }

            Globals.LastRegisterError = null;
            this.HttpContext.Response.Redirect("/");
        }

        [BindProperty]
        public string WidgetName { get; set; }
        public string[] Widgets = new[] { "Duck", "Meme", "Dog", "Cat", "Meow", "Number", "Coffee", "Quote", "Insult", "Spotify", "Weather" };
        public ActionResult OnPostAddWidget()
        {
            if (WidgetName.Equals("Duck")) {
                Console.WriteLine("Selected Duck!");
                InitDuck();
                Globals.CurrentWidgets.Add("Duck");
            } else if (WidgetName.Equals("Meme")) {
                Console.WriteLine("Selected Meme!");
                InitMeme();
                Globals.CurrentWidgets.Add("Meme");
            } else if (WidgetName.Equals("Dog")) {
                Console.WriteLine("Selected Dog!");
                InitDog();
                Globals.CurrentWidgets.Add("Dog");
            } else if (WidgetName.Equals("Cat")) {
                Console.WriteLine("Selected Cat!");
                InitCat();
                Globals.CurrentWidgets.Add("Cat");
            } else if (WidgetName.Equals("Meow")) {
                Console.WriteLine("Selected Meow!");
                InitMeow();
                Globals.CurrentWidgets.Add("Meow");
            } else if (WidgetName.Equals("Number")) {
                Console.WriteLine("Selected Number!");
                InitNumber();
                Globals.CurrentWidgets.Add("Number");
            } else if (WidgetName.Equals("Coffee")) {
                Console.WriteLine("Selected Coffee!");
                InitCoffee();
                Globals.CurrentWidgets.Add("Coffee");
            } else if (WidgetName.Equals("Quote")) {
                Console.WriteLine("Selected Quote!");
                InitQuote();
                Globals.CurrentWidgets.Add("Quote");
            } else if (WidgetName.Equals("Insult")) {
                Console.WriteLine("Selected Insult!");
                InitInsult();
                Globals.CurrentWidgets.Add("Insult");
            } else if (WidgetName.Equals("Spotify")) {
                Console.WriteLine("Selected Spotify!");
                InitSpotify();
                Globals.CurrentWidgets.Add("Spotify");
            } else if (WidgetName.Equals("Weather")) {
                Console.WriteLine("Selected Weather!");
                InitWeather();
                Globals.CurrentWidgets.Add("Weather");
            }

            return Redirect("/");
        }

        public ActionResult OnPostRemoveWidget(string selection)
        {
            Console.WriteLine($"removing: {selection}");

            if (selection.Equals("Duck")) {
                Globals.CurrentWidgets.Remove("Duck");
                GlobalModels.panelModel.stop_duck();
                GlobalModels.panelModel.clean_duck();
            } else if (selection.Equals("Meme")) {
                Globals.CurrentWidgets.Remove("Meme");
                GlobalModels.panelModel.stop_meme();
                GlobalModels.panelModel.clean_meme();
            } else if (selection.Equals("Dog")) {
                Globals.CurrentWidgets.Remove("Dog");
                GlobalModels.panelModel.stop_dog();
                GlobalModels.panelModel.clean_dog();
            } else if (selection.Equals("Cat")) {
                Globals.CurrentWidgets.Remove("Cat");
                GlobalModels.panelModel.stop_cat();
                GlobalModels.panelModel.clean_cat();
            } else if (selection.Equals("Meow")) {
                Globals.CurrentWidgets.Remove("Meow");
                GlobalModels.panelModel.stop_meow();
                GlobalModels.panelModel.clean_meow();
            } else if (selection.Equals("Number")) {
                Globals.CurrentWidgets.Remove("Number");
                GlobalModels.panelModel.stop_number();
                GlobalModels.panelModel.clean_number();
            } else if (selection.Equals("Coffee")) {
                Globals.CurrentWidgets.Remove("Coffee");
                GlobalModels.coffeeModel = null;
            } else if (selection.Equals("Quote")) {
                Globals.CurrentWidgets.Remove("Quote");
                GlobalModels.panelModel.stop_quote();
                GlobalModels.panelModel.clean_quote();
            } else if (selection.Equals("Insult")) {
                Globals.CurrentWidgets.Remove("Insult");
                GlobalModels.panelModel.stop_insult();
                GlobalModels.panelModel.clean_insult();
            } else if (selection.Equals("Spotify")) {
                Globals.CurrentWidgets.Remove("Spotify");
                GlobalModels.spotifyModel = null;
            } else if (selection.Equals("Weather")) {
                Globals.CurrentWidgets.Remove("Weather");
                GlobalModels.weatherModel = null;
            }

            return Redirect("/");
        }

        public ActionResult OnPostCustomWidget(string selection)
        {
            Console.WriteLine(selection);

            if (selection.Equals("Duck")) {
                return Redirect("/#settingsDuck");
            } else if (selection.Equals("Meme")) {
                return Redirect("/#settingsMeme");
            } else if (selection.Equals("Dog")) {
                return Redirect("/#settingsDog");
            } else if (selection.Equals("Cat")) {
                return Redirect("/#settingsCat");
            } else if (selection.Equals("Meow")) {
                return Redirect("/#settingsMeow");
            } else if (selection.Equals("Number")) {
                return Redirect("/#settingsNumber");
            } else if (selection.Equals("Coffee")) {
                return Redirect("/#settingsCoffee");
            } else if (selection.Equals("Quote")) {
                return Redirect("/#settingsQuote");
            } else if (selection.Equals("Insult")) {
                return Redirect("/#settingsSpotify");
            } else if (selection.Equals("Spotify")) {
                return Redirect("/#settingsSpotify");
            }
            return Redirect("/");
        }

        public async Task OnPostRefreshWidget(string selection)
        {
            Console.WriteLine($"refeshing: {selection}");

            if (selection.ToLower().Equals("duck")) {
                await GlobalModels.panelModel.stop_duck();
                await GlobalModels.panelModel.clean_duck();
                await InitDuck();
            } else if (selection.ToLower().Equals("meme")) {
                await GlobalModels.panelModel.stop_meme();
                await GlobalModels.panelModel.clean_meme();
                await InitMeme();
            } else if (selection.ToLower().Equals("dog")) {
                await GlobalModels.panelModel.stop_dog();
                await GlobalModels.panelModel.clean_dog();
                await InitDog();
            } else if (selection.ToLower().Equals("cat")) {
                await GlobalModels.panelModel.stop_cat();
                await GlobalModels.panelModel.clean_cat();
                await InitCat();
            } else if (selection.ToLower().Equals("meow")) {
                await GlobalModels.panelModel.stop_meow();
                await GlobalModels.panelModel.clean_meow();
                await InitMeow();
            } else if (selection.ToLower().Equals("number")) {
                await GlobalModels.panelModel.stop_number();
                await GlobalModels.panelModel.clean_number();
                await InitNumber();
            } else if (selection.ToLower().Equals("coffee")) {
                GlobalModels.coffeeModel = null;
                await InitCoffee();
            } else if (selection.ToLower().Equals("quote")) {
                await GlobalModels.panelModel.stop_quote();
                await GlobalModels.panelModel.clean_quote();
                await InitQuote();
            } else if (selection.ToLower().Equals("insult")) {
                await GlobalModels.panelModel.stop_insult();
                await GlobalModels.panelModel.clean_insult();
                await InitInsult();
            } else if (selection.ToLower().Equals("spotify")) {
                GlobalModels.spotifyModel = null;
                await InitSpotify();
            }
        }
    }
}