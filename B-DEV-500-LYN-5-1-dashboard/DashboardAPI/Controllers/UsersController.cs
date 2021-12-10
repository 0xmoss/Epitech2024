using DashboardAPI.Models;
using DashboardAPI.Services;
using Microsoft.AspNetCore.Mvc;
using System.Collections.Generic;
using System;

namespace DashboardAPI.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UsersController : ControllerBase
    {
        private readonly UserService _userService;

        public UsersController(UserService userService)
        {
            _userService = userService;
        }

        [HttpGet]
        public ActionResult<List<User>> Get() =>
            _userService.Get();

        [HttpGet("{id:length(24)}", Name = "GetUser")]
        public ActionResult<User> Get(string id)
        {
            Console.WriteLine("Get() called. (id: " + id + ")");
            var user = _userService.Get(id);

            if (user == null)
            {
                Console.WriteLine(" - Invalid ID");
                return NotFound();
            }

            Console.WriteLine(" - User found: username=" + user.UserName + " password=" + user.Password);
            return user;
        }

        [HttpPost]
        public ActionResult<User> Create(User user)
        {
            Console.WriteLine("Create() called. (id=" + user.Id + " username=" + user.UserName + " password=" + user.Password + ")");
            _userService.Create(user);

            return CreatedAtRoute("GetUser", new { id = user.Id.ToString() }, user);
        }

        [HttpPut("{id:length(24)}")]
        public IActionResult Update(string id, User userIn)
        {
            var user = _userService.Get(id);

            if (user == null)
            {
                return NotFound();
            }

            _userService.Update(id, userIn);

            return NoContent();
        }

        [HttpDelete("{id:length(24)}")]
        public IActionResult Delete(string id)
        {
            Console.WriteLine("Delete() called. (id=" + id + ")");
            var user = _userService.Get(id);

            if (user == null)
            {
                return NotFound();
            }

            _userService.Remove(user.Id);

            return NoContent();
        }
    }
}