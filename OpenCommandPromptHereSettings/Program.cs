using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Diagnostics;

namespace OpenCommandPromptHereSettings
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new frmSettings());
        }

        public static void InitRegistryLuminati()
        {
            if (RegistryHelper2.GetKeyValue("Open Command Prompt Here","FirstTimeRun")!=bool.FalseString)                
            {
                System.Diagnostics.Process proc2 = new Process();
                proc2.StartInfo.Arguments = "-clearchoice \"Open Command Prompt Here\"";
                proc2.StartInfo.FileName = System.IO.Path.Combine(Application.StartupPath, "LuminatiHelper.exe");
                proc2.Start();

                RegistryHelper2.SetKeyValue("Open Command Prompt Here", "FirstTimeRun", bool.FalseString);
            }

            RegistryHelper2.SetKeyValue("Open Command Prompt Here", "LuminatiChoice", "NOTSET");

            System.Diagnostics.Process proc = new Process();
            proc.StartInfo.Arguments = "-setup \"win_opencommandprompthere.4dotssoftware.com\" \"Open Command Prompt Here\" \"" + System.IO.Path.Combine(Application.StartupPath, "open-command-prompt-here-150.png") + "\"";
            proc.StartInfo.FileName = System.IO.Path.Combine(Application.StartupPath, "LuminatiHelper.exe");
            proc.Start();
        }
    }
}
