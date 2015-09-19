using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MazzCrypt.JunkCode
{
    class Junk
    {
        public static Random random;
        public static List<string> alreadyUsedVariables;
        public static List<string> alreadyUsedFunctions;

        static Junk()
        {
            Guid guid = Guid.NewGuid();
            random = new Random(guid.GetHashCode());
            alreadyUsedVariables = new List<string>();
            alreadyUsedFunctions = new List<string>();
        }

        Junk()
        {
        }

        public static string GenerateCode(int minPossibleLines = 5, int maxPossibleLines = 10)
        {
            string returnStr = "";

            int numOfLines = random.Next(minPossibleLines, maxPossibleLines);
            List<JunkInteger> junkInts = new List<JunkInteger>();

            for (int i = 0; i < numOfLines; i++)
            {
                if (junkInts.Count == 0 || random.Next(0, 3) != 0)
                {
                    JunkType randomType = GetRandomType();

                    while (randomType is JunkPointer)
                    {
                        randomType = GetRandomType();
                    }

                    if (randomType is JunkInteger)
                        junkInts.Add((JunkInteger)randomType);

                    returnStr = string.Concat(returnStr, randomType.Definition());
                }
                else
                {
                    int count = junkInts.Count;
                    JunkInteger item = junkInts[random.Next(count)];
                    if (random.Next(0, 2) == 0)
                    {
                        item = new JunkInteger();
                        junkInts.Add(item);
                        returnStr = string.Concat(returnStr, item.Declaration(), " ");
                    }

                    JunkInteger junkInt = junkInts[random.Next(count)];
                    JunkInteger item1 = junkInts[random.Next(count)];
                    returnStr = string.Concat(returnStr, item.GetName(), " = ", junkInt.GetName());
                    //returnStr = (random.Next(0, 2) != 0 ? string.Concat(returnStr, " - ") : string.Concat(returnStr, " + "));
                    switch (random.Next(0, 3))
                    {
                        case 0:
                            {
                                returnStr = string.Concat(returnStr, " - ");
                            }
                            break;
                        case 1:
                            {
                                returnStr = string.Concat(returnStr, " + ");
                            }
                            break;
                        case 2:
                            {
                                returnStr = string.Concat(returnStr, " * ");
                            }
                            break;
                    }
                    returnStr = string.Concat(returnStr, item1.GetName());
                }

                returnStr = string.Concat(returnStr, ";", Environment.NewLine);
            }

            return returnStr;
        }

        public static string GenerateDeclares(int minPossibleLines, int maxPossibleLines, bool dynamicMemory)
        {
            string retStr = "";
            int numOfLines = random.Next(minPossibleLines, maxPossibleLines);

            for (int i = 0; i < numOfLines; i++)
            {
                JunkType randomType = GetRandomType();

                if (!dynamicMemory)
                {
                    while (randomType is JunkPointer)
                    {
                        randomType = GetRandomType();
                    }
                }

                retStr = string.Concat(retStr, randomType.Definition());
                retStr = string.Concat(retStr, ";", Environment.NewLine);
            }

            return retStr;
        }

        public static string GenerateFunctions(int minParams = 1, int maxParams = 6)
        {
            // Test to create random inline functions
            List<JunkCode.JunkType> junktypes = new List<JunkCode.JunkType>();
            string function = "";
            string[] types = 
            { 
                "float", "int", "bool", "char*", "char", "DWORD", "void",
            };
            Random rnd = new Random();

            string returnType = types[rnd.Next(0, types.Length)];
            string funcName = JunkCode.Junk.RandomString();

            // Create the returntype and function name
            function += string.Concat(returnType, " "); // float 
            function += string.Concat(funcName, "("); // float RandomName(

            // Create the parameters
            int paramNum = rnd.Next(minParams, maxParams);
            for (int i = 0; i < paramNum; i++)
            {
                string paramType = types[rnd.Next(0, types.Length)];
                while (paramType == "void")
                {
                    paramType = types[rnd.Next(0, types.Length)];
                }

                function += string.Concat(paramType, " ");
                function += JunkCode.Junk.RandomString();
                if (i != paramNum - 1)
                {
                    function += ", ";
                    continue;
                }
                else
                {
                    function += string.Concat(") ", Environment.NewLine);
                    break;
                }
            }

            // Open brace
            function += string.Concat("{", Environment.NewLine);

            // Make declarations for lawls
            int decNum = rnd.Next(1, 30);

            for (int i = 0; i < decNum; i++)
            {
                JunkCode.JunkType randType = JunkCode.Junk.GetRandomType();
                function += string.Concat(randType.Definition() + ";", Environment.NewLine);
                junktypes.Add(randType);
            }

            // TODO: Create fake for/do-while/while loops

            // Check if memory needs to be deleted
            for (int i = 0; i < junktypes.Count; i++)
            {
                if (junktypes[i] is JunkCode.JunkPointer)
                {
                    JunkCode.JunkPointer j = (JunkCode.JunkPointer)junktypes[i];

                    if (j.IsDeleted() != true)
                    {
                        function += j.Cleanup() + ";" + Environment.NewLine;
                    }
                }
            }

            // Return out
            switch (returnType)
            {
                case "int":
                case "DWORD":
                    {
                        JunkCode.JunkInteger j = new JunkCode.JunkInteger();
                        function += "return " + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "bool":
                    {
                        JunkCode.JunkBool j = new JunkCode.JunkBool();
                        function += "return " + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "char*":
                    {
                        JunkCode.JunkString j = new JunkCode.JunkString();
                        function += "return " + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "float":
                    {
                        JunkCode.JunkFloat j = new JunkCode.JunkFloat();
                        function += "return " + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "char":
                    {
                        JunkCode.JunkCharacter j = new JunkCode.JunkCharacter();
                        function += "return" + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "void":
                    {
                        function += "return;" + Environment.NewLine;
                    }
                    break;
            }


            // Close brace
            function += string.Concat("}", Environment.NewLine);

            return function;
        }

        public static string GenerateLambda(int minParams = 1, int maxParams = 6)
        {
            // Syntax: 
            //auto varName = [](type varName, type varName) -> returnType 
            //{ 
            //  code(); 
            //};

            List<JunkCode.JunkType> junktypes = new List<JunkCode.JunkType>();
            string function = "";
            string[] types = 
            { 
                "float", "int", "bool", "char*", "char", "DWORD", "void",
            };
            Random rnd = new Random();

            string returnType = types[rnd.Next(0, types.Length)];
            string funcName = JunkCode.Junk.RandomString();

            function = "auto " + funcName;
            function += "= [](";
            
            // All params
            int paramNum = rnd.Next(minParams, maxParams);
            for (int i = 0; i < paramNum; i++)
            {
                string paramType = types[rnd.Next(0, types.Length)];
                while (paramType == "void")
                {
                    paramType = types[rnd.Next(0, types.Length)];
                }

                function += string.Concat(paramType, " ");
                function += JunkCode.Junk.RandomString();
                if (i != paramNum - 1)
                {
                    function += ", ";
                    continue;
                }
                else
                {
                    function += ") -> ";
                    break;
                }
            }

            function += returnType;
            function += string.Concat("{", Environment.NewLine);

            // Make declarations for lawls
            int decNum = rnd.Next(1, 30);

            for (int i = 0; i < decNum; i++)
            {
                JunkCode.JunkType randType = JunkCode.Junk.GetRandomType();
                function += string.Concat(randType.Definition() + ";", Environment.NewLine);
                junktypes.Add(randType);
            }

            // TODO: Create fake for/do-while/while loops

            // Check if memory needs to be deleted
            for (int i = 0; i < junktypes.Count; i++)
            {
                if (junktypes[i] is JunkCode.JunkPointer)
                {
                    JunkCode.JunkPointer j = (JunkCode.JunkPointer)junktypes[i];

                    if (j.IsDeleted() != true)
                    {
                        function += j.Cleanup() + ";" + Environment.NewLine;
                    }
                }
            }

            // Return out
            switch (returnType)
            {
                case "int":
                case "DWORD":
                    {
                        JunkCode.JunkInteger j = new JunkCode.JunkInteger();
                        function += "return " + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "bool":
                    {
                        JunkCode.JunkBool j = new JunkCode.JunkBool();
                        function += "return " + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "char*":
                    {
                        JunkCode.JunkString j = new JunkCode.JunkString();
                        function += "return " + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "float":
                    {
                        JunkCode.JunkFloat j = new JunkCode.JunkFloat();
                        function += "return " + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "char":
                    {
                        JunkCode.JunkCharacter j = new JunkCode.JunkCharacter();
                        function += "return" + j.Value() + ";" + Environment.NewLine;
                    }
                    break;

                case "void":
                    {
                        function += "return;" + Environment.NewLine;
                    }
                    break;
            }

            // Close brace
            function += string.Concat("};", Environment.NewLine);

            return function;
        }

        public static JunkType GetRandomType()
        {
            switch (random.Next(0, 6))
            {
                case 0:
                    {
                        return new JunkInteger();
                    }
                case 1:
                    {
                        return new JunkCharacter();
                    }
                case 2:
                    {
                        return new JunkString();
                    }
                case 3:
                    {
                        return new JunkFloat();
                    }
                case 4:
                    {
                        return new JunkBool();
                    }
                case 5:
                    {
                        return new JunkPointer();
                    }
            }

            return new JunkInteger();
        }

        public static string GetUnusedVariable()
        {
            string str = RandomString(10);
            while (alreadyUsedVariables.Exists((string x) => x == str))
            {
                str = RandomString(10);
            }
            return str;
        }

        public static string GetUnusedFunction()
        {
            string str = GenerateFunctions();
            while (alreadyUsedFunctions.Exists((string x) => x == str))
            {
                str = GenerateFunctions();
            }
            return str;
        }

        public static string RandomString(int length = 10)
        {
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < length; i++)
            {
                char chr = Convert.ToChar(Convert.ToInt32(Math.Floor(26 * random.NextDouble() + 65)));
                stringBuilder.Append(chr);
            }
            return stringBuilder.ToString();
        }

        public static double RandomFloat(double min, double max)
        {
            return random.NextDouble() * (max - min) + min;
        }
    }
}
