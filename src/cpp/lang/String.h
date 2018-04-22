#pragma once
#include "_typedef.h"

class String
	/*public Object*/
{
public:
	String();

	String(const char* str);
	~String();

	String(const String &str);
	
	// cast String to char*
	operator char*() const
	{
		return _value;
	};

	// cast String to const char*
	operator const char*() const
	{
		return (const char*)_value;
	};


	/* get character in String at index */
	char operator [](usize index) const
	{
		return _value[index];
	}

	/* set character in String at index */
	char & operator [](usize index)
	{
		return _value[index];
	}

	/* get character in string at index */
	char charAt(usize index);

	/* get position of `substr` in String, return -1 if not found */
    usize indexOf(String substr);

	/* removes whitespace from both ends of a string */
	String trim();

	/* convert string to array of char */
	const char* toCString();

	/* convert string to lower case */
	String toLowerCase();

	/* convert string to upper case */
	String toUpperCase();

	/* take substring contains `length` character from index `start` */
	String substr(usize start, usize length) const;

	/* take substring contains from index `start` to index `end` */
	String substring(usize start, usize end) const;


public:
	/* length or number of characters */
	const usize &length;

private:
    usize   _length = 0;
	char* _value = null;
	char  _tmp;
};

