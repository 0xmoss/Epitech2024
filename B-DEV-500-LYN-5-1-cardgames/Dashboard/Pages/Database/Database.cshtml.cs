using System;
using Microsoft.AspNetCore.Mvc;
using System.Collections.Generic;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using System.Threading.Tasks;
using System.Net;
using System.Data;
using Newtonsoft.Json;

using Dashboard.API;

namespace Dashboard.Pages
{
    public class Database
    {
        static public Authentification authentification = new Authentification("database");
        public Requests request = new Requests(authentification);

        public class Settings
        {
            public string base_url = "http://localhost:8081/api";
        }

        public Settings settings = new Settings();

        public Database()
        {
        }

        // getAllUsers(): Gets a list of all database users in JSON format
        public async Task<string> getAllUsers()
        {
            string route = $"{settings.base_url}/Users";

            Dictionary<string, string> data = await request.create(route, null, null, null);
            string result = await request.get(data);

            return (result);
        }

        // createUser(): Creates a user in database
        public async Task<bool> createUser(string name, string password)
        {
            string route = $"{settings.base_url}/Users";

            API.User user = new API.User(name, password);

            Dictionary<string, string> data = await request.create(route, null, JsonConvert.SerializeObject(user), null);
            string result = await request.post(data);

            return (false);
        }

        // getUser(): Gets a specific user in JSON format from database
        public async Task<string> getUser(string id)
        {
            string route = $"{settings.base_url}/Users/{id}";

            Dictionary<string, string> data = await request.create(route, null, null, null);
            string result = await request.get(data);

            return (result);
        }

        public async Task<string> userExists(string id)
        {
            string route = $"{settings.base_url}/Users";

            Dictionary<string, string> data = await request.create(route, null, null, null);
            string result = await request.get(data);

            return (result);
        }

        // setUserConnectionState(): Sets a users connection status (true=conneted / false=disconnected)
        public async Task<bool> setUserConnectionState(string id, bool newConnectionState)
        {
            string route = $"{settings.base_url}/Users/{id}";

            API.User user = JsonConvert.DeserializeObject<API.User>(await getUser(id));
            
            user.Connected = newConnectionState;

            Dictionary<string, string> data = await request.create(route, null, JsonConvert.SerializeObject(user), null);
            string result = await request.put(data);

            return (false);
        }

        // setUserName(): Sets a new username to an existing user
        public async Task<bool> setUserName(string id, string newUserName)
        {
            string route = $"{settings.base_url}/Users/{id}";

            API.User user = JsonConvert.DeserializeObject<API.User>(await getUser(id));
            
            user.Username = newUserName;

            Dictionary<string, string> data = await request.create(route, null, JsonConvert.SerializeObject(user), null);
            string result = await request.put(data);

            return (false);
        }

        // setPassword(): Sets a new password to an existing user
        public async Task<bool> setPassword(string id, string newPassword)
        {
            string route = $"{settings.base_url}/Users/{id}";

            API.User user = JsonConvert.DeserializeObject<API.User>(await getUser(id));
            
            user.Password = newPassword;

            Dictionary<string, string> data = await request.create(route, null, JsonConvert.SerializeObject(user), null);
            string result = await request.put(data);

            return (false);
        }
    }
}
