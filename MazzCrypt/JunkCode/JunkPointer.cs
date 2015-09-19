using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.JunkCode
{
    class JunkPointer : JunkType
    {
        int val;
        string type;
        bool hasMultipleMemory;

        bool isDeleted = false;

        public JunkPointer()
        {
            name = Junk.GetUnusedVariable();
            val = Junk.random.Next(0, Int32.MaxValue);

            bool[] randBool = { true, false };

            hasMultipleMemory = randBool[Junk.random.Next(0,1)];
        }

        public override string Declaration()
        {
            string[] types =
            { 
                "int*", "bool*", "float*"
            };
            type = types[Junk.random.Next(0, types.Length)];

            return type;
        }

        public override string Definition()
        {
            string str;
            if (hasMultipleMemory == false)
            {
                str = string.Concat("", Declaration()); // int*
                str = string.Concat(str, " "); // int* 
                str = string.Concat(str, base.GetName()); // int* blah
                str = string.Concat(str, " = "); // int* blah = 
                return string.Concat(str, Value()); // int* blah = new int
            }

            str = string.Concat("", Declaration()); // int*
            str = string.Concat(str, " "); // int* 
            str = string.Concat(str, base.GetName()); // int* blah
            str = string.Concat(str, " = "); // int* blah = 
            return string.Concat(str, Value()); // int* blah = new int[100]
        }

        public override string Value()
        {
            if (hasMultipleMemory)
                return "new " + type.Replace("*", "") + "[" + Junk.random.Next(2, 100).ToString() + "]";
            else
                return "new" + type.Replace("*", "");

        }

        public string Cleanup()
        {
            if (hasMultipleMemory)
                return "delete[] " + name;
            else
                return "delete" + name;
        }

        public bool IsDeleted()
        {
            return this.isDeleted;
        }

        public bool HasMemory()
        {
            return this.hasMultipleMemory;
        }
    }
}
