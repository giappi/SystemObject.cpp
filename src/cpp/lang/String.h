#pragma once
#include "_typedef.h"
#include "Object.h"
#include <string>

class String:
    public Object
{
public:
	String();

	String(const char* str);
	~String();

	String(const String &str);

	// cast String to char*
	virtual operator char*() const;
	// cast String to const char*
	virtual operator const char*() const;

	/* get character in String at index */
	virtual byte        operator [](usize index) const;

	/* set character in String at index */
	virtual byte&       operator [](usize index);

    virtual String      operator+(const String& str) const;

	/* get character in string at index */
	virtual byte        charAt(usize index) const;

    /**
     * Check if this String equals with another
     * @param str anotherString to compare
     * @return true if two String are the same
     */
    virtual boolean     equals(const String& str) const;

    /**
     * get position of `str` in String, return length of this String if not found
     * @param str a text to search in this String
     * @return position of `str` in this String
     */
    virtual usize       indexOf(String str) const;
    /**
     *
     * @param str a text to search in this String
     * @param fromIndex the index from which to start the search
     * @return position of `str` in this String
     */
    virtual usize       indexOf(String str, usize fromIndex) const;

	/**
     * Return a new String with all extra whitespaces from begining and ending removed
     */
	virtual String      trim() const;

	/**
     * Convert this String to array of bytes
     * @return array of
     */
	virtual const byte* toByteArray() const;

	/**
     * Converts all of the characters in this String to lower case
     * @return the String that is converted to lowercase
     */
	virtual String      toLowerCase() const;

	/**
     * Converts all of the characters in this String to upper case
     * @return the String that is converted to uppercase
     */
	virtual String      toUpperCase() const;

	/**
     * Take a new string that is a substring of this string by first index and length of substring
     * @param from the position that is the begining of substring
     * @param length the length of substring
     * @return the specified substring
     */
	virtual String      substr(usize from, usize length) const;

	/**
     * Take a new string that is a substring of this string by given index
     * @param begin The begining index
     * @param end The ending index
     * @return the specified substring
     */
	virtual String      substring(usize begin, usize end) const;

    /**
     * Convert string to String
     * @return String
     */
    virtual String      toString() const override;


public:
	/* length or number of characters */
	const usize&        length;

private:
    usize               _length = 0;
	std::string         _value = "";
	byte                _tmp;
};

