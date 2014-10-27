using LtpCsharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestAndDebug
{
    class Program
    {
        static void Main(string[] args)
        {

            List<String> words = null;
            List<String> postags = null;
            List<String> rectags = null;
            List<int> heads = null;
            List<string> deprels = null;
            Segmentor segmentor = new Segmentor(@"..\..\..\ltp_data\cws.model");

            segmentor.Segment("爱上一匹野马，可我的家里没有草原。", out words);
            //Postagger postagger = new Postagger(@"..\..\..\..\ltp_data\pos.model");
            //postagger.Postag(words, out postags);
            //Recognizer recognizer = new Recognizer(@"..\..\..\..\ltp_data\ner.model");
            //recognizer.Postag(words, postags, out rectags);
            //Parser parser = new Parser(@"..\..\..\..\ltp_data\parser.model");
            //parser.Parse(words, postags, out heads, out deprels);

        }
    }
}
