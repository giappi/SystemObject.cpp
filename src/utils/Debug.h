
/*
 * File:   Debug.h
 * Author: Giappi
 *
 * Created on April 22, 2018, 9:02 PM
 */

#ifndef DEBUG_H
#define DEBUG_H
#include "_typedef.h"
#include "cpp/lang/String.h"
#include <vector>


class Debug
{
public:

    static void log(const char* formated, ...);

    static std::vector<String> argumentsToString()
    {
        return _tmp_logf_arguments;
    }

    template <class T, class... Args>
    static std::vector<String> argumentsToString(T first, Args... args)
    {
        _tmp_logf_arguments.push_back(valueToString(first));
        return argumentsToString(args...);
    }

    template <class... Args>
    static void logf(String formated, Args... args)
    {
        // fix bug: log was wrong: _tmp_logf_arguments must clear before use
        _tmp_logf_arguments.clear();
        std::vector<String> arguments = argumentsToString(args...);
        logfv(formated, arguments);
    };

    static void logfv(String formated, std::vector<String> arguments);

    static String valueToString(const boolean x);
    static String valueToString(const char x);
    static String valueToString(const int8 x);
    static String valueToString(const int32 x);
    static String valueToString(const int64 x);
    static String valueToString(const uint8 x);
    static String valueToString(const uint32 x);
    static String valueToString(const uint64 x);
    static String valueToString(const float x);
    static String valueToString(const double x);
    static String valueToString(const long double x);
    static String valueToString(const char* x);

    static std::vector<String> _tmp_logf_arguments;

};

#endif /* DEBUG_H */

