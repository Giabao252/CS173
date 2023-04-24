#include <iomanip>
#include <math.h>
#include <sstream>
#include <iostream>
using namespace std;

template <class T>
class List
{
private:
    // struct for Node for linked list
    struct Node
    {
        T item;
        Node *next;
    };

    Node *head; // the pointer for the linked list

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
        Node *ptr = mylist.head;
        while (ptr != NULL)
        {
            if (ptr->next != NULL)
                os << ptr->item << " ";
            else
                os << ptr->item;
            ptr = ptr->next;
        }

        return os;
    }
};

// #########################################################################################################

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
        Node *next_node;

        while (head != NULL)
        {
            next_node = head->next;
            delete head;
            head = next_node;
        }

        head = NULL;

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
}

template <class T>
void List<T>::append(const T &item) {
    Node* ptr;
    Node* ptr2;

    ptr = new Node;
    ptr->item = item;
    ptr->next = NULL

    if (head == NULL) {
        head = ptr;
    }
    else {
        ptr2 = head;
        while(ptr2->next != NULL) {
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr;
        
    }
}

template <class T> 
int List<T>::length(void) const {
    int size = 0;
    while (head->next != NULL) {
        head = head->next;
        size++
    }
    return size;
}

// #########################################################################################################

int main(void)
{
    List<int> list1;
    cout << "list1 = " << list1 << endl;

    for (int i = 1; i <= 10; i++)
        list1.append(i);

    cout << "list1 = " << list1 << endl;

    List<int> list2(list1);
    cout << "list2 = " << list2 << endl;

    cout << "\nlist1.insert(50,10);\nlist1.insert(0,0)\n";
    cout << "list1.remove(1);\n";
    list2[2] = 100;
    list1.insert(50, 10);
    list1.insert(0, 0);
    list1.remove(1);
    cout << "list2 = " << list2 << endl;
    cout << "list1 = " << list1 << endl;

    cout << "\nlist3 new empty\n";
    List<int> list3;
    cout << "list3 size = " << list3.length() << endl;
    if (list3.isEmpty())
        cout << "list3 empty\n";
    else
        cout << "list3 not empty\n";

    cout << "\nlist3 = list1+list2\n";
    list3 = list1 + list2;
    cout << "list3 = " << list3 << endl;

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