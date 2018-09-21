using System;
using System.Collections.Generic;
using System.Threading;
using System.Diagnostics;
namespace ProcessMonitoring
{
    class Program
    {
        static void Table()
        {
            Process[] prc = Process.GetProcesses();
            var performs = new List<PerformanceCounter>();
            int i = 0;
            foreach (Process process in prc)
            {
                var perform = new PerformanceCounter("Process", "% Processor Time", process.ProcessName);
                perform.NextValue();
                performs.Add(perform);
            }

            Console.WriteLine("╔═══════╦╦═══════╦╦═════════════════════════════════════════════════╦╦═════════════╦╦═════════╗");
            Console.WriteLine("║  PID  ║║  UID  ║║                      NAME                       ║║     CPU     ║║   RAM   ║");
            Console.WriteLine("╠═══════╣╠═══════╣╠═════════════════════════════════════════════════╣╠═════════════╣╠═════════╣");
            foreach (var count in performs)
            {
                Console.WriteLine($"║{ prc[i].Id,-7}║║{ prc[i].SessionId,-7}║║{prc[i].ProcessName,-49}║║{count.NextValue() / Environment.ProcessorCount,-13}║║{ prc[i].WorkingSet64 / 1024d,-9}║");
                i++;
            }
            Console.Write("╚═══════╩╩═══════╩╩═════════════════════════════════════════════════╩╩═════════════╩╩═════════╝\nRefresh in 80 sec: ");

        }
        static void LoadingBar(double x)
        {
            for (int i = 0; i < 50; i++)
            {
                if (i < (x / 2)) Console.Write("█");
                else Console.Write("|");
            }
            Console.WriteLine();
        }
        static void CpuRamShow(PerformanceCounter CPU, PerformanceCounter RAM)
        {
            int posX = Console.CursorLeft, posY = Console.CursorTop;
            Console.WriteLine("\n");

            var CPUBar = CPU.NextValue();
            Console.Write("{0,25}", "CPU: ");
            Console.Write("{0:0.0}", CPUBar);
            Console.WriteLine(" %");

            LoadingBar(CPUBar);
            var RAMBar = RAM.NextValue();
            Console.Write("{0,25}", "RAM: ");
            Console.Write("{0:0.0}", RAMBar);
            Console.WriteLine(" %");
            LoadingBar(RAMBar);

            Thread.Sleep(1000);
            Console.SetCursorPosition(posX, posY);
        }




        static void CpuRam()
        {
            PerformanceCounter CPU = new PerformanceCounter("Processor", "% Processor Time", "_Total");
            PerformanceCounter RAM = new PerformanceCounter("Memory", "% Committed Bytes In Use");
            while (true)
            {
                CpuRamShow(CPU, RAM);
            }
        }
        static void SystemTasks()
        {
            while (true)
            {
                Table();
                for (int j = 0; j < 80; j++)
                {
                    Console.Write("█");
                    Thread.Sleep(1000);
                    if (j > 80)
                        break;
                }
                Console.Clear();
            }

        }
        static void Both()
        {
            while (true)
            {
                PerformanceCounter RAM = new PerformanceCounter("Memory", "% Committed Bytes In Use");
                PerformanceCounter CPU = new PerformanceCounter("Processor", "% Processor Time", "_Total");
                Table();
                for (int j = 0; j < 80; j++)
                {
                    Console.Write("█");
                    CpuRamShow(CPU, RAM);
                    if (j > 80)
                        break;
                }
                Console.Clear();
            }

        }
       
       

        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("-----------------What to dysplay------------------");
                Console.WriteLine("\"1\": - CPU & RAM   \"2\" - Tasks Table   \"3\" - Both");
                string x = Console.ReadLine();
                switch (x)
                {
                    case "1":
                        Console.Clear();
                        CpuRam();
                        break;
                    case "2":
                        Console.Clear();
                        SystemTasks();
                        break;
                    case "3":
                        Console.Clear();
                        Both();
                        break;
                }
                Console.Clear();
            }
        }
    }
}
