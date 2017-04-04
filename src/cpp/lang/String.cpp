#include "String.h"


String::String() : length(_length)
{
	_length = 0;
	_value = new Char[_length + 1];
	_value[0] = NULL;
}

String::String(const char* s) : length(_length)
{
	_length = 0;
	while (s[_length] != NULL)
	{
		++_length;
	}
	_value = new Char[_length + 1];
	for (u32 i = 0; i < this->length; i++)
	{
		_value[i] = s[i];
	}
	_value[_length] = NULL;
}

String::String(String& str) : length(_length)
{
	_length = str.length;
	_value = new Char[_length];
	for (u32 i = 0; i < this->length; i++)
	{
		_value[i] = str[i];
	}
	_value[_length] = NULL;
}

String::~String()
{
}

Char String::charAt(u32 index)
{
	return index < _length ? _value[index] : NULL;
}


#pragma untested
// TODO: improve string search
i32 String::indexOf(String str)
{
	for (u32 i = 0; i < _length - str.length; i++)
	{
		u32 diff = 0;
		for (u32 j = 0; j < str.length; j++)
		{
			diff += _value[i + j] != str.charAt(j);
		}
		if (diff == 0)
		{
			return i;
		}
	}
	return -1;
};


String String::trim()
{
	return *this;
};


String String::toLowerCase()
{
	String str = *this;
	for (u32 i = 0; i < str.length; i++)
	{
		str[i] += _value[i] > '@' && _value[i] < '[' ? 32 : 0;
	}
	return str;
};


String String::toUpperCase()
{
	String str = *this;
	for (u32 i = 0; i < str.length; i++)
	{
		str[i] -= _value[i] > '`' && _value[i] < '{' ? 32 : 0;
	}
	return str;
}

Char* String::toCharStar()
{
	return (Char*)_value;
}

String String::substr(i32 start, i32 length = -1)
{
	return "Not implemented";
};
String String::substring(i32 start, i32 end = -1)
{
	return "Not implemented";
};