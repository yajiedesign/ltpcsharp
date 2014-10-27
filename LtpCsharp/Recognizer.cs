using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp
{
 public   class Recognizer
    {
        private Common.IRecognizer native = null;
        private string p;
        public Recognizer(string path)
        {
            native = LtpFactory.GetLtpFactory().CreateRecognizer(path);
        }
        public int Recognize(List<string> words, List<string> postags, out List<string> tags)
        {
            return native.Recognize(words, postags, out tags);
        }
    }
}
