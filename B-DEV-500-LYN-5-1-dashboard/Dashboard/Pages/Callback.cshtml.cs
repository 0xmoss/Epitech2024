using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;

namespace Dashboard.Pages
{
    public class CallbackModel : PageModel
    {
        public class spotify
        {
            public string code = null;
            public string state = null;
        }

        public string uri = null;
        public spotify auth = new spotify();

        public CallbackModel()
        {
        }

        private async Task<Task> dump(string type)
        {
            string cache = "cache";
            string[] files = null;

            if (Directory.Exists(cache) == false)
                Directory.CreateDirectory(cache);
            files = Directory.GetFiles(cache);

            foreach (string file in files) {
                if (file.Contains(type) == true)
                    System.IO.File.Delete(file);
            }

            System.IO.File.WriteAllText($"cache/{type}.{auth.state}", auth.code);

            return (Task.CompletedTask);
        }

        public async Task<string> spotify_token()
        {
            string[] splitted = uri.Split("code=");

            auth.code = splitted[1].Split("&state")[0];
            auth.state = splitted[1].Split("&state")[1].Replace("=", "");

            await dump("spotify");

            await GlobalModels.spotifyModel.call_login();

            return (null);
        }
    }
}
