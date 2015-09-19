using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.CodeDom.Compiler;
using System.Reflection;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using System.IO;
using Microsoft.CSharp;
using MazzCrypt.Encryption;
using MazzCrypt.JunkCode;

namespace MazzCrypt.Randomization
{
    public struct ParseItem
    {
        public string tag;

        public int pos;

        public ParseItem(string t, int p)
        {
            this.tag = t;
            this.pos = p;
        }
    }

    abstract class BaseFile
    {
        protected bool escapeString;

        protected bool junkEnabled;
        protected bool junkDeclaresOnly;
        protected int junkMinLines;
        protected int junkMaxLines;

        protected Stack<ParseItem> parseStack = new Stack<ParseItem>();
        protected List<string>[] blocks = new List<string>[100];

        protected int currentBlockLayer = -1;
        protected int cursor;

        protected string fileName;
        protected string fileData;

        protected abstract string AddCode();

        public string GetData()
        {
            return fileData;
        }

        protected BaseFile()
        {
        }

        protected void CheckAll()
        {
            bool i;
            ParseItem fromStack;
            string str;
            string str1 = "";

            // Check for strings
            if (Match("\""))
            {
                int currentCursor = cursor;
                for (i = false; !i; i = fileData[currentCursor - 1] != '\\')
                {
                    currentCursor++;
                    currentCursor = fileData.IndexOf("\"", currentCursor);

                    if (currentCursor == -1)
                    {
                        break;
                    }
                }

                if (i == true)
                {
                    string literal = ToLiteral(fileData.Substring(cursor + 1, currentCursor - cursor - 1));

                    if (!escapeString)
                    {
                        cursor = currentCursor + 1;
                    }
                    else
                    {
                        // Handle replacing strings with Decrypt method
                        int litLength = literal.Length;
                        string decryptString = "Decrypt(" + litLength.ToString();

                        int[] encrypted = StringEnc.Encrypt(literal);

                        for (int currentLit = 0; currentLit < literal.Length; currentLit++)
                        {
                            decryptString += "," + encrypted[currentLit];
                        }

                        decryptString += ")";
                        SafeRemove(cursor, currentCursor - cursor + 1);
                        SafeInsert(cursor, decryptString);
                    }
                }
            }
            // Check for tags
            if (Match("["))
            {
                int num1 = fileData.IndexOf("]", cursor + 1);
                str1 = fileData.Substring(cursor + 1, num1 - cursor - 1);
                string[] tagArgs = str1.Split(new char[] { ' ' });
                string tag = tagArgs[0];

                if (IsTag(tag))
                {
                    SafeRemove(cursor, num1 - cursor + 1);
                    bool flag = (str1.EndsWith("/") ? false : !str1.StartsWith("/"));
                    string str4 = tag;
                    string str5 = str4;

                    if (str4 != null)
                    {
                        switch (str5)
                        {
                            case "junk_enable":
                                {
                                    junkEnabled = true;
                                    junkDeclaresOnly = false;

                                    // If arguments are listed, (min and max lines)
                                    if (tagArgs.Length != 3)
                                    {
                                        if (tagArgs.Length != 4)
                                        {
                                            break;
                                        }
                                        this.junkMinLines = int.Parse(tagArgs[1]);
                                        this.junkMaxLines = int.Parse(tagArgs[2]);
                                        break;
                                    }
                                    else
                                    {
                                        // One parameter
                                        junkMaxLines = junkMinLines = int.Parse(tagArgs[1]);
                                        break;
                                    }
                                }

                            case "add_junk":
                                {
                                    int minLines = 5;
                                    int maxLines = 10;

                                    if (tagArgs.Length == 3)
                                    {
                                        maxLines = minLines = int.Parse(tagArgs[1]);
                                    }
                                    else if (tagArgs.Length == 4)
                                    {
                                        minLines = int.Parse(tagArgs[1]);
                                        maxLines = int.Parse(tagArgs[2]);
                                    }
                                    SafeInsert(cursor, Junk.GenerateCode(minLines, maxLines));
                                    break;
                                }

                            case "add_junk_datamembers":
                                {
                                    int minLines = 5;
                                    int maxLines = 10;

                                    if (tagArgs.Length == 3)
                                    {
                                        maxLines = minLines = int.Parse(tagArgs[1]);
                                    }
                                    else if (tagArgs.Length == 4)
                                    {
                                        minLines = int.Parse(tagArgs[1]);
                                        maxLines = int.Parse(tagArgs[2]);
                                    }
                                    SafeInsert(cursor, Junk.GenerateDeclares(minLines, maxLines, false));
                                    break;
                                }

                            case "add_junk_function":
                                {
                                    int minArgs = 1;
                                    int maxArgs = 6;

                                    if (tagArgs.Length == 3)
                                    {
                                        maxArgs = minArgs = int.Parse(tagArgs[1]);
                                    }
                                    else if (tagArgs.Length == 4)
                                    {
                                        minArgs = int.Parse(tagArgs[1]);
                                        maxArgs = int.Parse(tagArgs[2]);
                                    }
                                    SafeInsert(cursor, Junk.GenerateFunctions(minArgs, maxArgs));
                                    break;
                                }

                            case "add_junk_lambda":
                                {
                                    int minArgs = 1;
                                    int maxArgs = 6;

                                    if (tagArgs.Length == 3)
                                    {
                                        maxArgs = minArgs = int.Parse(tagArgs[1]);
                                    }
                                    else if (tagArgs.Length == 4)
                                    {
                                        minArgs = int.Parse(tagArgs[1]);
                                        maxArgs = int.Parse(tagArgs[2]);
                                    }
                                    SafeInsert(cursor, Junk.GenerateLambda(minArgs, maxArgs));
                                    break;
                                }

                            case "enc_string_enable":
                                {
                                    escapeString = true;
                                    break;
                                }

                            case "enc_string_disable":
                                {
                                    escapeString = false;
                                    break;
                                }

                            case "/swap_lines":
                                {
                                    fromStack = GetFromStack("swap_lines");
                                    string str6 = fileData.Substring(fromStack.pos, cursor - fromStack.pos);

                                    string[] newLine = new string[] { Environment.NewLine };
                                    string[] strArrays1 = str6.Split(newLine, StringSplitOptions.None);
                                    string[] strArrays2 = new string[(int)strArrays1.Length - 2];

                                    for (int k = 1; k < (int)strArrays1.Length - 1; k++)
                                    {
                                        strArrays2[k - 1] = strArrays1[k];
                                    }

                                    strArrays2 = RandomStringArrays.RandomizeStrings(strArrays2);
                                    str = string.Concat(Environment.NewLine, string.Join(Environment.NewLine, strArrays2), Environment.NewLine);
                                    SafeRemove(fromStack.pos, fileData.Substring(fromStack.pos, cursor - fromStack.pos).Length);
                                    cursor = fromStack.pos;
                                    SafeInsert(fromStack.pos, str);

                                    break;
                                }
                        }
                    }

                    if (flag)
                    {
                        ParseItem parseItem = new ParseItem(tag, cursor);
                        parseStack.Push(parseItem);
                    }
                    return;
                }
            }

            if (Match(";"))
            {
                int num6 = fileData.IndexOf(Environment.NewLine, cursor + 1);
                if (junkEnabled)
                {
                    cursor = num6 + 1;
                    SafeInsert(cursor, AddCode());
                }
            }

        }

        public void AddJunkCode()
        {
            while (cursor < fileData.Length)
            {
                NextChar();
            }
        }

        protected void NextChar()
        {
            CheckAll();
            BaseFile baseFile = this;
            baseFile.cursor = baseFile.cursor + 1;
        }

        protected bool Match(string str)
        {
            for (int i = 0; i < str.Length; i++)
            {
                if (fileData[cursor + i] != str[i])
                {
                    return false;
                }
            }
            return true;
        }

        protected bool MatchWildCard(string str)
        {
            int num = fileData.IndexOf('\n', cursor);
            if (num == -1)
            {
                return false;
            }
            string str1 = fileData.Substring(cursor, num - cursor);
            if ((new Regex(string.Concat("^", Regex.Escape(str).Replace("\\*", ".*").Replace("\\?", "."), "$"))).IsMatch(str1))
            {
                return true;
            }
            return false;
        }

        protected ParseItem GetFromStack(string shouldBe)
        {
            ParseItem parseItem = parseStack.Pop();
            if (parseItem.tag.ToLower() != shouldBe)
            {
                Clipboard.SetText(fileData);
                string[] strArrays = new string[] { "Starting tag ", parseItem.tag, " does not match ", shouldBe, " at ", cursor.ToString(), Environment.NewLine, "File data has been copied to the clipboard!" };
                MessageBox.Show(string.Concat(strArrays), "Parse error!");
                Application.Exit();
            }
            return parseItem;
        }

        protected bool IsTag(string s)
        {
            string str = s;
            string str1 = str;
            if (str != null)
            {
                switch (str1)
                {
                    case "junk_enable":             // Enable adding junk
                    case "add_junk":                // Add Junk with given lines
                    case "add_junk_datamembers":    // Add a junk datamember in a class
                    case "add_safe_junk":           // Add junk that doesn't give dynamic memory (used in headers and such)
                    case "junk_disable":            // Disable adding junk
                    case "junk_enable_declares":    // Add junk declares
                    case "add_junk_function":       // Add a junk function
                    case "add_junk_lambda":         // Add a junk lamdba
                    case "enc_string_enable":       // Start encrypting any string
                    case "enc_string_disable":      // Stop encrypting any string
                    case "swap_lines":              // Start swapping lines
                    case "/swap_lines":             // Stop swapping lines
                    case "swap_blocks":             // Start swapping blocks
                    case "/swap_blocks":            // Stop swapping blocks
                    case "block":                   // Start a block
                    case "/block":                  // End a block
                        {
                            return true;
                        }
                }
            }
            return false;
        }

        protected void SafeRemove(int start, int length)
        {
            fileData = fileData.Remove(start, length);
        }

        protected void SafeInsert(int start, string toInsert)
        {
            fileData = fileData.Insert(start, toInsert);
            BaseFile length = this;
            length.cursor = length.cursor + toInsert.Length;

        }

        protected string ToLiteral(string input)
        {
            CSharpCodeProvider cSharpCodeProvider = new CSharpCodeProvider();
            CompilerParameters compilerParameter = new CompilerParameters()
            {
                GenerateExecutable = false,
                GenerateInMemory = true
            };

            string[] strArrays = new string[] { string.Concat("\r\n            namespace tmp\r\n            {\r\n                public class tmpClass\r\n                {\r\n                    public static string GetValue()\r\n                    {\r\n                            return \"", input, "\";\r\n                    }\r\n                }\r\n            }") };
            Assembly compiledAssembly = cSharpCodeProvider.CompileAssemblyFromSource(compilerParameter, strArrays).CompiledAssembly;
            MethodInfo method = compiledAssembly.GetType("tmp.tmpClass").GetMethod("GetValue");
            return method.Invoke(null, null) as string;
        }
    }
}
