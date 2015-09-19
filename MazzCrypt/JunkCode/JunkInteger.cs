using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.JunkCode
{
    class JunkInteger : JunkType
    {
        int val;

        public JunkInteger()
        {
            name = Junk.GetUnusedVariable();
            val = Junk.random.Next(0, Int32.MaxValue);
        }

        public override string Declaration()
        {
            return "int";
        }

        public override string Definition()
        {
            string str = string.Concat("", Declaration()); // int
            str = string.Concat(str, " "); // int 
            str = string.Concat(str,  base.GetName()); // int blah
            str = string.Concat(str, " = "); // int blah = 
            return string.Concat(str, Value()); // int blah = value
        }

        public override string Value()
        {
            // chance to return a hex value
            int chanceForHex = Junk.random.Next(0, 1);
            string rtnStr;

            if (chanceForHex == 0)
                rtnStr = "0x" + val.ToString("X2");
            else
                rtnStr = val.ToString();

            return rtnStr;
        }
    }
}
