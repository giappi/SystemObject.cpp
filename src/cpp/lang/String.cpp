#include "cpp/lang/String.h"
#include <iostream>

String::String() : length(_length)
{
    _value  = "";
    _length = _value.length();
}

String::String(const char* str) : length(_length)
{
    _value  = str;
    _length = _value.length();
}

String::String(const String& str) : length(_length)
{
    _value   = str;
    _length = _value.length();
}

String::~String()
{
}

boolean String::equals(const String& object) const
{
    return Object::equals(object);
}


String String::operator+(const String& str) const
{
    return "Not implemented!";
}

char String::operator[](usize index) const
{
    return _value[index];
}


char& String::operator[](usize index)
{
    return _value[index];
}

String::operator char*() const
{
    return (char*) _value.c_str();
}

String::operator const char*() const
{
    return (const char*) _value.c_str();
}



byte String::charAt(usize index) const
{
	return  index < _length ? _value[index] : '\0';
}


// TODO: improve string search
usize String::indexOf(String str) const
{
    return this->indexOf(str, 0);
};

usize String::indexOf(String str, usize fromIndex) const
{
    return _value.find(str.toByteArray(), fromIndex);
}



String String::trim() const
{
	return "Not implemented!";
};


String String::toLowerCase() const
{
	String str = "";
	for (register usize i = 0; i < str.length; i++)
	{
		str[i] += _value[i] > '@' && _value[i] < '[' ? ('a'-'A') : 0;
	}
	return str;
};


String String::toUpperCase() const
{
	String str = "";
	for (register usize i = str.length; i-- > 0;)
	{
		str[i] -= _value[i] > '`' && _value[i] < '{' ? ('a'-'A') : 0;
	}
	return str;
}

const byte* String::toByteArray() const
{
	return (const byte*)_value.c_str();
}

String String::substr(usize start, usize length) const
{
	return "Not implemented!";
};

String String::substring(usize start, usize end = -1) const
{
	return "Not implemented!";
};

String String::toString() const
{
    return *this;
}
