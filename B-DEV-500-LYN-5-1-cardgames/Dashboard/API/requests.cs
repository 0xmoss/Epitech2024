using System;
using System.Collections.Generic;
using System.Threading.Tasks;

using System.IO;

using RestSharp;

namespace Dashboard.Pages
{
    public class Requests
    {
        public List<string> blacklist = new List<string>()
        {
            "url",
            "body",
            "useragent"
        };

        public Requests(Authentification auth_data)
        {
        }

        public async Task<Dictionary<string, string>> create(string url, Dictionary<string, string> headers, string body, string useragent)
        {
            Dictionary<string, string> informations = new Dictionary<string, string>();

            informations.Add("url", url);
            informations.Add("body", body);
            informations.Add("useragent", useragent);

            if (headers != null){
                foreach (var key in headers)
                {
                    informations.Add(key.Key, key.Value);
                }
            }

            await display(informations);

            return (informations);
        }

        public async Task<Dictionary<string, string>> create_token(string type, string token)
        {
            Dictionary<string, string> data = new Dictionary<string, string>()
            {
                {"Authorisation", $"{type} {token}"}
            };

            return (data);
        }

        private async Task<Task> display(Dictionary<string, string> informations)
        {
            bool show = true;

            if (show == true) {
                Console.WriteLine("--------------------------------");
                foreach(var item in informations)
                {
                    Console.WriteLine($"{item.Key} : {item.Value}");
                }
                Console.WriteLine("--------------------------------");
            }

            return (Task.CompletedTask);
        }

        private bool valid(Dictionary<string, string> informations, string key)
        {
            if (informations.ContainsKey(key) == true) {
                if (informations[key] != null) {
                    return (true);
                }
            }

            return (false);
        }

        public async Task<String> post(Dictionary<string, string> informations)
        {
            RestClient client = new RestClient();
            RestRequest request = new RestRequest();
            IRestResponse response = null;
        
            await display(informations);
            
            if (valid(informations, "url") == true)
                request.Resource = informations["url"];

            if (valid(informations, "body") == true)
                request.AddJsonBody(informations["body"]);

            if (valid(informations, "useragent") == true)
                client.UserAgent = informations["useragent"];

            if (valid(informations, "token") == true)
                request.AddHeader("Authorization", "Bearer" + informations["token"]);

            foreach (var item in informations)
            {
                if (blacklist.Contains(item.Key) == false)
                    request.AddHeader(item.Key, item.Value);
            }

            response = client.Post(request);

            return (response.Content);
        }

        public async Task<String> get(Dictionary<string, string> informations)
        {
            RestClient client = new RestClient();
            RestRequest request = new RestRequest();
            IRestResponse response = null;

            await display(informations);
            
            if (valid(informations, "url") == true)
                request.Resource = informations["url"];

            if (valid(informations, "body") == true)
                request.AddJsonBody(informations["body"]);

            if (valid(informations, "useragent") == true)
                client.UserAgent = informations["useragent"];

            foreach (var item in informations)
            {
                if (blacklist.Contains(item.Key) == false)
                    request.AddHeader(item.Key, item.Value);
            }

            response = client.Get(request);

            return (response.Content);
        }

        public async Task<String> put(Dictionary<string, string> informations)
        {
            RestClient client = new RestClient();
            RestRequest request = new RestRequest();
            IRestResponse response = null;
        
            await display(informations);
            
            if (valid(informations, "url") == true)
                request.Resource = informations["url"];

            if (valid(informations, "body") == true)
                request.AddJsonBody(informations["body"]);

            if (valid(informations, "useragent") == true)
                client.UserAgent = informations["useragent"];

            foreach (var item in informations)
            {
                if (blacklist.Contains(item.Key) == false)
                    request.AddHeader(item.Key, item.Value);
            }

            response = client.Put(request);

            return (response.Content);
        }

        public async Task<String> patch(Dictionary<string, string> informations)
        {
            RestClient client = new RestClient();
            RestRequest request = new RestRequest();
            IRestResponse response = null;
        
            await display(informations);
            
            if (valid(informations, "url") == true)
                request.Resource = informations["url"];

            if (valid(informations, "body") == true)
                request.AddJsonBody(informations["body"]);

            if (valid(informations, "useragent") == true)
                client.UserAgent = informations["useragent"];

            foreach (var item in informations)
            {
                if (blacklist.Contains(item.Key) == false)
                    request.AddHeader(item.Key, item.Value);
            }

            response = client.Patch(request);

            return (response.Content);
        }

        public async Task<String> delete(Dictionary<string, string> informations)
        {
            RestClient client = new RestClient();
            RestRequest request = new RestRequest();
            IRestResponse response = null;
        
            await display(informations);
            
            if (valid(informations, "url") == true)
                request.Resource = informations["url"];

            if (valid(informations, "body") == true)
                request.AddJsonBody(informations["body"]);

            if (valid(informations, "useragent") == true)
                client.UserAgent = informations["useragent"];

            foreach (var item in informations)
            {
                if (blacklist.Contains(item.Key) == false)
                    request.AddHeader(item.Key, item.Value);
            }

            response = client.Delete(request);

            return (response.Content);
        }
    }
}
