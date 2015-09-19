using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.IO;
using System.Diagnostics;
using MazzCrypt.JunkCode;
using MazzCrypt.Encryption;

namespace MazzCrypt
{
    public partial class Form1 : Form
    {
        string fileName, safeFileName;
        bool isCompiling;
        Thread compileThread;

        string outEXEName = "Mazz.exe";

        public Form1()
        {
            InitializeComponent();
        }

        public void CreateFunction()
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
            int paramNum = rnd.Next(1, 10);
            for (int i = 0; i < paramNum; i++)
            {
                function += string.Concat(types[rnd.Next(0, types.Length)], " ");
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
            int decNum = rnd.Next(1, 50);

            for (int i = 0; i < decNum; i++)
            {
                JunkCode.JunkType randType = JunkCode.Junk.GetRandomType();
                function += string.Concat(randType.Definition() + ";", Environment.NewLine);
                junktypes.Add(randType);
            }

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

            textBox1.Text = function;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        public TreeView GetTreeView()
        {
            return treeViewHack;
        }

        delegate void SetProgressBarCallback(int cs, int ms);
        private void SetProgressBar(int cs, int ms)
        {
            if (InvokeRequired)
            {
                SetProgressBarCallback d = new SetProgressBarCallback(SetProgressBar);
                this.Invoke(d, new object[] { cs, ms });
            }
            else
            {
                progressBar1.Value = (int)((float)cs / (float)ms * 100f);
            }
        }

        delegate void SetStatusCallback(string text);
        private void SetStatus(string text)
        {
            if (InvokeRequired)
            {
                SetStatusCallback d = new SetStatusCallback(SetStatus);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                lblStatus.Text = "";
                lblStatus.Text = "Status: " + text;
            }
        }

        private void Compile(object data)
        {
            int progress = 4;

            string outputName = Junk.RandomString(25) + ".exe";

            SetProgressBar(0, progress);
            SetStatus("Unzipping..");
            HackFile hackFile = (HackFile)data;
            string directory = string.Concat(Path.GetFileNameWithoutExtension(fileName), "/");
            char encKey = Junk.RandomString(1).ToCharArray()[0];
            hackFile.Unzip(directory, encKey);
            StringEnc.SetKey(encKey);

            SetProgressBar(1, progress);
            SetStatus("Randomizing and Encrypting..");

            string str1 = string.Concat(Path.GetFileNameWithoutExtension(fileName), "_R/");
            hackFile.RandomizeAllFiles(directory, str1);
            SetProgressBar(2, progress);

            SetStatus("Compiling..");
            string str2 = string.Concat(Path.GetDirectoryName(txtCompilerPath.Text), "\\");

            ProcessStartInfo processStartInfo = new ProcessStartInfo()
            {
                FileName = "cmd.exe"
            };

            string str3 = "/C ";
            str3 = string.Concat(str3, "cd ", str1, "&");
            str3 = string.Concat(str3, "\"", str2, "vcvars32.bat\"&");
            string str4 = str3;
            string[] strArrays = new string[] { str4, "\"", str2, "cl.exe\" ", txtCompilerArgs.Text };

            str3 = string.Concat(strArrays);
            if (!chkboxDebug.Checked)
            {
                processStartInfo.UseShellExecute = false;
                processStartInfo.RedirectStandardInput = true;
                processStartInfo.WindowStyle = ProcessWindowStyle.Hidden;
                processStartInfo.CreateNoWindow = true;
            }
            else
            {
                str3 = string.Concat(str3, "&pause");
            }

            processStartInfo.Arguments = str3;
            Process.Start(processStartInfo).WaitForExit();
            SetProgressBar(3, progress);
            SetStatus("Finishing up..");

            if (File.Exists(outputName))
            {
                File.Delete(outputName);
            }

            bool flag = false;
            if (File.Exists(string.Concat(str1, outEXEName)))
            {
                File.Move(string.Concat(str1, outEXEName), outputName);
                flag = true;
            }

            if (chkBoxDeleteFolders.Checked)
            {
                Directory.Delete(directory, true);
                Directory.Delete(str1, true);
            }

            SetProgressBar(4, progress);
            SetStatus("Done with " + safeFileName);

            if (!flag)
            {
                if (chkBox_PromptMsg.Checked)
                    MessageBox.Show("Something went wrong when compiling the randomized source!", "Error");
            }
            else
            {
                if(chkBox_PromptMsg.Checked)
                    MessageBox.Show(string.Concat("File saved as: ", outputName), "Compiling has been completed.");

                if (num_Copies.Value == 1) 
                {
                    if (chkBox_PromptMsg.Checked)
                    {
                        DialogResult msgBox = MessageBox.Show("Would you like to run this right now?", "Question", MessageBoxButtons.YesNo);

                        if (msgBox == System.Windows.Forms.DialogResult.Yes)
                        {
                            processStartInfo = new ProcessStartInfo()
                            {
                                FileName = outputName
                            };

                            Process.Start(processStartInfo).WaitForExit();
                        }
                    }
                }
            }

            isCompiling = false;

        }

        private void btnCompile_Click(object sender, EventArgs e)
        {
            HackFile hackFile = new HackFile(fileName);
            if (!hackFile.CheckFile())
            {
                MessageBox.Show("The current .zip isn't valid!", "ZIP isn't valid");
                return;
            }
            if (isCompiling)
            {
                MessageBox.Show("Still compiling, please wait.", "Still Compiling!");
                return;
            }

            isCompiling = true;

            for (int i = 0; (int)i < num_Copies.Value; i++)
            {
                compileThread = new Thread(new ParameterizedThreadStart(this.Compile));
                compileThread.Start(hackFile);
            }
        }

        private void btnOpenZip_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();

            if (ofd.ShowDialog() != System.Windows.Forms.DialogResult.OK)
                return;

            fileName = ofd.FileName;
            safeFileName = ofd.SafeFileName;

            SetStatus("Loaded " + ofd.SafeFileName);
        }

        private void btnOpenCompiler_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();

            if (ofd.ShowDialog() != System.Windows.Forms.DialogResult.OK)
                return;

            txtCompilerPath.Text = ofd.FileName;
        }

        private void btn_generateDecryptClass_Click(object sender, EventArgs e)
        {
            StringEnc.SetKey(textBox2.Text[0]);
            int[] result = StringEnc.Encrypt(textBox3.Text);
            textBox1.Text = "";
            textBox1.Text = result.Count().ToString() + ", ";
            for (int i = 0; i < result.Count(); i++)
            {
                if (i == result.Count() - 1)
                    textBox1.Text += result[i].ToString();
                else
                    textBox1.Text += result[i].ToString() + ", ";
            }
        }

        private void btnAbout_Click(object sender, EventArgs e)
        {
            MazzCrypt.Forms.About a = new MazzCrypt.Forms.About();
            a.Show();
        }
    }
}
