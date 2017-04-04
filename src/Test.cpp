#include <cpp/lang/Integer.h>
#include <cpp/lang/String.h>
#include <stdio.h>


void testInteger()
{
	Integer n = 30;
	Integer m = n + 1;
	printf("  Value is %d\n", m);
}
void testString()
{
	String s = " Hoang Dinh     Giap ";
	Char* t = s.toCharStar();
	printf("Origin Text:   %s\n", s);
	printf("toLowerCase:   %s\n", s.toLowerCase());
	printf("toUpperCase:   %s\n", s.toUpperCase());
	printf("Origin Text:   %s\n", s);

	u32 nh = s.indexOf("nh");
	printf("Index Of 'nh': %d\n", nh);
}

int main()
{
	testString();
	int a = 0;
}
