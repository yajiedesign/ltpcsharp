using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp.Common
{
   public  interface ILtpFactory
    {
        ISegmentor CreateSegmentor(string path);
        ISegmentor CreateSegmentor(string path, string lexicon_file);
        IPostagger CreatePostagger(string path);
        IPostagger CreatePostagger(string path, string lexicon_file);
        IRecognizer CreateRecognizer(string path);
        IParser CreateParser(string path);
        ISplitsnt CreateSplitsnt();
    }
}
