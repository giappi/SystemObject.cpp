/*
 * File:   Function.h
 * Author: Giappi
 *
 * Created on 16 October 2018, 12:50
 */

#ifndef FUNCTION_H
#define FUNCTION_H
#include "cpp/lang/Object.h"

#define extend :

template <class Fx>
class Function;

template <class ReturnType, class... Args>
class Function<ReturnType(Args...)>
    extend public Object
{

private:

    /**
     * Generic Function
     */
    class Fn
    {

    public:
        /**
         * Operator call function
         * @param args arguments
         * @return ReturnType
         */
        virtual ReturnType operator()(Args... args) = 0;
        /**
         * Make another Fn from this
         * @return an other Fn as pointer
         */
        virtual Fn* clone() = 0;

    };

    /**
     * Specific Function
     */
    template <class T>
    class Fx
        extend public Fn
    {

    public:

        /**
         * Create a specific function
         * @param function
         */
        Fx(T function): _fx_with_args(function)
        {
        };

        /**
         * Operator call funtion(args...)
         * @param args arguments
         * @return ReturnType
         */
        ReturnType operator()(Args... args) override
        {
            return _fx_with_args(args...);
        }
        /**
         * Make a duplicate version of this Fx
         * @return an other Fn as pointer
         */
        Fn* clone() override
        {
            return new Fx<T>(*this);
        };


    private:

        T _fx_with_args;

    };

public:

    /**
     * Create a Function that is callable
     * @param function
     */
    template <class CallableType>
    Function(CallableType function)
    {
        this->_fx = new Fx<CallableType>(function);
    }

    /**
     * Create new Function by copy from another: `Function b = a;`
     * @param __fx another Function
     */
    Function(const Function<ReturnType(Args...)>& __fx)
    {
        Fn* fx1 = __fx._fx;
        this->_fx = fx1->clone();
    }

    /**
     * Operator for call Funtion(args...)
     * @param args arguments
     * @return ReturnType
     */
    ReturnType operator()(Args... args)
    {
        return _fx->operator ()(args...);
    }

    /**
     * Destroy and clean up everything
     */
    virtual ~Function()
    {
        delete this->_fx;
    }

private:

    Fn* _fx;

};


#endif /* FUNCTION_H */

