using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class Cat
    {
        public class Root
        {
            public List<object> breeds { get; set; }
            public string id { get; set; }
            public string url { get; set; }
            public int width { get; set; }
            public int height { get; set; }
        }
    }
}
