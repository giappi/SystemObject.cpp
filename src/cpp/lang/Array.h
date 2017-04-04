#pragma once
#include <cpp/lang/Object.h>
#include <cstring>
#include <initializer_list>

template <class T>
class Array :
	public Object
{
public:
	Array() : length(_length)
	{
		_length = 0;
	};
	Array(std::initializer_list<T> list) : length(_length)
	{
		_length = 0;
		_value = new T[list.size()];
		for (const T e : list)
		{
			_value[_length++] = (e);
		}
	}

	/* set item in at index */
	T operator [](i32 index) const
	{
		if (index >= length)
		{
			throw std::exception("java.lang.Exception: Index out of bound.");
		}
		return index < _length ? _value[index] : NULL;
	}

	/* get item at index */
	T & operator [](i32 index)
	{
		if (index >= length)
		{
			throw std::out_of_range("java.lang.Exception: Index out of bound.");
		}

		return _value[index];
	}

	T getElementAt(int index)
	{
		return (*this)[index];
	}

	u32 push(T item)
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

	T pop()
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

	virtual ~Array()
	{
		//delete[] _value;
	};

public:
	/* length or number of items */
	const u32 &length;
private:
	T* _value = NULL;
	T _tmp;
	u32 _length = 0;
};

