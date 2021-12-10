using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using System.Net.Http.Headers;
using Microsoft.AspNetCore.Http.Extensions;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class CoffeeModel : PageModel
    {
        public class Settings
        {
            public string host = "https://developers.buymeacoffee.com/api/v1";
            public string key = "eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJhdWQiOiI5MTI5ZDIwMC1kYTdkLTRjY2MtOWQzZC01ODA0MTU0ZTgyMjYiLCJqdGkiOiIwZjViNmEyNzYwZmM4OWNjYmU5YTI0YjIwNGFhZTZjYzhmNDI0YjljY2U4ZWU2OTg0NzI5YmI1ODA4ZjZiN2U2MjY4NTQ0NWZiYjQxNjc2MyIsImlhdCI6MTYzNzIzOTEwOCwibmJmIjoxNjM3MjM5MTA4LCJleHAiOjE2NTI4Nzc1MDgsInN1YiI6IjE2NDkzODMiLCJzY29wZXMiOltdfQ.Dt8ZD8QVaRhifAY3iCOfN0i7FXjL-1Sk4VXOiRC1rPrG6KVTTfnx4xLFeVdEYtM-RzEorW_52cRVXYuxG-9ZXOzjWlAfspTJOa0-_Ad1CIT3UDb9l9qUpaKkE6cXBZBzxiAwqDPOForLaY54yyH5roy_yVrVUVR0EEPJtypEXlA0P5jiWT6EL_rZ1HVL1SbZqnA5YJ1F7mqGswzVYsA9OrPfEXJw4wu1utKa-faSRYyTLho5DBr567agb8VWJu2qgSccjnoc8N9rBg78UjLB-j0j7Ttrp5fNv0jIlYYTalGCCn3GJUYIP2wOS6SlnKeViEmEX3FUsvwZdOz1IkjmeRDdS4ePeTTxid545iyyRm4BlnVVkDDEkU3BnM5BtmyqZw9-SDhGo7osADqajmKJI5EcPRGgbSh3KXJ2ITSKFVCct6-6rbprfMaVdJZPiEnGm7P5firyR1se3wpPU1v5jXLGW2sQ-rR2G104o3PZg2aIbMFJTXoNLNeoRQ53qfnsMUk87oWPn6uPCk3ZKZOVtbGmjc-R_oGSshpK6NPH2yv03S_GAng18QzX4Gm-rCrBNacGNqojbKjOW3YkewTmudDU7eCTzyVcbwEl5LqqJgVMIOjdIkBjYXen6ZCMjutN1kdigpw7Q6hZPAtqk2LkdEukh13Q1mrkmUzKd1ZScJU";
            //"eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJhdWQiOiI5MTI5ZDIwMC1kYTdkLTRjY2MtOWQzZC01ODA0MTU0ZTgyMjYiLCJqdGkiOiJiY2U4ZWI3MWU5YzExMWFjZGU4YmYyM2I4Y2FlMmM0ZWI1YzA1NmQ0YzgxOTU1MDc5ODljNzFmN2I0MmExMmRhN2JlN2JlYzZjYjJjZGQ2YiIsImlhdCI6MTYzODUyNjYwOCwibmJmIjoxNjM4NTI2NjA4LCJleHAiOjE2NTQyNTE0MDcsInN1YiI6IjE2OTUyMDgiLCJzY29wZXMiOlsicmVhZC1vbmx5Il19.MBT6FZbYZSIyGXLUntq-C7SNNaZhY-RCk8FSF3W6TdiYXyvtvDsJPQrfAAShcqKoCO9BSnbWZz9LTBho50TrGotJTY9TcunFV5B7BJSN-EOUuoc5-yVvl2yfZ7iyeC3DHdYbDo6kh5tSGYrIb04xmW64vIdfzDM_aE-UYq7XfQqzRShhoqqsbinQWyY3-tN5WuB8US92Re7Dpaz_YjgrZMfTrhnD_Eee-wejiVKC0f5NqcvZsDqeKyki1pRQf-ARFGloCJuxZ8ToED4qkJ7GyUWonFE2y1ihlKcJAOnxIcXjbHnixBRp0K2lQnKCvJx7R848JYDwjfK4Ihu6RcRfAmDZZJW1IY-C-nSySKXUjxSzFTceC29bSM6hGTpv2XRsYj8jx9YyWtY5otdaFvOe6rT6OTTqgbehSrNTNusZI-t42JzILOGcvj37UuaAwQZLiDR8rxFMd2f-Kabo61Yjz9zxNFEyJMTZ80yIqin08b5X_icFazPhc9k0J2UlNfIkdzbnOWYXz_WoqcqqIvxBxjkQXjmB-6hDlbHCtA82tJxh0kh_Gnf8vKSekXHhnPiy6lkF_KbHKnUKz615hgKOa41vfD6-VBTG8cQINKNw4g_R45uh9grbANVp6qElQ_EXWooHwka7pykcgCA8Vgix6JzSX_6iN857Ag2TeIAEr8s";
            public bool launch = true;
        }

        public class Coffee
        {
            public CoffeeSubscriptions.Root subscriptions = null;
            public CoffeeSupporters.Root supporters = null;
            public CoffeeExtras.Root extras = null;
            public bool subscriptions_s = false;
            public bool supporters_s = false;
            public bool extras_s = false;
        }

        public Settings settings = new Settings();
        static Authentification authentification = new Authentification("buy me a coffee");
        Requests requests = new Requests(authentification);
        Html html = new Html();
        Password password = new Password();
        Coffee coffee = new Coffee();
        Cache cache = new Cache();
        public ClockBuilder clockBuilder = new ClockBuilder("coffee");

        public async Task<Task> start()
        {
            settings.launch = true;

            await subscriptions();
            await supporters();
            await extras();

            Task.Run(() => load_all());

            return (Task.CompletedTask);
        }

        public async Task<Task> stop()
        {
            settings.launch = false;

            return (Task.CompletedTask);
        }

        public async Task<Task> load_all()
        {
            while (settings.launch == true) {
                if (clockBuilder.settings.refresh == true) {
                    await subscriptions();
                    await supporters();
                    await extras();
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<Task> subscriptions()
        {
            string check = await cache.get("coffeemodel");
            Dictionary<string, string> headers = null;
            Dictionary<string, string> informations = null;
            
            if (check != null) {
                settings.key = check;
            }
            headers = new Dictionary<string, string>()
            {
                {"Authorization", $"Bearer {settings.key}"}
            };
            informations = await requests.create(
                $"{settings.host}/subscriptions",
                headers,
                null,
                null
            );

            coffee.subscriptions = JsonConvert.DeserializeObject<CoffeeSubscriptions.Root>(
                await requests.get(informations)
            );
            if (coffee.subscriptions.data != null)
                coffee.subscriptions_s = true;
            else
                coffee.subscriptions_s = false;

            return (Task.CompletedTask);
        }

        public async Task<Task> supporters()
        {
            string check = await cache.get("coffeemodel");
            Dictionary<string, string> headers = null;
            Dictionary<string, string> informations = null;
            
            if (check != null) {
                settings.key = check;
            }
            headers = new Dictionary<string, string>()
            {
                {"Authorization", $"Bearer {settings.key}"}
            };            
            informations = await requests.create(
                $"{settings.host}/supporters",
                headers,
                null,
                null
            );

            coffee.supporters = JsonConvert.DeserializeObject<CoffeeSupporters.Root>(
                await requests.get(informations)
            );

            if (coffee.supporters.data != null)
                coffee.supporters_s = true;
            else
                coffee.supporters_s = false;

            return (Task.CompletedTask);
        }

        public async Task<Task> extras()
        {
            string check = await cache.get("coffeemodel");
            Dictionary<string, string> headers = null;
            Dictionary<string, string> informations = null;
            
            if (check != null) {
                settings.key = check;
            }
            headers = new Dictionary<string, string>()
            {
                {"Authorization", $"Bearer {settings.key}"}
            };            
            informations = await requests.create(
                $"{settings.host}/extras",
                headers,
                null,
                null
            );

            coffee.extras = JsonConvert.DeserializeObject<CoffeeExtras.Root>(
                await requests.get(informations)
            );
            if (coffee.extras.data != null)
                coffee.extras_s = true;
            else
                coffee.extras_s = false;

            return (Task.CompletedTask);
        }

        public async Task<bool> state_subscriptions()
        {
            return (coffee.subscriptions_s);
        }

        public async Task<bool> state_supporters()
        {
            return (coffee.supporters_s);
        }

        public async Task<bool> state_extras()
        {
            return (coffee.extras_s);
        }

        public async Task<Task> key(string api_key)
        {
            if (api_key != null) {
                settings.key = api_key;
                await cache.add("coffeemodel", api_key);
            }

            return (Task.CompletedTask);
        }

        public async Task<int> get_subscriptions()
        {
            return (coffee.subscriptions.total);
        }

        public async Task<int> get_supporters()
        {
            return (coffee.supporters.total);
        }

        public async Task<int> get_extras()
        {
            return (coffee.extras.total);
        }
    }
}
