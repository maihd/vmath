using System;
using static vmath;

namespace csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            vec2 a = new vec2(1, 2);
            vec2 b = new vec2(3, 4);
            vec2 c = add(a, b);

            Console.WriteLine(string.Format("add({0}, {1}): {2}", a, b, c));
        }
    }
}
