using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class CacheAPI
    {
        public class API
        {
            public string name { get; set; }
            public string key { get; set; }
        }

        public class Root
        {
            public List<API> api { get; set; }
        }
    }
}
