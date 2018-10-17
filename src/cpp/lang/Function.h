/*
 * File:   Function.h
 * Author: Giappi
 *
 * Created on 16 October 2018, 12:50
 */

#ifndef FUNCTION_H
#define FUNCTION_H

template <class Fx> class Function;


template <class ReturnType, class... Args>
class Function<ReturnType(Args...)>
{
    typedef ReturnType (Fx)(Args...);
public:
    Function(Fx fx)
    {
        this->_fx = fx;
    }


    ReturnType operator()(Args... args)
    {
        return _fx(args...);
    }

private:
    Fx* _fx;

};



#endif /* FUNCTION_H */

