using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.JunkCode
{
    abstract class JunkType
    {
        protected string name;

        protected JunkType()
        {
        }

        public string GetName()
        {
            return this.name;
        }

        public abstract string Declaration();
        public abstract string Definition();
        public abstract string Value();
    }
}
