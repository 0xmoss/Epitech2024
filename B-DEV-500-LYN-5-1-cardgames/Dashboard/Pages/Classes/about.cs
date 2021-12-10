using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class About_json
    {
        public class Client
        {
            public string host { get; set; }
        }

        public class Param
        {
            public string name { get; set; }
            public string type { get; set; }
        }

        public class Widget
        {
            public string name { get; set; }

            [JsonProperty("description")]
            public string Description { get; set; }

            [JsonProperty("params")]
            public List<Param> Params { get; set; }
        }

        public class Service
        {
            public string name { get; set; }

            [JsonProperty("widgets")]
            public List<Widget> Widgets { get; set; }
        }

        public class Server
        {
            [JsonProperty("current_time")]
            public long CurrentTime { get; set; }

            [JsonProperty("services ")]
            public List<Service> Services { get; set; }
        }

        public class Root
        {
            [JsonProperty("client")]
            public Client Client { get; set; }

            [JsonProperty("server")]
            public Server Server { get; set; }
        }
    }
}
