using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.JunkCode
{
    class JunkCharacter : JunkType
    {
        string val;

        public JunkCharacter()
        {
            name = Junk.GetUnusedVariable();
            val = Junk.RandomString(1);
        }

        public override string Declaration() 
        {
            return "char";
        }

        public override string Definition()
        {
            string str = string.Concat("", Declaration()); // char
            str = string.Concat(str, " "); // char  
            str = string.Concat(str, GetName()); // char a
            str = string.Concat(str, " = "); // char a = 
            return string.Concat(str, Value()); // char a = 'v'
        }

        public override string Value()
        {
            return string.Concat("\'", val , "\'");
        }

    }
}
