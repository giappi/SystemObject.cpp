#include "cpp/lang/Integer.h"
#include "cpp/lang/String.h"
#include "cpp/lang/Array.h"
#include "utils/Debug.h"
#include "cpp/lang/Function.h"

class Test
{
public:
    static void testInteger()
    {
        Integer n = 30;
        Integer m = n + 1;
        Debug::log("  Value is %d\n", (int)m);
    }

    static void testString()
    {
        String s = "    (The quick brown \"Fox\" jumps over the lazy \"Dog\")    ";
        Debug::log("Length: %u", s.length);
        // test copy constructor
        const char* t = s.toCharArray();
        Debug::log("Origin Text:   '%s'", s.toCharArray());
        Debug::log("toLowerCase:   '%s'", s.toLowerCase().toCharArray());
        Debug::log("toUpperCase:   '%s'", s.toUpperCase().toCharArray());
        Debug::log("Trim   Text:   '%s'", s.trim().toCharArray());
        Debug::log("RepalceText:   '%s'", s.replaceN("Fox", "Firefox", 2).toCharArray());
        Debug::log("Repalce All:   '%s'", s.replaceAll("o", "[*]").toCharArray());
        Debug::log("Origin Text:   '%s'", s.toCharArray());

        Debug::log("");
        // Test polymorphism
        Object& o = s;
        Debug::log("Object String:   %s", o.getName().toCharArray());


        // Test equals
        String s1 = "aa";
        String s2 = "ab";
        Debug::log("s1.hasCode() = %ul", s1.hashCode());
        Debug::log("s2.hasCode() = %ul", s2.hashCode());
        Debug::log("s1.hasCode() == s2.hashCode() ? %d", s1.hashCode() == s2.hashCode());
        Debug::log("s1 == s2 ? %d", s1.equals(s2));



        uint32 nh = s.indexOf("over");
        Debug::log("Index Of 'over': %ul", nh);
    }

    static void testArray()
    {
        Array<int> a = { 1, 2, 4, 7, 8, 9, 0 };
        Debug::logf("a.length = {}", a.length);
        int y = a[3];
        Debug::logf("a[3] = {}", y);
        a.push(1234);
        Debug::logf("a.length = {}", a.length);
        for(auto i = 0; i < a.length; i++)
        {
            Debug::logf("-- a[{}] = {}", i, a[i]);
        }
        int last = a[a.length - 1];
        Debug::logf("last = {}", last);
        int d = a.pop();
        Debug::logf("a.pop() = {}", d);
        int length = a.length;
        Debug::logf("a.length = {}", length);
    }

    static void FunctionTest()
    {
        Debug::log("Function.() OK!");
    }

    static int sumAB(int a, int b)
    {
        return a + b;
    }

    class A
    {
    public:
        static int add(int a, int b)
        {
            return a + b;
        }
        double multiply(double a, double b)
        {
            return a * b;
        }
    };

    static void testFunction()
    {
        {
            typedef void (&VFV)();
            VFV fx1 = FunctionTest;
            fx1();

            Function<int(int, int)> fx2 = sumAB;
            auto fx3 = fx2;

            Debug::log("fx3(%d, %d) -> %d", 3, 4, fx3(3, 4));

            // test lambda
            Function<int(int, int)> f4 = [](int a, int b) -> int { return a * b; };
            Debug::log("fx4(%d, %d) -> %d", 3, 4, f4(3, 4));

            // test static method class
            Function<int(int, int)> fx5 = A::add;
            Debug::log("fx5(%d, %d) -> %d", 5, 8, fx5(5, 8));
            Debug::log("fx5.getName() -> '%s'", (const char*) fx5.getName());

            // test method class
            //A objectA = A();
            //Function<double(double, double)> fx6 = &A::multiply;
            //Debug::log("fx5(%d, %d) -> %d", 5, 8, fx6(5, 8));
        }
    }
};


int main()
{
	//Test::testString();
    //Test::testFunction();
    Debug::logf("[{}, {}, {}, {}, {}, {}]", 13, 'C', true, 4.5, "const char* Hello");
    Debug::logf("--{}--", true);
    Test::testArray();
	int a = 0;
}
