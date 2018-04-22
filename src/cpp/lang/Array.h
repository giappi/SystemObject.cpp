#pragma once
#include "cpp/lang/Object.h"
#include <cstring>
#include <initializer_list>

template <class T>
class Array :
	public Object
{
public:

	Array();
	Array(std::initializer_list<T> list);

	/* set item in at index */
	T operator [](i32 index) const;

	/* get item at index */
	T & operator [](i32 index);

	T getElementAt(int index);

	u32 push(T item);

	T pop();

	virtual ~Array();

public:
	/* length or number of items */
	const u32 &length;
private:
	T* _value = NULL;
	T _tmp;
	u32 _length = 0;
};

