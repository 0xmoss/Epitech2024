using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class Meme
    {
        public class Root
        {
            public string postLink { get; set; }
            public string subreddit { get; set; }
            public string title { get; set; }
            public string url { get; set; }
            public bool nsfw { get; set; }
            public bool spoiler { get; set; }
            public string author { get; set; }
            public int ups { get; set; }
            public List<string> preview { get; set; }
        }
    }
}
