#pragma once
#include "cpp/lang/Object.h"
#include <initializer_list>
#include <vector>

template <class T>
class Array :
	public Object
{
public:

	Array();
	Array(std::initializer_list<T> list);

	/* set item in at index */
	T operator [](int32 index) const;

	/* get item at index */
	T & operator [](int32 index);

	T getElementAt(int index);

	uint32 push(T item);

	T pop();

	virtual ~Array();

public:
	/* length or number of items */
	const uint32 &length;
private:
	T* _value = NULL;
	T _tmp;
	uint32 _length = 0;
};

