using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class Quote
    {
        public class Root
        {
            public string anime { get; set; }
            public string character { get; set; }
            public string quote { get; set; }
        }
    }
}
