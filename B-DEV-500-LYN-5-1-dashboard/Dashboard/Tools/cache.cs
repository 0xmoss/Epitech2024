using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class Cache
    {
        public class Settings
        {
            public CacheAPI.Root cache_data = new CacheAPI.Root();
            public string folder = "cache";
            public string path = "cache/api";
        }

        Settings settings = new Settings();

        public async Task<Task> load()
        {
            if (Directory.Exists(settings.folder) == true) {
                if (File.Exists(settings.path) == true) {
                    settings.cache_data = JsonConvert.DeserializeObject<CacheAPI.Root>(
                        File.ReadAllText(settings.path)
                    );
                } else {
                    Console.WriteLine("No api cache to load");
                }
            }

            return (Task.CompletedTask);
        }

        public async Task<Task> add(string api_name, string key)
        {
            CacheAPI.API api = new CacheAPI.API()
            {
                name = api_name,
                key = key
            };
            if (settings.cache_data.api == null) {
                settings.cache_data.api = new List<CacheAPI.API>();
            }
            settings.cache_data.api.Add(api);
            await dump();
            await load();

            return (Task.CompletedTask);
        }

        public async Task<string> get(string api_name)
        {
            await load();

            if (settings.cache_data.api != null) {
                foreach (CacheAPI.API item in settings.cache_data.api) {
                    if (item.name == api_name) {
                        return (item.key);
                    }
                }
            }

            return (null);
        }

        public async Task<Task> dump()
        {
            if (Directory.Exists(settings.folder) == false) {
                Directory.CreateDirectory(settings.folder);
            }
            if (File.Exists(settings.path) == true) {
                File.Delete(settings.path);
            }
            File.WriteAllText(
                settings.path,
                JsonConvert.SerializeObject(settings.cache_data)
            );

            return (Task.CompletedTask);
        }
    }
}
