using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using ICSharpCode.SharpZipLib.Zip;
using MazzCrypt.Randomization;
using MazzCrypt.Properties;

namespace MazzCrypt
{
    class HackFile
    {
        private string fileName;
        private ZipFile zipFile;

        public HackFile(string filename)
        {
            fileName = filename;
            zipFile = null;
        }

        public bool CheckFile()
        {
            if(!File.Exists(fileName))
            {
                MessageBox.Show("File doesn't exist");
                return false;
            }

            zipFile = new ZipFile(File.OpenRead(fileName));

            if(zipFile.GetEntry("src/") == null)
            {
                MessageBox.Show("src folder doesn't exist in this .zip");
                zipFile.Close();
                return false;
            }

            zipFile.Close();
            return true;
        }

        public string GetFileName()
        {
            return fileName;
        }

        public void RandomizeAllFiles(string directory, string outDir)
        {
            // Every .h
            foreach (string str in Directory.EnumerateFiles(string.Concat(directory, "src/"), "*.h", SearchOption.AllDirectories))
            {
                string str1 = str.Replace(string.Concat(directory, "src/"), "");
                Directory.CreateDirectory(string.Concat(outDir, Path.GetDirectoryName(str1)));
                HeaderFile headerFile = new HeaderFile(str);
                headerFile.AddJunkCode();
                File.WriteAllText(string.Concat(outDir, str1), headerFile.GetData());
            }

            // Every .cpp
            foreach (string str2 in Directory.EnumerateFiles(string.Concat(directory, "src/"), "*.cpp", SearchOption.AllDirectories))
            {
                string str3 = str2.Replace(string.Concat(directory, "src/"), "");
                Directory.CreateDirectory(string.Concat(outDir, Path.GetDirectoryName(str3)));
                CppFile cppFile = new CppFile(str2);
                cppFile.AddJunkCode();
                File.WriteAllText(string.Concat(outDir, str3), cppFile.GetData());
            }
        }

        public void Unzip(string dir, char encryptionKey)
        {
            if (!Directory.Exists(dir))
            {
                Directory.CreateDirectory(dir);
            }

            (new FastZip()).ExtractZip(fileName, dir, null);
            File.WriteAllText(string.Concat(dir, "/src/Decrypt.h"), Resources.DecryptHeader.Replace("%ENC_KEY%", encryptionKey.ToString()));
            File.WriteAllText(string.Concat(dir, "/src/Decrypt.cpp"), Resources.DecryptSource);
        }
    }
}
