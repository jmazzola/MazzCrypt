using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.JunkCode
{
    class JunkFloat : JunkType
    {
        double val;

        public JunkFloat()
        {
            name = Junk.GetUnusedVariable();
            val = Junk.RandomFloat(1, 100);
        }

        public override string Declaration() 
        {
            return "float";
        }

        public override string Definition()
        {
            string str = string.Concat("", Declaration()); // float
            str = string.Concat(str, " "); // float  
            str = string.Concat(str, GetName()); // float name
            str = string.Concat(str, " = "); // float name = 
            return string.Concat(str, Value()); // float name = 10.0f
        }

        public override string Value()
        {
            decimal a = (decimal)val;
            decimal rounded = Math.Round(a, 2, MidpointRounding.ToEven);
            return string.Concat(rounded.ToString(), "f");
        }
    }
}
