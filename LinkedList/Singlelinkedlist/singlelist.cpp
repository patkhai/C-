//
//  singlelist.cpp
//  Singlelinkedlist
//
//  Created by Pat Khai on 7/13/17.
//  Copyright © 2017 Pat Khai. All rights reserved.
//

#include "singlelist.hpp"

using namespace std;

//Default Constructor
singlelist::singlelist() {
    head = NULL;
}

//Copy Constructor
singlelist::singlelist(singlelist &list) {
    node* n = list.head;
    while (n != NULL) {
        pushBack(n->data);
        n = n->next;
    }
}

//Destructor
singlelist::~singlelist() {
    if (head == NULL)
        return;
    node* temp = NULL;
    while (head != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

//Overloaded Assignment Operator
singlelist& singlelist::operator=(const singlelist& rhs) {
    head = rhs.head;
    return *this;
}

//To insert a node at the front of the list
void singlelist::pushFront(double data1)
{
    node* temp = head;
    if (temp == NULL) {
        head = new node;
        head->data = data1;
        head->next = NULL;
    }
    else
    {
        head = new node;
        head->data = data1;
        head->next = temp;
    }
}

//To appends a node at the back of the list
void singlelist::pushBack(double data1)
{
    node* temp = head;
    if (temp == NULL)
    {
        head = new node;
        head->data = data1;
        head->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        node* last = new node;
        last->data = data1;
        last->next = NULL;
        temp->next = last;
    }
    
}

//To remove the first node of the list
node* singlelist::popFront()
{
    node* temp = head;
    if (temp == NULL)
    {
        temp = new node;
        temp->data = NULL;
        return temp;
    }
    temp = head->next;
    node* front = head;
    head->next = NULL;
    head = temp;
    return front;
}

//To remove the last node of the list
node* singlelist::popBack()
{
    node* temp = head;
    if (temp == NULL)
    {
        temp = new node;
        temp->data = NULL;
        return temp;
    }
    else if (temp->next == NULL) {
        head = NULL;
        return temp;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node* back = temp->next;
    temp->next = NULL;
    return back;
}

//To insert a new node at the specific position
int singlelist::insert(double index, double val)
{
    node* temp = head;
    node* add = new node;
    if (temp == NULL)
    {
        head = new node;
        head->data = val;
        head->next = NULL;
        return 1;
    }
    else if (index == 1)
    {
        add->data = val;
        add->next = temp;
        head = add;
        return 1;
    }
    else
    {
        int i = 1;
        while (temp->next != NULL)
        {
            if (i == (index - 1)) {
                add->data = val;
                add->next = temp->next;
                temp->next = add;
                return i + 1;
            }
            i++;
            temp = temp->next;
        }
        add->data = val;
        add->next = NULL;
        temp->next = add;
        return i + 1;
    }
}

//To trace and delete all the duplicates within the list
void singlelist::deleteDuplicates(double val)
{
    node* temp = head;
    if (temp == NULL) {}
    else
    {
        node* before = temp;
        while (temp->next != NULL)
        {
            if (temp == head && temp->data == val)
            {
                head = temp->next;
                temp = head;
            }
            else if (temp->data == val)
            {
                node* after = temp->next->next;
                before = temp->next;
                before->next = after;
                temp = before->next;
            }
            else
            {
                before = temp;
                temp = temp->next;
            }
        }
        if (temp->data == val)
        {
            if (temp == head)
            {
                head = NULL;
            }
            else
            {
                before->next = NULL;
            }
        }
    }
}

//To return the last element of the list
node* singlelist::mtoLastElement(double m)
{
    node* temp = head;
    if (m > size() - 1)
    {
        temp = new node;
        temp->data = NULL;
        return temp;
    }
    for (int i = 0; i < (size()-m-1); i++) {
        temp = temp->next;
    }
    return temp;
}

//To return the size of the list
int singlelist::size()
{
    int size = 0;
    if (head == NULL)
    {
        return size;
    }
    node* temp = head;
    while (temp->next != NULL) {
        size++;
        temp = temp->next;
    }
    size++;
    return size;
}

//To print out all the data items stored in the list
ostream& operator<<(ostream& out, const singlelist& list) {
    node* temp = list.head;
    if (temp == NULL) {
        out << "Empty list";
    }
    else
    {
        while (temp->next != NULL)
        {
            out << temp->data << " -> ";
            temp = temp->next;
        }
        out << temp->data << " -> NULL";
    }
    return out;
}

//To reverse the entire linked list
void singlelist::reverseList()
{
    node* current = head;
    if (current == NULL) 
    {
        return;
    }
    node* beforeNode = NULL;
    node* tempNextNode = NULL;
    while(current->next != NULL)
    {
        tempNextNode = current->next;
        current->next = beforeNode;
        beforeNode = current;
        current = tempNextNode;
    }
    current->next = beforeNode;
    head = current;
}


