using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Net.Http;

namespace Dashboard.Pages
{
    public class RegisterModel : PageModel
    {
        public void OnGet()
        {
        }

        public async Task<bool> callRegister()
        {
            Task call = null;

            Console.WriteLine("Calling callRegister() ...");

            // callRegister

            Console.WriteLine("login register");

            return (false);
        }
    }
}
