using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AsyncTuts
{
    class Program
    {
        static void Main(string[] args)
        {
            Task.Run(() => DoSomthingAsync());
            Console.ReadLine();
        }


        private static async Task DoSomthingAsync()
        {
            var val = 13;
            Console.WriteLine(val);

            await Task.Delay(TimeSpan.FromSeconds(2)).ConfigureAwait(false);
            Console.WriteLine(val);

            val *= 3;
            Console.WriteLine(val);

            await Task.Delay(TimeSpan.FromSeconds(1)).ConfigureAwait(false);
            Console.WriteLine(val);

            Trace.WriteLine(val.ToString());
        }
    }
}
