#include <iomanip>
#include <math.h>
#include <sstream>
#include <iostream> 
using namespace std;

#define DEFAULT_LIST_CAPACITY 10

template <class T>
class List
{
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

	friend ostream &operator<<(ostream &os, List<T> &mylist)
	{
		for (int i = 0; i < mylist.size; i++)
			os << mylist.list[i] << " ";
		return os;
	}

private:
	T *list;	  // the pointer for the dynamic array
	int capacity; // the size of the array
	int size;	  // the number of items in the list

	void reallocate(void)
	{
		capacity = capacity * 2;
		T *newlist = new T[capacity];
		for (int i = 0; i < size; i++)
			*(newlist + i) = *(list + i);
		delete[] list;
		list = newlist;
	}
};

template <class T>
	List<T>::List	(void)
{
	capacity = DEFAULT_LIST_CAPACITY;
	list = new T[DEFAULT_LIST_CAPACITY];
	size = 0; 
}


//======================================================
// Destructor
// PARAMETERS: none
// RETURN: none but returns the array to the free store
//======================================================
template <class T>
	List<T>::~List		( void )
{
	delete [] list; 
}


//=================================================
// to_string
// PARAMETERS: none
// RETURN VALUE:
// values in the list separated by a space in between 
//=================================================

template <class T>
string	List<T>::to_string ( void ) const
{
	stringstream stream;
	for (int i=0; i<size; i++) 
		stream << *(list+i) << " ";
	stream << " size: " << size << " cap: " << capacity; 
	return stream.str(); 
} 


//======================================================
// append
// - appends a new item to the end of the list 
// PARAMETERS: const reference to item of type T 
// RETURN: none but adds new item to the last spot in
//	   list and increment size by 1
//======================================================
template <class T>
void	List<T>::append		( const T &item)
{
	if (size==capacity)
	{
		reallocate(); 
	}
	*(list+size) = item; 
	size++; 
}

//======================================================
// Copy Constructor 
// - performs deep copy 
// PARAMETERS: const reference to mylist 
// RETURN: none but copies the size, capacity and values
//	   of the parameter to the caller of the function 
//======================================================
template <class T>
	List<T>::List	( const List<T> &mylist )
{
	capacity = mylist.capacity; 
	size = mylist.size; 
	list = new T[mylist.capacity]; 
	for (int i=0; i<mylist.size; i++)
		*(list+i) = *(mylist.list+i);

}


//======================================================
// operator=
// list1 = list2
// PARAMETERS: const reference to mylist 
// RETURN: capacity, size and every value in mylist is 
//	   assigned to *this. Then *this is returned
//======================================================
template <class T>
List<T> List<T>::operator=	( const List<T> &mylist )
{
	delete [] list; 
	capacity = mylist.capacity; 
	size = mylist.size; 
	list = new T[mylist.capacity]; 
	for (int i=0; i<mylist.size; i++) 
		*(list+i) = *(mylist.list+i); 
	return *this; 
}


//======================================================
// isEmpty
// PARAMETERS: none
// RETURN: true of the list is empty, false otherwise 
//======================================================
template <class T>
bool	List<T>::isEmpty		( void ) const
{
	return (size==0);
}


//======================================================
// length
// PARAMETERS: none
// RETURN: size of the list as an integer
//======================================================
template <class T>
int	List<T>::length		( void ) const
{
	return size; 

}


//======================================================
// clear
// PARAMETERS: none
// RETURN: none but deletes the existing list and 
// 	   creates a new one with the same capacity and
//	   size set to 0 
//======================================================
template <class T>
void	List<T>::clear		( void )
{
	size=0; 
	delete [] list; 
	list = new T[capacity];
		
}

//======================================================
// operator+
// list1 = list2 + list3
// PARAMETERS: const reference to mylist 
// RETURN: a list object whose size and capacity is the
//		   sum of its addends. The new list contains values
//		   from the first addend followed by the second
//======================================================
template <class T>
List<T> List<T>::operator+	( const List<T> &mylist ) const
{
	List<T> result; 
	result.capacity = capacity + mylist.capacity; 
	result.size = 0; 
	result.list = new T [result.capacity]; 
	for (int i=0; i<size; i++) 
	{
		//cout<< *(list+i) << ","; 
		result.append(*(list+i));
	} 
	for (int j=0; j<mylist.size; j++)
	{
		//cout<< *(mylist.list+j) << ","; 
		result.append(*(mylist.list + j));
	}
	return result; 
	
}


//======================================================
// insert
// PARAMETERS: const reference to item & int index 
// RETURN: none, but inserts item into the correct position
//		   and shifts the items that comes after (int index)
//		   one unit to the right 
//======================================================
template <class T>
void	List<T>::insert		( const T &item, int index )
{
	if (index <0 || index>size) throw std::invalid_argument( "Invalid index" );
	size++; 
	if (size==capacity) reallocate(); 
	for (int i=size-1; i>index; i--) 
		*(list+i) = *(list+i-1);
	*(list+index) = item; 
	
}


//======================================================
// remove
// PARAMETERS: const reference to index 
// RETURN: none, but removes the item at specified index
//		   then shift the items after index position 
//		   one unit to the left 
//======================================================
template <class T>
void	List<T>::remove		( int index )
{
	if (index <0 || index>size-1) throw std::invalid_argument( "Invalid index" );
	size--; 
	for(int i=index; i<size; i++) 
		*(list+i) = *(list+i+1);
	 
}

//======================================================
// operator[]
// PARAMETERS: const reference to index 
// RETURN: none, but returns value at specified index
// Raises error if the index is invalid (out of bounds)
//======================================================
template <class T>
T &	List<T>::operator[]	( int index )
{
	if (index <0 || index>size-1) throw std::invalid_argument( "Invalid index" ); 
	return*(list+index); 

} 

int main ( void )
{
	List<int>	list1;
	cout << "list1 = " << list1 << endl;
	
	for ( int i = 1; i <= 10; i++ )
		list1.append(i);

	cout << "list1 = " << list1 << endl;

	List<int> list2(list1);
	cout << "list2 = " << list2 << endl;
	
	cout << "\nlist1.insert(50,10);\nlist1.insert(0,0)\n";
	cout << "list1.remove(1);\n"; 
	list2[2] = 100;
	list1.insert(50,10);
	list1.insert(0,0);
	list1.remove(1);
	cout << "list2 = " << list2 << endl;
	cout << "list1 = " << list1 << endl;
	
	cout << "\nlist3 new empty\n";
	List<int> list3;
	cout << "list3 size = " << list3.length() << endl;
	if ( list3.isEmpty() )
		cout << "list3 empty\n";
	else
		cout << "list3 not empty\n";

	cout << "\nlist3 = list1+list2\n";
	list3 = list1 + list2;
	cout << "list3 = " << list3.to_string() << endl;
	
	
	cout << "list3 size = " << list3.length() << endl;
	if ( list3.isEmpty() )
		cout << "list3 empty\n";
	else
		cout << "list3 not empty\n";

	cout << "\nlist3.clear()\n";
	list3.clear();

	cout << "list3 size = " << list3.length() << endl;
	if ( list3.isEmpty() )
		cout << "list3 empty\n";
	else
		cout << "list3 not empty\n";
	return 0;
}

