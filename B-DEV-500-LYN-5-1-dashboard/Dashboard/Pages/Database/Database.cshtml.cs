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
            public string base_url = "http://api:8081/api";
        }

        public Settings settings = new Settings();

        public Database()
        {
            System.Net.ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls | SecurityProtocolType.Tls11 | SecurityProtocolType.Tls12;
        }

        public async void ping()
        {
            Dictionary<string, string> data = await request.create(
                $"{settings.base_url}/Users", null, null, null
            );
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
        public async Task<string> createUser(string name, string password)
        {
            string route = $"{settings.base_url}/Users";

            API.User user = new API.User(name, password);

            Dictionary<string, string> data = await request.create(route, null, JsonConvert.SerializeObject(user), null);
            string result = await request.post(data);

            return (result);
        }

        // getUser(): Gets a specific user in JSON format from database
        public async Task<string> getUserFromId(string id)
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
        public async Task<string> setUserConnectionState(string id, bool newConnectionState)
        {
            string route = $"{settings.base_url}/Users/{id}";

            API.User user = JsonConvert.DeserializeObject<API.User>(await getUserFromId(id));

            user.Connected = newConnectionState;

            Dictionary<string, string> data = await request.create(route, null, JsonConvert.SerializeObject(user), null);
            string result = await request.put(data);

            return (result);
        }

        // setUserName(): Sets a new username to an existing user
        public async Task<string> setUserName(string id, string newUserName)
        {
            string route = $"{settings.base_url}/Users/{id}";

            API.User user = JsonConvert.DeserializeObject<API.User>(await getUserFromId(id));

            user.Username = newUserName;

            Dictionary<string, string> data = await request.create(route, null, JsonConvert.SerializeObject(user), null);
            string result = await request.put(data);

            return (result);
        }

        // setPassword(): Sets a new password to an existing user
        public async Task<string> setPassword(string id, string newPassword)
        {
            string route = $"{settings.base_url}/Users/{id}";

            API.User user = JsonConvert.DeserializeObject<API.User>(await getUserFromId(id));

            user.Password = newPassword;

            Dictionary<string, string> data = await request.create(route, null, JsonConvert.SerializeObject(user), null);
            string result = await request.put(data);

            return (result);
        }

        // usernameExists(): Returns true if username alreaady exists, false otherwise
        public async Task<bool> usernameExists(string username)
        {
            string userListJson = await getAllUsers();
            var userList = JsonConvert.DeserializeObject<List<API.User>>(userListJson);

            if (userList.Find(item => item.Username == username) != null)
            {
                return (true);
            }
            return (false);
        }

        // passwordMatch(): Returns true if password matches the password in database, return false otherwise
        public async Task<bool> passwordMatch(string username, string password)
        {
            string userListJson = await getAllUsers();
            var userList = JsonConvert.DeserializeObject<List<API.User>>(userListJson);

            if (userList.Find(item => (item.Username == username && item.Password == password)) != null)
            {
                return (true);
            }

            return (false);
        }

        // getUserFromUsername(): returns a user 
        public async Task<API.User> getUserFromUsername(string username)
        {
            string userListJson = await getAllUsers();
            var userList = JsonConvert.DeserializeObject<List<API.User>>(userListJson);

            return (userList.Find(item => item.Username == username));
        }

        // getUserConnectionState(): get connection state of a user
        public async Task<bool> getUserConnectionState(string id)
        {
            string userJson = await getUserFromId(id);

            API.User user = JsonConvert.DeserializeObject<API.User>(userJson);

            return (user.Connected);
        }

        // registerUser(): registers a user in the database
        public async Task<bool> regiserUser(string username, string password)
        {
            bool user = await usernameExists(username);

            if (user == false)
            {
                await createUser(username, password);
                return true;
            }
            return false;
        }

        // loginUser(): logs a user in the database
        public async Task<bool> loginUser(string username, string password)
        {
            bool match = await passwordMatch(username, password);

            if (match)
            {
                Globals.CurrentUser = await getUserFromUsername(username);
                return true;
            }
            return false;
        }

        // logoutUser(): logs out a user + in the database
        public async Task logoutUser()
        {
            Globals.CurrentUser = null;
        }
    }
}
