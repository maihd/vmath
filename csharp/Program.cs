using System;
using static vmath;

namespace csharp
{
    class Program
    {
        static void vec2_test()
        {
            vec2 a = vec2(1, 2);
            vec2 b = vec2(3, 4);
            vec2 c = add(a, b);
            vec2 d = a + b;

            if (c == d)
            {
                Console.WriteLine(string.Format("add({0}, {1}): {2}", a, b, c));
            }
            else
            {
                Console.WriteLine("Test failed");
            }
        }

        static void Main(string[] args)
        {
            vec2_test();
        }
    }
}
