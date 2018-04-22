#pragma once
#include "_typedef.h"
#include "cpp/lang/String.h"

class Object
{
public:
	Object();
	~Object();

	bool equals(Object object);
	const char* getName();
	String toString();
};
