
/*
 * File:   Debug.cpp
 * Author: Giappi
 *
 * Created on April 22, 2018, 9:02 PM
 */

#include "Debug.h"
#include <tuple>
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>


void Debug::log(const char* __formated, ... )
{
    char buffer[10240] = {'\0'};
    // -- Empty the buffer properly to ensure no leaks.
    memset(buffer, '\0', sizeof(buffer));

    va_list args;
    va_start ( args, __formated );
    vsnprintf ( buffer, sizeof(buffer), __formated, args );
    va_end ( args );

    printf("%s\n", buffer);

}

void Debug::logfv(String formated, std::vector<String> arguments)
{
    for(String arg_i : arguments)
    {
        formated = formated.replaceN("{}", arg_i, 1);
    }
    Debug::log(formated.toCharArray());
}



String Debug::valueToString(const boolean x)
{
    return x == true ? "<true>" : "<false>";
}

String Debug::valueToString(const char x)
{
    // compile error on gcc GNU 8.2.1
    //return String("char('") + ((const char[]){x, 0}) + "'" + valueToString((int8) x) + ")";
    const char c[] = {x, '\0'};
    return String("char('") + c + "'" + valueToString((int8) x) + ")";
}

String Debug::valueToString(const int8 x)
{
    return std::to_string(x).c_str();
}

String Debug::valueToString(const int32 x)
{
    return std::to_string(x).c_str();
}

String Debug::valueToString(const int64 x)
{
    return std::to_string(x).c_str();
}

String Debug::valueToString(const uint8 x)
{
    return std::to_string(x).c_str();
}

String Debug::valueToString(const uint32 x)
{
    return std::to_string(x).c_str();
}

String Debug::valueToString(const uint64 x)
{
    return std::to_string(x).c_str();
}

String Debug::valueToString(const float x)
{
    return std::to_string(x).c_str();
}

String Debug::valueToString(const double x)
{
    return std::to_string(x).c_str();
}

String Debug::valueToString(const long double x)
{
    return std::to_string(x).c_str();
}

String Debug::valueToString(const char* x)
{
    return String("\"") + x + "\"";
}

std::vector<String> Debug::_tmp_logf_arguments = {};