using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Valval.Models {
    public class Client : Person{
        public string TypeOfService { get; set; }
        public string Location { get; set; }
        public string Contact { get; set; }
    }
}
