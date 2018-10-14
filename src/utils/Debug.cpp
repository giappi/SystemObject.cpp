
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