namespace MazzCrypt
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.msMain = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnOpenZip = new System.Windows.Forms.ToolStripMenuItem();
            this.btnAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.label1 = new System.Windows.Forms.Label();
            this.treeViewHack = new System.Windows.Forms.TreeView();
            this.label2 = new System.Windows.Forms.Label();
            this.chkboxDebug = new System.Windows.Forms.CheckBox();
            this.gbOptions = new System.Windows.Forms.GroupBox();
            this.chkBox_PromptMsg = new System.Windows.Forms.CheckBox();
            this.num_Copies = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.chkBoxDeleteFolders = new System.Windows.Forms.CheckBox();
            this.btnCompile = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.txtCompilerPath = new System.Windows.Forms.TextBox();
            this.btnOpenCompiler = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.txtCompilerArgs = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.lblStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.btn_generateDecryptClass = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.msMain.SuspendLayout();
            this.gbOptions.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_Copies)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // msMain
            // 
            this.msMain.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.msMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.btnAbout});
            this.msMain.Location = new System.Drawing.Point(0, 0);
            this.msMain.Name = "msMain";
            this.msMain.Size = new System.Drawing.Size(419, 28);
            this.msMain.TabIndex = 0;
            this.msMain.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnOpenZip});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(44, 24);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // btnOpenZip
            // 
            this.btnOpenZip.Name = "btnOpenZip";
            this.btnOpenZip.Size = new System.Drawing.Size(175, 24);
            this.btnOpenZip.Text = "Open .zip";
            this.btnOpenZip.Click += new System.EventHandler(this.btnOpenZip_Click);
            // 
            // btnAbout
            // 
            this.btnAbout.Name = "btnAbout";
            this.btnAbout.Size = new System.Drawing.Size(62, 24);
            this.btnAbout.Text = "About";
            this.btnAbout.Click += new System.EventHandler(this.btnAbout_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 45);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 17);
            this.label1.TabIndex = 1;
            // 
            // treeViewHack
            // 
            this.treeViewHack.Location = new System.Drawing.Point(12, 45);
            this.treeViewHack.Name = "treeViewHack";
            this.treeViewHack.Size = new System.Drawing.Size(400, 219);
            this.treeViewHack.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(150, 28);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(100, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Hack Hierachy";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // chkboxDebug
            // 
            this.chkboxDebug.AutoSize = true;
            this.chkboxDebug.Checked = true;
            this.chkboxDebug.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkboxDebug.Location = new System.Drawing.Point(6, 21);
            this.chkboxDebug.Name = "chkboxDebug";
            this.chkboxDebug.Size = new System.Drawing.Size(165, 21);
            this.chkboxDebug.TabIndex = 4;
            this.chkboxDebug.Text = "Show compiler output";
            this.chkboxDebug.UseVisualStyleBackColor = true;
            // 
            // gbOptions
            // 
            this.gbOptions.Controls.Add(this.chkBox_PromptMsg);
            this.gbOptions.Controls.Add(this.num_Copies);
            this.gbOptions.Controls.Add(this.label5);
            this.gbOptions.Controls.Add(this.chkBoxDeleteFolders);
            this.gbOptions.Controls.Add(this.chkboxDebug);
            this.gbOptions.Location = new System.Drawing.Point(12, 329);
            this.gbOptions.Name = "gbOptions";
            this.gbOptions.Size = new System.Drawing.Size(400, 102);
            this.gbOptions.TabIndex = 10;
            this.gbOptions.TabStop = false;
            this.gbOptions.Text = "Options";
            // 
            // chkBox_PromptMsg
            // 
            this.chkBox_PromptMsg.AutoSize = true;
            this.chkBox_PromptMsg.Checked = true;
            this.chkBox_PromptMsg.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkBox_PromptMsg.Location = new System.Drawing.Point(6, 48);
            this.chkBox_PromptMsg.Name = "chkBox_PromptMsg";
            this.chkBox_PromptMsg.Size = new System.Drawing.Size(159, 21);
            this.chkBox_PromptMsg.TabIndex = 8;
            this.chkBox_PromptMsg.Text = "Prompt MessageBox";
            this.chkBox_PromptMsg.UseVisualStyleBackColor = true;
            // 
            // num_Copies
            // 
            this.num_Copies.Location = new System.Drawing.Point(137, 74);
            this.num_Copies.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.num_Copies.Name = "num_Copies";
            this.num_Copies.Size = new System.Drawing.Size(120, 22);
            this.num_Copies.TabIndex = 7;
            this.num_Copies.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.num_Copies.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(8, 74);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(123, 17);
            this.label5.TabIndex = 6;
            this.label5.Text = "Number of copies:";
            // 
            // chkBoxDeleteFolders
            // 
            this.chkBoxDeleteFolders.AutoSize = true;
            this.chkBoxDeleteFolders.Checked = true;
            this.chkBoxDeleteFolders.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkBoxDeleteFolders.Location = new System.Drawing.Point(181, 21);
            this.chkBoxDeleteFolders.Name = "chkBoxDeleteFolders";
            this.chkBoxDeleteFolders.Size = new System.Drawing.Size(122, 21);
            this.chkBoxDeleteFolders.TabIndex = 5;
            this.chkBoxDeleteFolders.Text = "Delete Folders";
            this.chkBoxDeleteFolders.UseVisualStyleBackColor = true;
            // 
            // btnCompile
            // 
            this.btnCompile.Location = new System.Drawing.Point(10, 603);
            this.btnCompile.Name = "btnCompile";
            this.btnCompile.Size = new System.Drawing.Size(402, 54);
            this.btnCompile.TabIndex = 11;
            this.btnCompile.Text = "Compile .exe";
            this.btnCompile.UseVisualStyleBackColor = true;
            this.btnCompile.Click += new System.EventHandler(this.btnCompile_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(15, 273);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(100, 17);
            this.label3.TabIndex = 12;
            this.label3.Text = "Compiler Path:";
            // 
            // txtCompilerPath
            // 
            this.txtCompilerPath.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtCompilerPath.Location = new System.Drawing.Point(118, 270);
            this.txtCompilerPath.Name = "txtCompilerPath";
            this.txtCompilerPath.Size = new System.Drawing.Size(240, 21);
            this.txtCompilerPath.TabIndex = 13;
            this.txtCompilerPath.Text = "F:\\Visual Studio 2013\\VC\\bin\\cl.exe";
            // 
            // btnOpenCompiler
            // 
            this.btnOpenCompiler.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnOpenCompiler.Location = new System.Drawing.Point(364, 270);
            this.btnOpenCompiler.Name = "btnOpenCompiler";
            this.btnOpenCompiler.Size = new System.Drawing.Size(45, 23);
            this.btnOpenCompiler.TabIndex = 14;
            this.btnOpenCompiler.Text = "...";
            this.btnOpenCompiler.UseVisualStyleBackColor = true;
            this.btnOpenCompiler.Click += new System.EventHandler(this.btnOpenCompiler_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(15, 301);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(100, 17);
            this.label4.TabIndex = 15;
            this.label4.Text = "Compiler Args:";
            // 
            // txtCompilerArgs
            // 
            this.txtCompilerArgs.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtCompilerArgs.Location = new System.Drawing.Point(118, 298);
            this.txtCompilerArgs.Name = "txtCompilerArgs";
            this.txtCompilerArgs.Size = new System.Drawing.Size(294, 21);
            this.txtCompilerArgs.TabIndex = 16;
            this.txtCompilerArgs.Text = "/EHsc /Od /MT *.cpp kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib a" +
    "dvapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /link /FORCE:MULTIPLE /O" +
    "UT:Mazz.exe";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(10, 493);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox1.Size = new System.Drawing.Size(400, 44);
            this.textBox1.TabIndex = 17;
            this.textBox1.Text = "Encrypted text lol";
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(10, 663);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(400, 37);
            this.progressBar1.TabIndex = 18;
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.lblStatus});
            this.statusStrip1.Location = new System.Drawing.Point(0, 703);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(419, 28);
            this.statusStrip1.TabIndex = 19;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // lblStatus
            // 
            this.lblStatus.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(98, 23);
            this.lblStatus.Text = "Status: Idle.";
            // 
            // btn_generateDecryptClass
            // 
            this.btn_generateDecryptClass.Location = new System.Drawing.Point(10, 543);
            this.btn_generateDecryptClass.Name = "btn_generateDecryptClass";
            this.btn_generateDecryptClass.Size = new System.Drawing.Size(400, 54);
            this.btn_generateDecryptClass.TabIndex = 21;
            this.btn_generateDecryptClass.Text = "Encrypt String with XOR_KEY";
            this.btn_generateDecryptClass.UseVisualStyleBackColor = true;
            this.btn_generateDecryptClass.Click += new System.EventHandler(this.btn_generateDecryptClass_Click);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(13, 465);
            this.textBox2.MaxLength = 1;
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(397, 22);
            this.textBox2.TabIndex = 22;
            this.textBox2.Text = "XOR_KEY";
            this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(13, 437);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(397, 22);
            this.textBox3.TabIndex = 23;
            this.textBox3.Text = "String to Encrypt";
            this.textBox3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(419, 731);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.btn_generateDecryptClass);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.txtCompilerArgs);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.btnOpenCompiler);
            this.Controls.Add(this.txtCompilerPath);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btnCompile);
            this.Controls.Add(this.gbOptions);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.treeViewHack);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.msMain);
            this.MainMenuStrip = this.msMain;
            this.Name = "Form1";
            this.Text = "MazzCrypt - Private Polymorphic Parser";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.msMain.ResumeLayout(false);
            this.msMain.PerformLayout();
            this.gbOptions.ResumeLayout(false);
            this.gbOptions.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_Copies)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip msMain;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem btnOpenZip;
        private System.Windows.Forms.ToolStripMenuItem btnAbout;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TreeView treeViewHack;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox chkboxDebug;
        private System.Windows.Forms.GroupBox gbOptions;
        private System.Windows.Forms.Button btnCompile;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtCompilerPath;
        private System.Windows.Forms.Button btnOpenCompiler;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtCompilerArgs;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel lblStatus;
        private System.Windows.Forms.Button btn_generateDecryptClass;
        private System.Windows.Forms.CheckBox chkBoxDeleteFolders;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.NumericUpDown num_Copies;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.CheckBox chkBox_PromptMsg;
    }
}

