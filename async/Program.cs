using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Http;

namespace async
{
    class Program
    {
        static void AccessWeb()
        {
            
        }

        async Task<int> AccessWebAsync()
        {
            HttpClient client = new HttpClient();
            Task<string> getStringTask = client.GetStringAsync("http://msdn.microsoft.com");
            string urlcontent = await getStringTask;
            return urlcontent.Length;
        }
        static void Main(string[] args)
        {
        }
    }
}
