using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp.Common
{
    public interface ISegmentor
    {
        int Segment(string line, out List<string> words);
    }
}
