using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp.Common
{
    public interface ISplitsnt
    {
        int SplitSentence(string paragraph, out List<string> sentences);
    }
}
