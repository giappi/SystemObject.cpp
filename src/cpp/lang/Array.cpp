#include "cpp/lang/Array.h"
#include <exception>
#include <stdexcept>


template <class T>
Array<T>::Array() : length(_length)
{
    _length = 0;
};

template <class T>
Array<T>::Array(std::initializer_list<T> list) : length(_length)
{
    _length = 0;
    _value = new T[list.size()];
    for (const T e : list)
    {
        _value[_length++] = (e);
    }
}

/* set item in at index */
template <class T>
T Array<T>::operator [](const usize index) const
{
    if (index < 0 || index >= length)
    {
        throw std::runtime_error("java.lang.Exception: Index out of bound.");
    }
    return _value[index];
}

/* get item at index */
template <class T>
T & Array<T>::operator [](const usize index)
{
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("java.lang.Exception: Index out of bound.");
    }

    return _value[index];
}

template<class T>
boolean Array<T>::exists(const T& element)
{
    return false;
}


template <class T>
T Array<T>::getElementAt(int index)
{
    return (*this)[index];
}

template<class T>
usize Array<T>::getLength() const
{
    return _length;
}


template <class T>
uint32 Array<T>::push(T item)
{
    _length++;
    T* _value1 = new T[_length];
    _value1[_length - 1] = item;
    for (int i = 0; i < _length-1; i++)
    {
        _value1[i] = _value[i];
    }

    delete[] _value;
    _value = _value1;
    return _length;
}

template <class T>
T Array<T>::pop()
{
    T item = _value[_length - 1];
    T* _value1 = new T[_length - 1];
    _length--;
    for (int i = 0; i < _length - 1; i++)
    {
        _value1[i] = _value[i];
    }

    delete[] _value;
    _value = _value1;
    return item;
}

template <class T>
Array<T>::~Array()
{
    delete[] _value;
};

// @important: always on bottom
template class Array<boolean>;
template class Array<int32>;
template class Array<int64>;
template class Array<uint32>;
template class Array<uint64>;
template class Array<float>;
template class Array<double>;