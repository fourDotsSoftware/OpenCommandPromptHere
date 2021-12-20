using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Diagnostics;

namespace OpenCommandPromptHere
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            ExceptionsHelper.AddUnhandledExceptionHandlers();

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            /*
            InitRegistryLuminati();

            while (true)
            {
                string regval = RegistryHelper2.GetKeyValue("Open Command Prompt Here", "LuminatiChoice");

                if (regval == "NOTSET")
                {
                    System.Threading.Thread.Sleep(1000);
                }
                else if (regval == "ACCEPT")
                {
                    break;
                }
                else
                {
                    Environment.Exit(0);

                    return;
                }

                Application.DoEvents();
            }           
            */

            DialogResult dres=Module.ShowQuestionDialog("Open Command Prompt with Administrator Rights ?", "Open with Admin Rights ?");

            ProcessStartInfo pr = new ProcessStartInfo(System.Environment.GetFolderPath(Environment.SpecialFolder.System) + "\\cmd.exe");

            //pr.Arguments = "  /K \"cd /d ";
            //pr.Arguments = " /s /k \"pushd %L";
            pr.Arguments = "/k \"pushd ";
            
            string dir="";

            if (System.IO.Directory.Exists(args[0]))
            {
                dir=System.IO.Path.GetFullPath(args[0]);
                pr.WorkingDirectory=args[0];
                //pr.Arguments = " /c start " + args[0] + pr.Arguments;
                pr.Arguments += dir;
            }
            else
            {
                pr.WorkingDirectory = System.IO.Path.GetDirectoryName(args[0]);
                //pr.Arguments = " /c start " + System.IO.Path.GetDirectoryName(args[0]) + pr.Arguments;
                

                dir=System.IO.Path.GetFullPath(System.IO.Path.GetDirectoryName(args[0]));

                pr.Arguments += dir;
            }

            pr.Arguments += "\"";

            if (dres==DialogResult.Yes)
            {
                pr.Verb = "runas";                
                pr.UseShellExecute = true;
            }

            Process p = new Process();
            p.StartInfo = pr;
            p.Start();                  
            

            
        }

        /*
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
        }*/
    }
}