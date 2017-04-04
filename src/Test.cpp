#include <cpp/lang/Integer.h>
#include <cpp/lang/String.h>
#include <cpp/lang/Array.h>
#include <stdio.h>
#include <string>

void testInteger()
{
	Integer n = 30;
	Integer m = n + 1;
	printf("  Value is %d\n", m);
}
void testString()
{
	String s = " Hoang Dinh     Giap ";
	const char* t = s;
	printf("Origin Text:   %s\n", s.toCString());
	printf("toLowerCase:   %s\n", s.toLowerCase().toCString());
	printf("toUpperCase:   %s\n", s.toUpperCase().toCString());
	printf("Origin Text:   %s\n", s.toCString());

	u32 nh = s.indexOf("nh");
	printf("Index Of 'nh': %d\n", nh);
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
	testArray();
	int a = 0;
}
