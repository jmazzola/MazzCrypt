using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using MazzCrypt.JunkCode;

namespace MazzCrypt.Randomization
{
    class HeaderFile : BaseFile
    {
        public HeaderFile(string fn)
        {
            fileName = fn;
            fileData = File.ReadAllText(fileName);
            for (int i = 0; i < (int)this.blocks.Length; i++)
            {
                this.blocks[i] = new List<string>();
            }
        }

        protected override string AddCode()
        {
            if (junkDeclaresOnly)
            {
                return string.Concat(Junk.GenerateDeclares(junkMinLines, junkMaxLines, true), Environment.NewLine);
            }
            return string.Concat(Junk.GenerateDeclares(junkMinLines, junkMaxLines, true), Environment.NewLine);
        }
    }
}
