#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <sstream>
#include <iostream>
using namespace std;

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
    T *list;      // the pointer for the dynamic array
    int capacity; // the size of the array
    int size;     // the number of items in the list

    // YOU CAN ADD METHODS/VARIABLES HERE
    void add_memory()
    {
        capacity *= 2;
		T *newList = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			newList[i] = list[i];
		}

		delete[] list;

		list = newList;
    }
};

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
    delete [] list; 
	capacity = mylist.capacity; 
	size = mylist.size; 
	list = new T[mylist.capacity]; 
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
        stream << *(list + i) << " ";
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
        throw std::invalid_argument("Index out of range");
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
void List<T>::insert(const T &item, int index) {
    if (index >= 0 || index <= size) {
        size += 1;
        if (size == capacity) {
            add_memory();
        }
        for (int i = size - 1; i > index; i--) {
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
void List<T>::remove(int index) {
    if (index >= 0 || index <= size - 1) {
        size -= 1;
        for (int i = index; i < size; i++) {
            list[i] = list[i + 1];
        } 
    }
}

template <class T> 
List<T> List<T>::operator+(const List<T> &mylist) const {
    List<T> concat;
    concat.size = 0;
    concat.capacity = capacity + mylist.capacity;
    concat.list = new T[concat.capacity];

    for (int i = 0; i < size; i++) {
        T* listPtr = list + i;
        concat.append(*listPtr);
    } 

    for (int i = 0; i < mylist.size; i++) {
        T* mylistPtr = mylist.list + i;
        concat.append(*mylistPtr);
    }
    return concat;
}

template <class T>
int List<T>::length(void) const
{
    return size;
}

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

template <class T>
void List<T>::clear(void)
{
    size = 0;
    delete[] list;
    list = new T[capacity];
}

int main(void)
{
    List<int> list1;
    cout << "list1 = " << list1.to_string() << endl;

    for (int i = 1; i <= 10; i++)
        list1.append(i);

    cout << "list1 = " << list1.to_string() << endl;

    List<int> list2(list1);
    cout << "list2 = " << list2.to_string() << endl;

    cout << "\nlist1.insert(50,10);\nlist1.insert(0,0)\n";
    cout << "list1.remove(1);\n";
    list2[2] = 100;
    list1.insert(50, 10);
    list1.insert(0, 0);
    list1.remove(1);
    cout << "list2 = " << list2.to_string() << endl;
    cout << "list1 = " << list1.to_string() << endl;

    cout << "\nlist3 new empty\n";
    List<int> list3;
    cout << "list3 size = " << list3.length() << endl;
    if (list3.isEmpty())
        cout << "list3 empty\n";
    else
        cout << "list3 not empty\n";

    cout << "\nlist3 = list1+list2\n";
    list3 = list1 + list2;
    cout << "list3 = " << list3.to_string() << endl;

    cout << "list3 size = " << list3.length() << endl;
    if (list3.isEmpty())
        cout << "list3 empty\n";
    else
        cout << "list3 not empty\n";

    cout << "\nlist3.clear()\n";
    list3.clear();

    cout << "list3 size = " << list3.length() << endl;
    if (list3.isEmpty())
        cout << "list3 empty\n";
    else
        cout << "list3 not empty\n";
    return 0;
}