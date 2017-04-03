
#include <cpp/lang/String.h>
#include <stdio.h>

int main()
{
	/*
	Integer n = 30;
	Integer m = n + 1;
	printf("  Value is %d\n", m);
	*/

	String s = " Hoang Dinh     Giap ";

	printf("Origin Text:   %s\n", (char*)s);
	printf("toLowerCase:   %s\n", (char*)(s.toLowerCase()));
	printf("toUpperCase:   %s\n", (char*)(s.toUpperCase()));
	printf("Origin Text:   %s\n", (char*)s);

	u32 Dinh = s.indexOf("Dinh");
	printf("Index Of 'Dinh': %d\n", Dinh);
	int a = 0;
}