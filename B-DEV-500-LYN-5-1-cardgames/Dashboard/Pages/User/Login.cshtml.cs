using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Dashboard.Pages
{
    public class LoginModel : PageModel
    {
        Database database = new Database();

        public async Task<bool> call_login()
        {
            Task call = null;
        
            Console.WriteLine("calling login...");

            await database.userExists("test");

            Console.WriteLine("login called");

            return (false);
        }
    }
}
