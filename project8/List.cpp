#include <iomanip>
#include <math.h>
#include <sstream>
#include <iostream>
#include "List.h"
using namespace std;


template <class T>
List<T>::List(void)
{
    head = NULL;
}

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