#include <iomanip>
#include <math.h>
#include <sstream>
#include <iostream>
#include "List.h"
using namespace std;

/*
DEFAULT CONSTRUCTOR -> Creates an empty list
PARAMETERS: none
RETURN: none
FUNCTIONALITY:
- sets capacity to the default capacity defined in the header file
- sets size to NULL
- initializes an array with the default size, capacity and return a pointer
to the first element of the array
*/

template <class T>
List<T>::List(void)
{
    capacity = DEFAULT_LIST_CAPACITY;
    size = 0;
    list = new T[DEFAULT_LIST_CAPACITY];
}

/*
COPY CONSTRUCTOR -> Deep copy
PARAMETERS: const reference to the passed object mylist
RETURN: none
FUNCTIONALITY: copies the size, capacity and values of the parameter
to the caller of the function
*/

template <class T>
List<T>::List(const List<T> &mylist)
{
    list = new T[mylist.capacity];
    capacity = mylist.capacity;
    size = mylist.size;
    copy(mylist.list, mylist.list + mylist.size, list);
}

/*
DESTRUCTOR
PARAMETERS: none
RETURN: none
FUNCTIONALITY: returns the array to the free store
*/

template <class T>
List<T>::~List(void)
{
    delete[] list;
}

/*
ASSIGNMENT OPERATOR
PARAMETERS: const reference to the passed object mylist
RETURN: *this -> a reference to the current object
*/

template <class T>
List<T> List<T>::operator=(const List<T> &mylist)
{
    delete[] list;
    list = new T[mylist.capacity];
    capacity = mylist.capacity;
    size = mylist.size;
    copy(mylist.list, mylist.list + mylist.size, list);
    return *this;
}

/*
TO_STRING FUNCTION
PARAMETERS: none
RETURN: a string of the list elements separated by commas
*/
template <class T>
string List<T>::to_string(void) const
{
    stringstream stream;
    for (int i = 0; i < size; i++)
    {
        stream << *(list + i) << " ";
    }
    return stream.str();
}

/*
APPEND FUNCTION
PARAMETERS: const reference to the passed 'item' value of type T
RETURN: none
FUNCTIONALITY: append a new element at the end of the list
*/

template <class T>
void List<T>::append(const T &item)
{
    if (size == capacity)
    {
        add_memory();
    };

    T *elementPtr = list + size;
    *elementPtr = item;
    size++;
}

/*
OPERATOR[]
PARAMETERS: reference to the inputted index
RETURN: the list's value at specified index
*/

template <class T>
T &List<T>::operator[](int index)
{
    if (index < 0 || index > size - 1)
    {
        throw std::invalid_argument("Index out of range"); // throwing an exception
    };
    T *indexPtr = list + index;
    return *indexPtr;
}

/*
INSERT FUNCTION
PARAMETERS:
- const reference to 'item' of type T
- an index of type integer
RETURN: none
FUNCTIONALITY: shifts all elements on the right of the inputted index 1 unit to the right
to make space for the new item to be inserted into the specified position
*/

template <class T>
void List<T>::insert(const T &item, int index)
{
    if (index >= 0 || index <= size)
    {
        size += 1;
        if (size == capacity)
        {
            add_memory();
        }
        for (int i = size - 1; i > index; i--)
        {
            list[i] = list[i - 1];
        }
        list[index] = item;
    }
}

/*
REMOVE FUNCTION
PARAMETERS: an index of type integer
RETURN: none
FUNCTIONALITY: remove the list's element at specified inde and then shifts all elements on the right
of the inputted index 1 unit to the left
*/

template <class T>
void List<T>::remove(int index)
{
    if (index >= 0 || index <= size - 1)
    {
        size -= 1;
        for (int i = index; i < size; i++)
        {
            list[i] = list[i + 1];
        }
    }
}

/*
OPERATOR+
PARAMETERS: const reference of the passed object 'mylist'
RETURN: a new list that is the concatenation of 'mylist' and our list
*/

template <class T>
List<T> List<T>::operator+(const List<T> &mylist) const
{
    List<T> concat;
    concat.size = 0;
    concat.capacity = capacity + mylist.capacity;
    concat.list = new T[concat.capacity];

    for (int i = 0; i < size; i++)
    {
        T *listPtr = list + i;
        concat.append(*listPtr);
    }

    for (int i = 0; i < mylist.size; i++)
    {
        T *mylistPtr = mylist.list + i;
        concat.append(*mylistPtr);
    }
    return concat;
}

/*
LENGTH()
PARAMETERS: none
RETURN: the size of the list of type integer
*/

template <class T>
int List<T>::length(void) const
{
    return size;
}

/*
isEmpty()
PARAMETERS: none
RETURN: a boolean value that is either true for an empty list or false for a non-empty list
*/

template <class T>
bool List<T>::isEmpty(void) const
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
clear()
PARAMETERS: none
RETURN: none
FUNCTIONALITY: delete the existing list and creates a new empty list of same capacity to free up memory
*/

template <class T>
void List<T>::clear(void)
{
    size = 0;
    delete[] list;
    list = new T[capacity];
}
