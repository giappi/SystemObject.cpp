#pragma once
#include <cpp/lang/Object.h>
#include <string>
class String :
	public Object
{
public:
	String();

	String(const char* s);
	~String();

	String(String &s);

	operator char*() const
	{
		return _value;
	};
	char operator [](i32 index) const
	{
		return index < _length ? _value[index] : NULL;
	}
	char & operator [](i32 index)
	{
		return index < _length ? _value[index] : _tmp;
	}

	Char charAt(u32 index);
	i32 indexOf(String substr);
	String trim();
	String toLowerCase();
	String toUpperCase();
	String substr(i32 start, i32 length);
	String substring(i32 start, i32 end);


public:
	const int &length;

private:
	int   _length = 0;
	char* _value = NULL;
	char  _tmp;
};

