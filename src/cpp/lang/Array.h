#pragma once
#include "cpp/lang/Object.h"
#include "cpp/lang/ArrayAccess.h"
#include "Iterable.h"
#include <initializer_list>

class ArrayBase :
    public Object
{

public:

    typedef byte* E;

    ArrayBase();
    ~ArrayBase();
protected:

    void                    _new();
	E                       _get(const usize index) const;
    E&                      _reference(const usize index);
    void                    _set(const usize index, E element);
    boolean                 _exists(const E& element);
	E                       _getElementAt(const int index);
	usize                   _push(E item);
	E                       _pop();
    usize                   _getLength();
    void                    _updateLength();

public:
	const usize &length;

protected:
	void*  _value = null;
    usize  _element_size = 1;
	usize  _length = 0;
};


template <class T>
class Array :
	public ArrayBase,
    public ArrayAccess<T>
{
public:

	Array()
    {
        this->_new();
    };
	Array(std::initializer_list<T> list)
    {
        this->_new();
        for(T e : list)
        {
            this->_push( (byte*) new T(e));
        }
    };


	virtual T               operator [](const usize index) const override
    {
        return *(T*)( (byte*)_get(index));
    };

	virtual T&              operator [](const usize index) override
    {
        return *(T*)(_reference(index));
    };

    virtual boolean         exists(const T& element) override
    {
        return _exists( (byte*)&element);
    };

    virtual usize           getLength() const override;

	virtual T               getElementAt(const int index)
    {
        return *(T*)(_getElementAt(index));
    };

	virtual uint32          push(T item)
    {
        return _push((byte*)&item);
    };

	T                       pop()
    {
        return *(T*)_pop();
    };

	virtual ~Array();


};

