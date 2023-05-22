#include <iomanip>
#include <math.h>
#include <sstream>
#include <iostream>
#include "List.h"
using namespace std;

/*
DEFAULT CONSTRUCTOR -> Creates an empty linked list
PARAMETERS: none
RETURN: none
*/
template <class T>
List<T>::List(void)
{
    head = NULL;
}

/*
DESTRUCTOR 
PARAMETERS: none
RETURN: none
FUNCTIONALITY: freeing the memory allocated to each node in the list when the list is no longer needed
*/

template <class T>
List<T>::~List(void)
{
    Node *next_node;

    while (head != NULL)
    {
        next_node = head->next;
        delete head;
        head = next_node;
    }

    head = NULL;
}

/*
COPY CONSTRUCTOR 
PARAMETERS: const reference to the passed object mylist
RETURN: none
FUNCTIONALITY: performs deep copy on a linked list
*/

template <class T>
List<T>::List(const List<T> &mylist)
{
    Node *new_ptr;
    Node *traverse_ptr;
    Node *ptr;

    if (mylist.head == NULL)
    {
        head = NULL;
    }
    else
    {
        head = new Node;
        traverse_ptr = mylist.head;
        head->item = traverse_ptr->item;
        head->next = NULL;
        ptr = head;
        traverse_ptr = traverse_ptr->next;

        while (traverse_ptr != NULL)
        {
            new_ptr = new Node;
            new_ptr->item = traverse_ptr->item;
            new_ptr->next = NULL;

            ptr->next = new_ptr;
            ptr = ptr->next;

            traverse_ptr = traverse_ptr->next;
        }
    }
}

/*
operator= 
PARAMETERS: const reference to the passed object mylist
RETURN: the existing linked list with all its value replaced by mylist's values
*/

template <class T>
List<T> List<T>::operator=(const List<T> &mylist)
{
    if (this != &mylist)
    {
        clear();

        Node *new_ptr;
        Node *traverse_ptr;
        Node *ptr;

        if (mylist.head == NULL)
        {
            head = NULL;
        }
        else
        {
            head = new Node;
            traverse_ptr = mylist.head;
            head->item = traverse_ptr->item;
            head->next = NULL;
            ptr = head;
            traverse_ptr = traverse_ptr->next;

            while (traverse_ptr != NULL)
            {
                new_ptr = new Node;
                new_ptr->item = traverse_ptr->item;
                new_ptr->next = NULL;

                ptr->next = new_ptr;
                ptr = ptr->next;

                traverse_ptr = traverse_ptr->next;
            }
        }
    }

    return *this;
}

/*
TO_STRING 
PARAMETERS: none
RETURN: a string of the list elements 
*/

template <class T>
string List<T>::to_string(void) const
{
    stringstream stream;

    Node *current = head;

    while (current != NULL)
    {
        stream << current->item;

        if (current->next != NULL)
        {
            stream << ',';
        }

        current = current->next;
    }

    return stream.str();
}

/*
APPEND 
PARAMETERS: const reference to the passed item of any data type
RETURN: none
FUNCTIONALITY: append the passed item to the back of the linked list 
*/

template <class T>
void List<T>::append(const T &item)
{
    Node *ptr;
    Node *ptr2;

    ptr = new Node;
    ptr->item = item;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr2 = head;
        while (ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr;
    }
}

/*
operator[]
PARAMETERS: index of integer type
RETURN: the value in the linked list that corresponds to the given index position
*/

template <class T>
T &List<T>::operator[](int index)
{
    Node *iPtr;
    int index_counter = 0;
    iPtr = head;

    if (index < 0 || index > length() - 1)
    {
        throw std::invalid_argument("Invalid index");
    }
    if (iPtr == NULL)
    {
        throw std::out_of_range("List index out of range");
    }
    while (index_counter < index)
    {
        index_counter++;
        iPtr = iPtr->next;
    }
    return (iPtr->item);
}

/*
INSERT 
PARAMETERS: 
- const reference to the passed item of any data type 
- index of integer type
RETURN: insert a new item in the existing linked list in a specified index position
*/

template <class T>
void List<T>::insert(const T &item, int index)
{
    if (index < 0 || index > length())
    {
        throw std::invalid_argument("Invalid index");
    }

    if (index == 0)
    {
        Node *new_node;
        new_node = new Node;
        new_node->item = item;
        new_node->next = head; // linking the new node to the old first node of the list
        head = new_node;
    }

    else if (index == length())
    {
        append(item);
    }

    else
    {
        Node *current = head;
        int index_counter = 0;

        while (index_counter < index)
        {
            index_counter++;
            current = current->next;
        }
        
        Node *new_node;
        new_node = new Node;
        new_node->item = item;

        new_node->next = current->next;
        current->next = new_node;
    }
}

/*
TO_STRING FUNCTION
PARAMETERS: none
RETURN: a string of the list elements separated by commas
*/

template <class T>
void List<T>::remove(int index)
{
    if (head == NULL)
    {
        throw std::out_of_range("List index out of range");
    }

    if (index < 0 || index > length() - 1)
    {
        throw std::invalid_argument("Invalid index");
    }

    if (index == 0)
    {
        Node *old_head = head;
        head = head->next;
        delete old_head;
    }
    else
    {
        Node *to_delete;
        Node *current = head;
        int index_counter = 0;

        while (index_counter < index-1)
        {
            index_counter++;
            current = current->next;
        }

        to_delete = current->next;
        if (index == length() - 1)
        {
            current->next = NULL;
        }
        else {
            current->next = current->next->next;
            delete to_delete;
        }
    }
}

/*
operator+
PARAMETERS: const reference to the passed object named mylist
RETURN: a new object that is the concatenation of the existing list and mylist
*/

template <class T> 
List<T> List<T>::operator+(const List<T> &mylist) const {
    List<T> concat;

    concat.head = NULL;

    if (head == NULL && mylist.head == NULL) {
        concat.head = NULL;
        return concat;
    }
    else if (mylist.head == NULL) {
        concat = *this;
        return concat;
    }
    else if (head == NULL) {
        concat = mylist;
        return concat;
    }
    else {
        Node* tPtr;
        concat = *this;
        tPtr = concat.head;

        while (tPtr->next != NULL) {
            tPtr = tPtr->next;  
        }

        tPtr->next = mylist.head; 
        return concat;
    }
}

/*
LENGTH 
PARAMETERS: none
RETURN: the length of the list as an integer type 
*/

template <class T>
int List<T>::length(void) const
{
    Node *head_ptr;
    int size = 0;
    head_ptr = head;

    while (head_ptr != NULL)
    {
        size++;
        head_ptr = head_ptr->next;
    }
    return size;
}

/*
ISEMPTY
PARAMETERS: none
RETURN: boolean type - true if the linked list is empty and vice versa
*/

template <class T>
bool List<T>::isEmpty(void) const
{

    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
CLEAR
PARAMETERS: none    
RETURN: none
FUNCTIONALITY: delete the entire linked list 
*/

template <class T>
void List<T>::clear(void)
{
    Node *next_node;

    while (head != NULL)
    {
        next_node = head->next;
        delete head;
        head = next_node;
    }
    head = NULL;
}