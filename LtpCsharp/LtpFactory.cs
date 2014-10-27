using LtpCsharp.Common;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace LtpCsharp
{
    static class LtpFactory
    {
        static ILtpFactory factory;
        static LtpFactory()
        {
            string fileName = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, string.Format("{0}\\ltpcsharp.native.dll", (IntPtr.Size == 4) ? "x86" : "x64"));
            Assembly dll = Assembly.LoadFile(fileName);
            factory = (LtpCsharp.Common.ILtpFactory)dll.CreateInstance("ltpcsharp_native.LtpFactory");
            if (factory == null)
            {
                throw new Exception("ltpcsharp.native.dll 加载错误");
            }
        }

        public static ILtpFactory GetLtpFactory()
        {
            return factory;
        }

    }
}
