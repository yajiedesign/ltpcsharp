using LtpCsharp.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp
{
    public class Postagger 
    {
        IPostagger native = null;

        public Postagger(string path)
        {
            native = LtpFactory.GetLtpFactory().CreatePostagger(path);
        }
        public Postagger(string path, string lexicon_file)
        {
            native = LtpFactory.GetLtpFactory().CreatePostagger(path, lexicon_file);
        }

        public int Postag(List<string> words, out List<string> tags)
        {
            return native.Postag(words, out tags);
        }
    }
}
