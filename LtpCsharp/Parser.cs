using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp
{
    public class Parser
    {
        private Common.IParser native = null;
        public Parser(string path)
        {
            native = LtpFactory.GetLtpFactory().CreateParser(path);
        }
        public int Parse(List<string> words, List<string> postags, out List<int> heads, out List<string> deprels)
        {
            return native.Parse(words, postags, out heads, out deprels);
        }
    }
}
