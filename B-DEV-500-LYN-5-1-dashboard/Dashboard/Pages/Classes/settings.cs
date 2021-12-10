using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class SettingsWidgets
    {
        public class Clock
        {
            public string widget { get; set; }
            public int time { get; set; }
        }

        public class Root
        {
            public List<Clock> clocks { get; set; }
        }
    }
}

