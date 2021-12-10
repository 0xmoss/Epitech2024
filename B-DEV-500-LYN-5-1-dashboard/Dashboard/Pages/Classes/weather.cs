using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class WeatherForecast
    {
        public class Request
        {
            public string type { get; set; }
            public string query { get; set; }
            public string language { get; set; }
            public string unit { get; set; }
        }

        public class Location
        {
            public string name { get; set; }
            public string country { get; set; }
            public string region { get; set; }
            public string lat { get; set; }
            public string lon { get; set; }
            public string timezone_id { get; set; }
            public string localtime { get; set; }
            public int localtime_epoch { get; set; }
            public string utc_offset { get; set; }
        }

        public class Current
        {
            public string observation_time { get; set; }
            public int temperature { get; set; }
            public int weather_code { get; set; }
            public List<string> weather_icons { get; set; }
            public List<string> weather_descriptions { get; set; }
            public int wind_speed { get; set; }
            public int wind_degree { get; set; }
            public string wind_dir { get; set; }
            public int pressure { get; set; }
            public int precip { get; set; }
            public int humidity { get; set; }
            public int cloudcover { get; set; }
            public int feelslike { get; set; }
            public int uv_index { get; set; }
            public int visibility { get; set; }
            public string is_day { get; set; }
        }

        public class Astro
        {
            public string sunrise { get; set; }
            public string sunset { get; set; }
            public string moonrise { get; set; }
            public string moonset { get; set; }
            public string moon_phase { get; set; }
            public int moon_illumination { get; set; }
        }

        public class _20211120
        {
            public string date { get; set; }
            public int date_epoch { get; set; }
            public Astro astro { get; set; }
            public int mintemp { get; set; }
            public int maxtemp { get; set; }
            public int avgtemp { get; set; }
            public int totalsnow { get; set; }
            public double sunhour { get; set; }
            public int uv_index { get; set; }
        }

        public class Forecast
        {
            [JsonProperty("2021-11-20")]
            public _20211120 _20211120 { get; set; }
        }

        public class Root
        {
            public Request request { get; set; }
            public Location location { get; set; }
            public Current current { get; set; }
            public Forecast forecast { get; set; }
        }
    }
}
