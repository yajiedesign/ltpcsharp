using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp.Common
{
    public interface IPostagger
    {
         int Postag(List<string> words, out List<string> tags);
    }
}
