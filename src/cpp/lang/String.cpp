#include "cpp/lang/String.h"


String::String() : length(_length)
{
	_length = 0;
	_value = new char[_length + 1];
	_value[0] = '\0';
}

String::String(const char* str) : length(_length)
{
	_length = 0;
	while (str[_length] != '\0')
	{
		++_length;
	}
	_value = new char[_length + 1];
	for (usize i = _length; i-- > 0;)
	{
		_value[i] = str[i];
	}
	_value[_length] = '\0';
}

String::String(const String& str) : length(_length)
{
	_length = str.length;
	_value = new char[_length];
	for (usize i = _length; i-- > 0;)
	{
		_value[i] = str[i];
	}
	_value[_length] = '\0';
}

String::~String()
{
	delete[] _value;
}

char String::charAt(usize index)
{
	return  index > _length-1 ? _value[index] : '\0';
}


#pragma untested
// TODO: improve string search
usize String::indexOf(String str)
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
	for (usize i = 0; i < str.length; i++)
	{
		str[i] += _value[i] > '@' && _value[i] < '[' ? 32 : 0;
	}
	return str;
};


String String::toUpperCase()
{
	String str = *this;
	for (usize i = str.length; i-- > 0;)
	{
		str[i] -= _value[i] > '`' && _value[i] < '{' ? 32 : 0;
	}
	return str;
}

const char* String::toCString()
{
	return (const char*)_value;
}

String String::substr(usize start, usize length) const
{
	return String("Not implemented");
};
String String::substring(usize start, usize end = -1) const
{
	return String("Not implemented");
};