#include "cpp/lang/String.h"
#include <string>

typedef std::string StdString;

#pragma region HELP_FUNCTIONS
inline void*                    CREATE_STRING(const char* __const_char_array)
{
    return (new StdString(__const_char_array));
}

inline void                     DELETE_STRING(void* __void_pointer)
{
    delete (StdString*)__void_pointer;
    __void_pointer = null;
}

inline StdString&               STRING(void* __void_pointer)
{
    return *((StdString*)__void_pointer);
}
#pragma endregion HELP_FUNCTIONS

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
    _value   = CREATE_STRING(str.toCharArray());
    updateLength();
}

String::~String()
{
    DELETE_STRING(_value);
}

boolean String::equals(const String& __string2) const
{
    return STRING(_value) == STRING(__string2._value);
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



char String::charAt(usize index) const
{
	return  index < this->GetLength() ? STRING(_value)[index] : '\0';
}


// TODO: improve string search
usize String::indexOf(String str) const
{
    return this->indexOf(str, 0);
};

usize String::indexOf(String str, usize fromIndex) const
{
    auto std_string_index = STRING(_value).find(str.toCharArray(), fromIndex);
    if(std_string_index == StdString::npos)
    {
        std_string_index = this->GetLength();
    }
    return std_string_index;
}

usize String::GetLength() const
{
    return STRING(_value).length();
}


String String::trim() const
{
	return "Not implemented!";
};


String String::toLowerCase() const
{
	String str = *this;
	for (register usize i = 0; i < str.GetLength(); i++)
	{
		str[i] += STRING(_value)[i] > '@' && STRING(_value)[i] < '[' ? ('a'-'A') : 0;
	}
	return str;
};


String String::toUpperCase() const
{
	String str = *this;
	for (register usize i = str.GetLength(); i-- > 0;)
	{
		str[i] -= STRING(_value)[i] > '`' && STRING(_value)[i] < '{' ? ('a'-'A') : 0;
	}
	return str;
}

const byte* String::toByteArray() const
{
	return (const byte*)STRING(_value).c_str();
}

const char* String::toCharArray() const
{
    return (const char*)toByteArray();
}


String String::substr(usize __begin, usize __length) const
{
	return STRING(_value).substr(__begin, __length).c_str();
};

String String::substring(usize __begin, usize __end) const
{
	return this->substr(__begin, __end - __begin);
};

String String::substring(usize __begin) const
{
    return this->substr(__begin, this->GetLength());
}


String String::toString() const
{
    return *this;
}

void String::updateLength()
{
    _length = STRING(_value).length();
}
