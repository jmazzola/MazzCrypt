using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.JunkCode
{
    class JunkString : JunkType
    {
        string val;

        public JunkString()
        {
            name = Junk.GetUnusedVariable();
            val = Junk.RandomString(Junk.random.Next(8, 25));
        }

        public override string Declaration()
        {
            return "char*";
        }

        public override string Definition()
        {
            string str = string.Concat("", Declaration()); // char*
            str = string.Concat(str, " "); // char* 
            str = string.Concat(str, base.GetName()); // char* blah
            str = string.Concat(str, " = "); // char* blah = 
            return string.Concat(str, Value()); // char* blah = "asdasdasd"
        }

        public override string Value()
        {
            return string.Concat("\"", val, "\"");
        }
    }
}
