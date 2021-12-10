using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Dashboard.Pages
{
    public class Html
    {
        public Html()
        {
        }

        public async Task<string> encode(string url)
        {
            Dictionary<string, string> values = new Dictionary<string, string>()
            {
                {" ", "%20"},
                {"!", "%21"},
                {"\"", "%22"},
                {"#", "%23"},
                {"$", "%24"},
                {"'", "%27"},
                {"(", "%28"},
                {")", "%29"},
                {"*", "%2A"},
                {"+", "%2B"},
                {",", "%2C"},
                {":", "%3A"},
                {";", "%3B"},
                {"<", "%3C"},
                {">", "%3E"},
                {"@", "%40"},
                {"https%3A//", "https://"},
                {"http%3A//", "http%3A%2F%2F"}
            };

            foreach (var item in values)
            {
                if (url.Contains(item.Key) == true) {
                    url = url.Replace(item.Key, item.Value);
                }
            }

            return (url);
        }
    }
}
