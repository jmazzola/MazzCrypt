using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.Encryption
{
    class StringEnc
    {
        protected static char encKey;

        public StringEnc()
        {
        }

        public static int[] Encrypt(string text)
        {
            char[] charArray = text.ToCharArray();
            int[] numArray = new int[charArray.Length];
            
            for(int i = 0; i < numArray.Length; i++)
            {
                numArray[i] = charArray[i] ^ (char)((encKey + (char)i) % 0xff);
            }

            return numArray;
        }

        public static char GetKey()
        {
            return encKey;
        }

        public static void SetKey(char key)
        {
            encKey = key;
        }
    }
}
