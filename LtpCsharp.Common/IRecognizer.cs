using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp.Common
{
    public interface IRecognizer
    {
         int Recognize(List<string> words, List<string> postags, out List<string> tags);
    }
}
