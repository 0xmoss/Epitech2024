
using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class Insult
    {
        public class Root
        {
            public string number { get; set; }
            public string language { get; set; }
            public string insult { get; set; }
            public string created { get; set; }
            public string shown { get; set; }
            public string createdby { get; set; }
            public string active { get; set; }
            public string comment { get; set; }
        }
    }
}


