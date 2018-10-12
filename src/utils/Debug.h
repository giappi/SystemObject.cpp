
/*
 * File:   Debug.h
 * Author: Giappi
 *
 * Created on April 22, 2018, 9:02 PM
 */

#ifndef DEBUG_H
#define DEBUG_H
#include "_typedef.h"

class Debug
{
public:
    template<class ... Args>
    static void printf(const byte* formated, Args... args);
};

#endif /* DEBUG_H */

