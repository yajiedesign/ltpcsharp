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
        private Common.ISegmentor native = null;
        public Segmentor(string path)
        {
            native = LtpFactory.GetLtpFactory().CreateSegmentor(path);
        }
        public Segmentor(string path, string lexicon_file)
        {
            native = LtpFactory.GetLtpFactory().CreateSegmentor(path, lexicon_file);
        }
        public int Segment(string line, out List<string> words)
        {
            return native.Segment(line, out words);
        }
    }
}
