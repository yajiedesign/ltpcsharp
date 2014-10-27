using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp
{
    public class Segmentor
    {

        static Segmentor()
        {
            string fileName = Path.Combine(
                AppDomain.CurrentDomain.BaseDirectory,
                string.Format("{0}\\ltpcsharp.native.dll", (IntPtr.Size == 4) ? "x86" : "x64"));


            Assembly.LoadFile(fileName);
        }

        ltpcsharp_native.Segmentor native = null;
        public Segmentor(string path)
        {
            native = new ltpcsharp_native.Segmentor(path);
        }
        public Segmentor(string path, string lexicon_file)
        {
            native = new ltpcsharp_native.Segmentor(path, lexicon_file);
        }
        public int Segment(string line, out List<string> words)
        {
            return native.Segment(line, out words);
        }
    }
}
