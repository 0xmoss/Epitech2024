using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Dashboard.Pages
{
    public class LogoutModel
    {
        public async Task<Task> cache()
        {
            string[] files = null;
    
            if (System.IO.Directory.Exists("cache") == true) {
                files = System.IO.Directory.GetFiles("cache");
                foreach (string file in files)
                    System.IO.File.Delete(file);
                System.IO.Directory.Delete("cache");
                Console.WriteLine("cache cleanned");
            } else
                Console.WriteLine("no cache to clean");

            return (Task.CompletedTask);
        }

        public async Task<Task> database()
        {
            Console.WriteLine("no database linked to logout");

            return (Task.CompletedTask);
        }

        public async Task<Task> all()
        {
            await cache();
            await database();

            return (Task.CompletedTask);
        }
    }
}
