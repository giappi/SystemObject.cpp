#include "cpp/lang/String.h"
#include <string>

typedef std::string StdString;

inline void*                    CREATE_STRING(const char* STR_VALUE)
{
    return (new StdString(STR_VALUE));
}

inline void                     DELETE_STRING(void* VOID_PTR)
{
    delete (StdString*)VOID_PTR;
}

inline StdString&             STRING(void* VOID_PTR)
{
    return *((StdString*)VOID_PTR);
}

String::String() : length(_length)
{
    _value  = CREATE_STRING("");
    updateLength();
}

String::String(const char* str) : length(_length)
{
    _value  = CREATE_STRING(str);
    updateLength();
}

String::String(const String& str) : length(_length)
{
    _value   = CREATE_STRING(str.toByteArray());
    updateLength();
}

String::~String()
{
    DELETE_STRING(_value);
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
    return STRING(_value)[index];
}


char& String::operator[](usize index)
{
    return STRING(_value)[index];
}

String::operator char*() const
{
    return (char*) STRING(_value).c_str();
}

String::operator const char*() const
{
    return (const char*) STRING(_value).c_str();
}



byte String::charAt(usize index) const
{
	return  index < _length ? STRING(_value)[index] : '\0';
}


// TODO: improve string search
usize String::indexOf(String str) const
{
    return this->indexOf(str, 0);
};

usize String::indexOf(String str, usize fromIndex) const
{
    return STRING(_value).find(str.toByteArray(), fromIndex);
}



String String::trim() const
{
	return "Not implemented!";
};


String String::toLowerCase() const
{
	String str = *this;
	for (register usize i = 0; i < str.length; i++)
	{
		str[i] += STRING(_value)[i] > '@' && STRING(_value)[i] < '[' ? ('a'-'A') : 0;
	}
	return str;
};


String String::toUpperCase() const
{
	String str = *this;
	for (register usize i = str.length; i-- > 0;)
	{
		str[i] -= STRING(_value)[i] > '`' && STRING(_value)[i] < '{' ? ('a'-'A') : 0;
	}
	return str;
}

const byte* String::toByteArray() const
{
	return (const byte*)STRING(_value).c_str();
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

void String::updateLength()
{
    _length = STRING(_value).length();
}
