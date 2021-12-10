using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;
using Newtonsoft.Json;

namespace DashboardAPI.Models
{
    public class User
    {
        [BsonId] // Announce primary key
        [BsonRepresentation(BsonType.ObjectId)] // Converts string into ObjectId
        public string Id { get; set; } // Required for MongoDB

        [BsonElement("Name")] // Name of the user
        public string UserName { get; set; }

        [BsonElement("Password")] // Password of the user (Encrypted)
        public string Password  { get; set; }

        [BsonElement("Connected")] // Connection status of the user
        public bool Connected { get; set; }
    }
}