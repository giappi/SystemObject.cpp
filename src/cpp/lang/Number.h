#pragma once
#include <cpp/lang/Object.h>

class Number : public Object
{
public:
	Number();
	virtual ~Number();

private:
	void* value;
};

