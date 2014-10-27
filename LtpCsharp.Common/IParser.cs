using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp.Common
{
    public interface IParser
    {
         int Parse(List<string> words, List<string> postags, out List<int> heads, out List<string> deprels);
    }
}
