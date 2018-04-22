#pragma once
#include "Number.h"

class Integer :
	public Number
{
public:
	Integer(int n);
	virtual ~Integer();
public:
	
	operator int() const
	{
		return value;
	};
	
	
	void operator =(const int& n)
	{
		value = n;
	}

	Integer operator+ (const int& n)
	{
		return value + n;
	}
	

private:
	int value = 0;
};

