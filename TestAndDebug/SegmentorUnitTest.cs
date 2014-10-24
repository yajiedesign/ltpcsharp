using System;
using System.Collections.Generic;

namespace TestAndDebug
{
 
    public class SegmentorUnitTest
    {

        public void SegmentTestMethod()
        {
            ltpcsharp.Segmentor segmentor = new ltpcsharp.Segmentor(@"..\..\..\..\ltp_data\cws.model");

            List<String> outlist = null;
            segmentor.Segment("爱上一匹野马，可我的家里没有草原。", out outlist);

            segmentor = null;
            GC.Collect();
        }
    }
}
