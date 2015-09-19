using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.JunkCode
{
    class JunkBool : JunkType
    {
        bool val;

        public JunkBool()
        {
            name = Junk.GetUnusedVariable();

            int rnd = Junk.random.Next(0, 1);
            bool[] bools = { true, false };

            val = bools[rnd];
        }

        public override string Declaration() 
        {
            return "bool";
        }

        public override string Definition()
        {
            string str = string.Concat("", Declaration()); // bool
            str = string.Concat(str, " "); // bool   
            str = string.Concat(str, GetName()); // bool name
            str = string.Concat(str, " = "); // bool name = 
            return string.Concat(str, Value()); // bool name = true/false
        }

        public override string Value()
        {
            return val.ToString().ToLower();
        }
    }
}
