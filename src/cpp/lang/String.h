#pragma once
#include <cpp/lang/Object.h>

class String :
	public Object
{
public:
	String();

	String(const char* s);
	~String();

	String(String &s);

	
	// cast String to Char*
	operator Char*() const
	{
		return (Char*)_value;
	};

	// cast String to const char*
	operator const char*() const
	{
		return (const char*)_value;
	};

	// cast String to char*
	operator char*() const
	{
		return (char*)_value;
	};
	

	/* get character in String at index */
	Char operator [](i32 index) const
	{
		return index < _length ? _value[index] : NULL;
	}

	/* set character in String at index */
	Char & operator [](i32 index)
	{
		return index < _length ? _value[index] : _tmp;
	}

	/* get character in string at index */
	Char charAt(u32 index);

	/* get position of `substr` in String, return -1 if not found */
	i32 indexOf(String substr);

	/* removes whitespace from both ends of a string */
	String trim();

	/* convert string to array of char */
	Char* toCharStar();

	byte* getBytes();

	/* convert string to lower case */
	String toLowerCase();

	/* convert string to upper case */
	String toUpperCase();

	/* take substring contains `length` character from index `start` */
	String substr(i32 start, i32 length);

	/* take substring contains from index `start` to index `end` */
	String substring(i32 start, i32 end);


public:
	/* length or number of characters */
	const int &length;

private:
	int   _length = 0;
	Char* _value = NULL;
	Char  _tmp;
};

