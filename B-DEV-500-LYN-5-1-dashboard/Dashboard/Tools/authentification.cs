using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Dashboard.Pages
{
    public class Authentification
    {
        public string module = null;
        public string token = null;
        public string fetch = null;
        public bool status = false;

        public Authentification(string module_name)
        {
            module = module_name;
        }
    }
}
