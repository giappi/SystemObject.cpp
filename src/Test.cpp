#include <cpp/lang/Integer.h>
#include <cpp/lang/String.h>
#include <cpp/lang/Array.h>
#include <stdio.h>

void testInteger()
{
	Integer n = 30;
	Integer m = n + 1;
	printf("  Value is %d\n", (int)m);
}
void testString()
{
	String s = " Hoang Dinh     Giap ";
    printf("Length: %u\n", s.length);
	// test copy constructor
	const char* t = s.toByteArray();
	printf("Origin Text:   %s\n", s.toByteArray());
	printf("toLowerCase:   %s\n", s.toLowerCase().toByteArray());
	printf("toUpperCase:   %s\n", s.toUpperCase().toByteArray());
	printf("Origin Text:   %s\n", s.toByteArray());

    // Test polymorphism
    Object& o = s;
    printf("Object String:   %s\n", o.getName().toByteArray());


    // Test equals
    String s1 = "aa";
    String s2 = "ab";
    printf("s1.hasCode() = %ul\n", s1.hashCode());
    printf("s2.hasCode() = %ul\n", s2.hashCode());
    printf("s1.hasCode() == s2.hashCode() ? %d\n", s1.hashCode() == s2.hashCode());
    printf("s1 == s2 ? %d\n", s1.equals(s2));

	uint32 nh = s.indexOf("nh");
	printf("Index Of 'nh': %u\n", nh);
}

void testArray()
{
	Array<int> a = { 1, 2, 4, 7, 8, 9, 0 };
	a.length;
	int y = a[3];
	a.push(1234);
	int last = a[a.length - 1];
	int d = a.pop();
	int length = a.length;
	int c = 0;
}

int main()
{
	testString();
	int a = 0;
}
