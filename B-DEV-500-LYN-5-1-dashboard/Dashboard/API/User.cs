namespace Dashboard.API
{
    public class User
    {
        public User(string UsernameNew, string PasswordNew)
        {
            Username = UsernameNew;
            Password = PasswordNew;
            Connected = true;
        }

        public string Id { get; set; }
        public string Username { get; set; }
        public string Password { get; set; }
        public bool Connected { get; set; }
    }
}