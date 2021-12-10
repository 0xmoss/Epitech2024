using DashboardAPI.Models;
using MongoDB.Driver;
using System.Collections.Generic;
using System.Linq;
using System;

namespace DashboardAPI.Services
{
    // This class have an access to appsettings.json values
    public class UserService
    {
        private readonly IMongoCollection<User> _users;

        public UserService(IDashboardDatabaseSettings settings)
        {
            var client = new MongoClient(settings.ConnectionString); // Reads server instance in order to effect DB operations
            var database = client.GetDatabase(settings.DatabaseName); // Represents database 

            _users = database.GetCollection<User>(settings.UsersCollectionName); // Gets collection of users
        }

        public List<User> Get() =>
            _users.Find(user => true).ToList();

        public User Get(string id) =>
            _users.Find<User>(user => user.Id == id).FirstOrDefault();

        public User Create(User user)
        {
            _users.InsertOne(user);
            return user;
        }

        public void Update(string id, User userIn) =>
            _users.ReplaceOne(user => user.Id == id, userIn);

        public void Remove(User userIn) =>
            _users.DeleteOne(user => user.Id == userIn.Id);

        public void Remove(string id) => 
            _users.DeleteOne(user => user.Id == id);
    }
}