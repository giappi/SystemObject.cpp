#pragma once
#include <_typedef.h>

class Object
{
public:
	Object();
	~Object();

	bool equals(Object object);
	const char* toString();
};
