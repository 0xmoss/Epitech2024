using System;
using System.Collections.Generic;
using System.Linq;
using System.Timers;
using System.Threading.Tasks;
using System.Threading;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;

using YandexTranslateCSharpSdk;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class MemeModel
    {
        public class Settings
        {
            public string host = "https://meme-api.herokuapp.com/gimme";
            public Meme.Root meme = new Meme.Root();
            static public Authentification authentification = new Authentification("meme");
            public Requests requests = new Requests(authentification);
            public bool launch = true;
        }

        public Settings settings = new Settings();
        public ClockBuilder clockBuilder = new ClockBuilder("meme");

        public async Task<Task> start()
        {
            settings.launch = true;

            await get();

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
                    await get();
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<Meme.Root> get()
        {
            Dictionary<string, string> data = await settings.requests.create(
                settings.host,
                null,
                null,
                null
            );
            string result = await settings.requests.get(data);

            settings.meme = JsonConvert.DeserializeObject<Meme.Root>(result);

            return (settings.meme);
        }

        public async Task<string> author()
        {
            return (settings.meme.author);
        }

        public async Task<string> link()
        {
            return (settings.meme.postLink);
        }

        public async Task<string> reddit()
        {
            return (settings.meme.subreddit);
        }

        public async Task<string> title()
        {
            return (settings.meme.title);
        }

        public async Task<string> url()
        {
            return (settings.meme.url);
        }

        public async Task<bool> nsfw()
        {
            return (settings.meme.nsfw);
        }

        public async Task<int> ups()
        {
            return (settings.meme.ups);
        }
    }

    public class QuoteModel
    {
        public class Settings
        {
            public string host = "https://animechan.vercel.app/api/random";
            public Quote.Root quote = new Quote.Root();
            static public Authentification authentification = new Authentification("quote");
            public Requests requests = new Requests(authentification);
            public bool launch = true;
        }

        public Settings settings = new Settings();
        public ClockBuilder clockBuilder = new ClockBuilder("quote");

        public async Task<Task> start()
        {
            settings.launch = true;

            await get();

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
                    await get();
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<Quote.Root> get()
        {
            Dictionary<string, string> data = await settings.requests.create(
                settings.host,
                null,
                null,
                null
            );
            string result = await settings.requests.get(data);

            settings.quote = JsonConvert.DeserializeObject<Quote.Root>(result);

            return (settings.quote);
        }

        public async Task<string> character()
        {
            return (settings.quote.character);
        }

        public async Task<string> anime()
        {
            return (settings.quote.anime);
        }

        public async Task<string> quote()
        {
            return (settings.quote.quote);
        }
    }

    public class NumberModel
    {
        public class Settings
        {
            public string number = "http://numbersapi.com/#";
            public string math = "http://numbersapi.com/#/math";
            public string date = "http://numbersapi.com/#/date";
            public string year = "http://numbersapi.com/#/year";
            public string trivia = "http://numbersapi.com/#/trivia";
            public int limit = 1000;
            public bool launch = true;
            public Number.Root numberRoot = new Number.Root();
            static public Authentification authentification = new Authentification("number");
            public Requests requests = new Requests(authentification);
        }

        public Settings settings = new Settings();
        Random random = new Random();
        public ClockBuilder clockBuilder = new ClockBuilder("number");

        public async Task<Task> start()
        {
            settings.launch = true;

            await get_number(null);
            await get_date(null);
            await get_math(null);
            await get_trivia(null);
            await get_year(null);

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
                    await get_number(null);
                    await get_date(null);
                    await get_math(null);
                    await get_trivia(null);
                    await get_year(null);
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<string> get_number(string number)
        {
            Dictionary<string, string> data = null;
            string result = null;

            if (number == null)
                number = $"{random.Next(0, settings.limit)}";
    
            data = await settings.requests.create(
                settings.number.Replace("#", number),
                null,
                null,
                null
            );
            settings.numberRoot.number = await settings.requests.get(data);

            return (settings.numberRoot.number);
        }

        public async Task<string> get_math(string number)
        {
            Dictionary<string, string> data = null;
            string result = null;

            if (number == null)
                number = $"{random.Next(0, settings.limit)}";
    
            data = await settings.requests.create(
                settings.math.Replace("#", number),
                null,
                null,
                null
            );
            settings.numberRoot.math = await settings.requests.get(data);

            return (settings.numberRoot.math );
        }

        public async Task<string> get_date(string number)
        {
            Dictionary<string, string> data = null;
            string result = null;

            if (number == null)
                number = $"{random.Next(1, 12)}/{random.Next(1, 28)}";
    
            data = await settings.requests.create(
                settings.date.Replace("#", number),
                null,
                null,
                null
            );
            settings.numberRoot.date = await settings.requests.get(data);

            return (settings.numberRoot.date);
        }

        public async Task<string> get_year(string number)
        {
            Dictionary<string, string> data = null;
            string result = null;

            if (number == null)
                number = $"{random.Next(0, 2021)}";
    
            data = await settings.requests.create(
                settings.year.Replace("#", number),
                null,
                null,
                null
            );
            settings.numberRoot.year = await settings.requests.get(data);

            return (settings.numberRoot.year);
        }
        
        public async Task<string> get_trivia(string number)
        {
            Dictionary<string, string> data = null;
            string result = null;

            if (number == null)
                number = $"{random.Next(0, settings.limit)}";
    
            data = await settings.requests.create(
                settings.trivia.Replace("#", number),
                null,
                null,
                null
            );
            settings.numberRoot.trivia = await settings.requests.get(data);

            return (settings.numberRoot.trivia);
        }
    }

    public class InsultModel
    {
        public class Settings
        {
            public string host = "https://evilinsult.com/generate_insult.php?lang=en&type=json";
            public bool launch = true;
            public Insult.Root insult = new Insult.Root();
            static public Authentification authentification = new Authentification("insult");
            public Requests requests = new Requests(authentification);
        }

        public Settings settings = new Settings();
        public ClockBuilder clockBuilder = new ClockBuilder("insult");

        public async Task<Task> start()
        {
            settings.launch = true;

            await get();

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
                    await get();
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<Insult.Root> get()
        {
            Dictionary<string, string> data = await settings.requests.create(
                settings.host,
                null,
                null,
                null
            );
            string result = await settings.requests.get(data);

            settings.insult = JsonConvert.DeserializeObject<Insult.Root>(result);

            return (settings.insult);
        }

        public async Task<string> insult()
        {
            return (settings.insult.insult);
        }

        public async Task<string> createdby()
        {
            return (settings.insult.createdby);
        }
    }

    public class MeowModel
    {
        public class Settings
        {
            public string host = "https://meowfacts.herokuapp.com";
            public bool launch = true;
            public Meow.Root meow = new Meow.Root();
            static public Authentification authentification = new Authentification("meow");
            public Requests requests = new Requests(authentification);
        }

        public Settings settings = new Settings();
        public ClockBuilder clockBuilder = new ClockBuilder("meow");
        

        public async Task<Task> start()
        {
            settings.launch = true;

            await get();

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
                    await get();
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<Meow.Root> get()
        {
            Dictionary<string, string> data = await settings.requests.create(
                settings.host,
                null,
                null,
                null
            );
            string result = await settings.requests.get(data);

            settings.meow = JsonConvert.DeserializeObject<Meow.Root>(result);

            return (settings.meow);
        }
    }

    public class DogModel
    {
        public class Settings
        {
            public string host = "https://random.dog/woof.json";
            public bool launch = true;
            public Dog.Root dog = new Dog.Root();
            static public Authentification authentification = new Authentification("dog");
            public Requests requests = new Requests(authentification);
        }

        public Settings settings = new Settings();
        public ClockBuilder clockBuilder = new ClockBuilder("dog");

        public async Task<Task> start()
        {
            settings.launch = true;

            await get();

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
                    await get();
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<Dog.Root> get()
        {
            Dictionary<string, string> data = await settings.requests.create(
                settings.host,
                null,
                null,
                null
            );
            string result = await settings.requests.get(data);

            settings.dog = JsonConvert.DeserializeObject<Dog.Root>(result);

            return (settings.dog);
        }
    }

    public class CatModel
    {
        public class Settings
        {
            public string host = "https://api.thecatapi.com/v1/images/search";
            public string key = "4c4b8187-23f0-4261-9f87-3e80a54b820c";
            public bool launch = true;
            public Cat.Root cat = new Cat.Root();
            static public Authentification authentification = new Authentification("cat");
            public Requests requests = new Requests(authentification);
        }

        public Settings settings = new Settings();
        Cache cache = new Cache();
        public ClockBuilder clockBuilder = new ClockBuilder("cat");

        public async Task<Task> start()
        {
            settings.launch = true;

            await get();

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
                    await get();
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<Cat.Root> get()
        {
            string check = await cache.get("catmodel");

            Dictionary<string, string> headers = null;
            Dictionary<string, string> data = await settings.requests.create(
                settings.host,
                headers,
                null,
                null
            );
            string result = await settings.requests.get(data);

            if (check != null) {
                settings.key = check;
            }
            headers = new Dictionary<string, string>()
            {
                {"X-Api-Key", $"{settings.key}"}
            };

            result = result.Replace("[{", "{");
            result = result.Replace("}]", "}");
            settings.cat = JsonConvert.DeserializeObject<Cat.Root>(result);

            return (settings.cat);
        }

        public async Task<Task> key(string api_key)
        {
            if (api_key != null) {
                settings.key = api_key;
                await cache.add("catmodel", api_key);
            }

            return (Task.CompletedTask);
        }
    }

    public class DuckModel
    {
        public class Settings
        {
            public string host = "https://random-d.uk/api/v2/random";
            public Duck.Root duck = new Duck.Root();
            public bool launch = true;
            static public Authentification authentification = new Authentification("duck");
            public Requests requests = new Requests(authentification);
        }

        public Settings settings = new Settings();
        public ClockBuilder clockBuilder = new ClockBuilder("duck");

        public async Task<Task> start()
        {
            settings.launch = true;

            await get();

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
                    await get();
                    await clockBuilder.start();
                }
                System.Threading.Thread.Sleep(1000);
            }


            return (Task.CompletedTask);
        }

        public async Task<Duck.Root> get()
        {
            Dictionary<string, string> data = await settings.requests.create(
                settings.host,
                null,
                null,
                null
            );
            string result = await settings.requests.get(data);

            settings.duck = JsonConvert.DeserializeObject<Duck.Root>(result);

            return (settings.duck);
        }
    }

    public class PanelModel : PageModel
    {
        public class Settings
        {
            public Languages languages = new Languages();
            static public Authentification authentification = new Authentification("Panel");
            public Requests request = new Requests(authentification);
        }

        public class PanelContent
        {
            public List<Meme.Root> memes = new List<Meme.Root>();
            public List<Quote.Root> quotes = new List<Quote.Root>();
            public List<Number.Root> numbers = new List<Number.Root>();
            public List<Insult.Root> insults = new List<Insult.Root>();
            public List<Meow.Root> meows = new List<Meow.Root>();
            public List<Dog.Root> dogs = new List<Dog.Root>();
            public List<Duck.Root> ducks = new List<Duck.Root>();
            public List<Cat.Root> cats = new List<Cat.Root>();
        }

        public Settings settings = new Settings();
        public PanelContent content = new PanelContent();

        public MemeModel memeModel = new MemeModel();
        public QuoteModel quoteModel = new QuoteModel();
        public NumberModel numberModel = new NumberModel();
        public InsultModel insultModel = new InsultModel();
        public MeowModel meowModel = new MeowModel();
        public DogModel dogModel = new DogModel();
        public DuckModel duckModel = new DuckModel();
        public CatModel catModel = new CatModel();

        public async Task<PanelContent> generate()
        {
            return (content);
        }

        // CLEANNERS

        public async Task<Task> clean_meme()
        {
            if (content.memes.Count > 0)
                content.memes.RemoveAt(content.memes.Count - 1);

            return (Task.CompletedTask);
        }

        public async Task<Task> clean_quote()
        {
            if (content.quotes.Count > 0)
                content.quotes.RemoveAt(content.quotes.Count - 1);

            return (Task.CompletedTask);
        }

        public async Task<Task> clean_number()
        {
            if (content.numbers.Count > 0)
                content.numbers.RemoveAt(content.numbers.Count - 1);

            return (Task.CompletedTask);
        }

        public async Task<Task> clean_insult()
        {
            if (content.insults.Count > 0)
                content.insults.RemoveAt(content.insults.Count - 1);

            return (Task.CompletedTask);
        }

        public async Task<Task> clean_meow()
        {
            if (content.meows.Count > 0)
                content.meows.RemoveAt(content.meows.Count - 1);

            return (Task.CompletedTask);
        }

        public async Task<Task> clean_dog()
        {
            if (content.dogs.Count > 0)
                content.dogs.RemoveAt(content.dogs.Count - 1);

            return (Task.CompletedTask);
        }

        public async Task<Task> clean_duck()
        {
            if (content.ducks.Count > 0)
                content.ducks.RemoveAt(content.ducks.Count - 1);

            return (Task.CompletedTask);
        }

        public async Task<Task> clean_cat()
        {
            if (content.cats.Count > 0)
                content.cats.RemoveAt(content.cats.Count - 1);

            return (Task.CompletedTask);
        }

        // STARTERS

        public async Task<Task> start_meme()
        {
            await memeModel.start();
            await generate_meme();

            return (Task.CompletedTask);
        }

        public async Task<Task> start_quote()
        {
            await quoteModel.start();
            await generate_quote();

            return (Task.CompletedTask);
        }

        public async Task<Task> start_number()
        {
            await numberModel.start();
            await generate_number();

            return (Task.CompletedTask);
        }

        public async Task<Task> start_insult()
        {
            await insultModel.start();
            await generate_insult();

            return (Task.CompletedTask);
        }

        public async Task<Task> start_meow()
        {
            await meowModel.start();
            await generate_meow();

            return (Task.CompletedTask);
        }

        public async Task<Task> start_dog()
        {
            await dogModel.start();
            await generate_dog();

            return (Task.CompletedTask);
        }

        public async Task<Task> start_duck()
        {
            await duckModel.start();
            await generate_duck();

            return (Task.CompletedTask);
        }

        public async Task<Task> start_cat()
        {
            await catModel.start();
            await generate_cat();

            return (Task.CompletedTask);
        }

        // STOPPERS

        public async Task<Task> stop_meme()
        {
            await memeModel.stop();

            return (Task.CompletedTask);
        }

        public async Task<Task> stop_quote()
        {
            await quoteModel.stop();

            return (Task.CompletedTask);
        }

        public async Task<Task> stop_number()
        {
            await numberModel.stop();

            return (Task.CompletedTask);
        }

        public async Task<Task> stop_insult()
        {
            await insultModel.stop();

            return (Task.CompletedTask);
        }

        public async Task<Task> stop_meow()
        {
            await meowModel.stop();

            return (Task.CompletedTask);
        }

        public async Task<Task> stop_dog()
        {
            await dogModel.stop();

            return (Task.CompletedTask);
        }

        public async Task<Task> stop_duck()
        {
            await duckModel.stop();

            return (Task.CompletedTask);
        }

        public async Task<Task> stop_cat()
        {
            await catModel.stop();

            return (Task.CompletedTask);
        }

        public async Task generate_meme()
        {
            string module = "meme";
            List<Meme.Root> memes = new List<Meme.Root>();
            int count = await panel_settings(module);

            for (int i = 0; i < count; i++) {
                memes.Add(memeModel.settings.meme);
            }

            content.memes = memes;
        }

        public async Task generate_quote()
        {
            string module = "quote";
            List<Quote.Root> quotes = new List<Quote.Root>();
            int count = await panel_settings(module);

            for (int i = 0; i < count; i++) {
                quotes.Add(quoteModel.settings.quote);
            }

            content.quotes = quotes;
        }

        public async Task generate_number()
        {
            string module = "number";
            List<Number.Root> numbers = new List<Number.Root>();
            int count = await panel_settings(module);
            Number.Root numberRoot = new Number.Root();

            for (int i = 0; i < count; i++) {
                numberRoot.number = numberModel.settings.numberRoot.number;
                numberRoot.math = numberModel.settings.numberRoot.math;
                numberRoot.date = numberModel.settings.numberRoot.date;
                numberRoot.year = numberModel.settings.numberRoot.year;
                numberRoot.trivia = numberModel.settings.numberRoot.trivia;

                numbers.Add(numberRoot);
            }

            content.numbers = numbers;
        }

        public async Task generate_insult()
        {
            string module = "insult";
            List<Insult.Root> insults = new List<Insult.Root>();
            int count = await panel_settings(module);

            for (int i = 0; i < count; i++) {
                insults.Add(insultModel.settings.insult);
            }

            content.insults = insults;
        }

        public async Task generate_meow()
        {
            string module = "meow";
            List<Meow.Root> meows = new List<Meow.Root>();
            int count = await panel_settings(module);

            for (int i = 0; i < count; i++) {
                meows.Add(meowModel.settings.meow);
            }

            content.meows = meows;
        }

        public async Task generate_dog()
        {
            string module = "dog";
            List<Dog.Root> dogs = new List<Dog.Root>();
            int count = await panel_settings(module);

            for (int i = 0; i < count; i++) {
                dogs.Add(await dogModel.get());
            }

            content.dogs = dogs;
        }

        public async Task generate_duck()
        {
            string module = "duck";
            List<Duck.Root> ducks = new List<Duck.Root>();
            int count = await panel_settings(module);

            for (int i = 0; i < count; i++) {
                ducks.Add(duckModel.settings.duck);
            }

            content.ducks = ducks;
        }

        public async Task generate_cat()
        {
            string module = "cat";
            List<Cat.Root> cats = new List<Cat.Root>();
            int count = await panel_settings(module);

            for (int i = 0; i < count; i++) {
                cats.Add(catModel.settings.cat);
            }

            content.cats = cats;
        }

        public async Task<int> panel_settings(string key)
        {
            Dictionary<string, int> settings_data = new Dictionary<string, int>()
            {
                {"meme", 1},
                {"quote", 1},
                {"number", 1},
                {"insult", 1},
                {"meow", 1},
                {"dog", 1},
                {"duck", 1},
                {"cat", 1}
            };

            if (settings_data.Keys.Contains(key) == true)
                return (settings_data[key]);
            return (-1);
        }
    }
}
