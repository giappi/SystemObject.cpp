#pragma once
#include "cpp/lang/Object.h"
#include "cpp/lang/ArrayAccess.h"
#include <initializer_list>
#include <vector>

template <class T>
class Array :
	public Object,
    public ArrayAccess<T>
{
public:

	Array();
	Array(std::initializer_list<T> list);


	virtual T           operator [](const usize index) const override;
	virtual T &         operator [](const usize index) override;
    virtual boolean     exists(const T& element) override;
    virtual usize       getLength() const override;
	virtual T           getElementAt(int index);
	virtual uint32      push(T item);
	T                   pop();

	virtual ~Array();

public:
	/* length or number of items */
	const uint32 &length;
private:
	T* _value = NULL;
	T _tmp;
	uint32 _length = 0;
};

