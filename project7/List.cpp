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
List<T>::List(void) {
    capacity = DEFAULT_LIST_CAPACITY;
    size = NULL;
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
List<T>::List(const List<T> &mylist) {
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
List<T>::~List(void) {
    delete [] list;
}

/*
ASSIGNMENT OPERATOR
PARAMETERS: const reference to the passed object mylist
RETURN: *this -> a reference to the current object
*/

template <class T> 
List<T> List<T>::operator=(const List<T> &mylist) {
    delete [] list;
    list = new T[mylist.capacity];
    capacity = mylist.capacity;
    size = mylist.size;
    copy(mylist.list, mylist.list + mylist.size, list);
    return *this; 
}

/*
to_string 
PARAMETERS: none
RETURN: a string of the list elements separated by commas
*/
template <class T>
string List<T>::to_string(void) const {
    stringstream stream;
    for (int i = 0; i < size; i++) {
        stream << *(list+i);
    }
    stream << " " << "size: " << size << " " << "cap:" << " " << capacity << endl; 
    return stream.str();
}

template <class T>
void List<T>::append(const T &item) {
    
}

template <class T> 
T& List<T>::operator[](int index) {

}

template <class T> 
void List<T>::insert(const T &item, int index) {

}

template <class T> 
void List<T>::remove(int index) {

}

template <class T> 
List<T> List<T>::operator+(const List<T> &mylist) const {

}

template <class T> 
int List<T>::length(void) const {

}

template <class T> 
bool List<T>::isEmpty(void) const {

}

template <class T> 
void List<T>::clear(void) {
    
}

