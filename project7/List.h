//========================================================
// Matt Kretchmar
// October 2022
// List.h
// This file contains the List class declaration.
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef LIST_H
#define LIST_H

#define DEFAULT_LIST_CAPACITY 10

template <class T>
class List
{
	// DO NOT CHANGE THIS PART
public:
	List(void);
	List(const List<T> &mylist);
	~List(void);
	List<T> operator=(const List<T> &mylist);
	string to_string(void) const;
	void append(const T &item);
	T &operator[](int index);
	void insert(const T &item, int index);
	void remove(int index);
	List<T> operator+(const List<T> &mylist) const;
	int length(void) const;
	bool isEmpty(void) const;
	void clear(void);

private:
	// DO NOT CHANGE THESE THREE VARIABLES
	T *list;	  // the pointer for the dynamic array
	int capacity; // the size of the array
	int size;	  // the number of items in the list

	// YOU CAN ADD METHODS/VARIABLES HERE
};

#include "List.cpp"

#endif
