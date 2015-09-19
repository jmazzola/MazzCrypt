using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.JunkCode
{
    class RandomStringArrays
    {
        public static string[] RandomizeStrings(string[] arr)
        {
            List<KeyValuePair<int, string>> keyValuePairs = new List<KeyValuePair<int, string>>();
            string[] strArrays = arr;
            for (int i = 0; i < (int)strArrays.Length; i++)
            {
                string str = strArrays[i];
                keyValuePairs.Add(new KeyValuePair<int, string>(Junk.random.Next(), str));
            }
            IOrderedEnumerable<KeyValuePair<int, string>> key =
                from item in keyValuePairs
                orderby item.Key
                select item;
            string[] value = new string[(int)arr.Length];
            int num = 0;
            foreach (KeyValuePair<int, string> keyValuePair in key)
            {
                value[num] = keyValuePair.Value;
                num++;
            }
            return value;
        }
    }
}
