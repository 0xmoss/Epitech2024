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

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class WeatherModel : PageModel
    {
        class Settings
        {
            public string host = "http://api.weatherstack.com";
            public string key = "478b7656452e041d00775d8fde73a980";
            // review_key = "f7146d0bf27385a97a3c22481f3acd85";
            public string city = "Lyon";
            public string unit = "m";
            public bool launch = true;
        }

        public class Weather
        {
            public WeatherForecast.Root weatherForecast = new WeatherForecast.Root();
        }

        Settings settings = new Settings();
        static Authentification authentification = new Authentification("weather");
        Requests requests = new Requests(authentification);
        Html html = new Html();
        Weather content = new Weather();
        Cache cache = new Cache();
        public ClockBuilder clockBuilder = new ClockBuilder("weather");

        public async Task<Task> start()
        {
            settings.launch = true;

            await search();

            Task.Run(() => load_all());

            return (Task.CompletedTask);
        }

        public async Task<Task> stop()
        {
            settings.launch = false;

            return (Task.CompletedTask);
        }

        public async Task<Task> load_all()
        {
            while (settings.launch == true) {
                if (clockBuilder.settings.refresh == true) {
                    await search();
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<Task> search()
        {
            string check = await cache.get("weathermodel");
            Dictionary<string, string> informations = null;

            if (check != null) {
                settings.key = check;
            }
            informations = await requests.create(
                $"{settings.host}/forecast?access_key={settings.key}&query={settings.city}&unit={settings.unit}",
                null,
                null,
                null
            );
            content.weatherForecast = JsonConvert.DeserializeObject<WeatherForecast.Root>(
                await requests.get(informations)
            );

            return (Task.CompletedTask);
        }

        public async Task<Task> city(string city_name)
        {
            if (city_name != null)
                settings.city = city_name;

            return (Task.CompletedTask);
        }

        public async Task<Task> key(string api_key)
        {
            if (api_key != null) {
                settings.key = api_key;
                await cache.add("weathermodel", api_key);
            }

            return (Task.CompletedTask);
        }

        // GET DATA
        public async Task<int> current_temperature()
        {
            if (content.weatherForecast != null)
                if (content.weatherForecast.current != null)
                    return (content.weatherForecast.current.temperature);
            return (0);
        }

        public async Task<int> current_wind_speed()
        {
            if (content.weatherForecast != null)
                if (content.weatherForecast.current != null)
                    return (content.weatherForecast.current.wind_speed);
            return (0);
        }

        public async Task<int> current_humidity()
        {
            if (content.weatherForecast != null)
                if (content.weatherForecast.current != null)
                    return (content.weatherForecast.current.humidity);
            return (0);
        }

        public async Task<string> location_name()
        {
            if (content.weatherForecast != null)
                if (content.weatherForecast.current != null)
                    return (content.weatherForecast.location.name);
            return (null);
        }

        public async Task<string> location_country()
        {
            if (content.weatherForecast != null)
                if (content.weatherForecast.current != null)
                    return (content.weatherForecast.location.country);
            return (null);
        }

        public async Task<string> location_region()
        {
            if (content.weatherForecast != null)
                if (content.weatherForecast.current != null)
                    return (content.weatherForecast.location.region);
            return (null);
        }

        public async Task<string> location_latitude()
        {
            if (content.weatherForecast != null)
                if (content.weatherForecast.current != null)
                    return (content.weatherForecast.location.lat);
            return (null);
        }

        public async Task<string> location_longitude()
        {
            if (content.weatherForecast != null)
                if (content.weatherForecast.current != null)
                    return (content.weatherForecast.location.lon);
            return (null);
        }
    }
}
