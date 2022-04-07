//
// Created by keraw on 4/5/2022.
//
#include <iostream>
#include <ostream>
#include "IntList.h"

IntList::IntList(){                 //works
    dummyHead = new IntNode(0);
    dummyTail =new IntNode(0);

    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

IntList::~IntList(){               //works
    IntNode* next = dummyHead->next;
    IntNode* curr = dummyHead;

    while (next != nullptr)
    {
        delete curr;
        curr = next;
        next = next->next;
    }

    delete curr;
    curr = nullptr;
    next = nullptr;
}

void IntList::push_front(int value){        //works
    IntNode* temp = new IntNode(value);
    temp->next = dummyHead->next;
    dummyHead->next->prev = temp;
    temp->prev = dummyHead;
    dummyHead->next = temp;
}
void IntList::pop_front(){                  //works
    if (dummyHead != dummyTail)
    {
        IntNode* temp = dummyHead->next;
        temp->next->prev = dummyHead;
        dummyHead->next = temp->next;
        delete temp;
        temp = nullptr;
    }
}
void IntList::push_back(int value)         //works
{
    IntNode* temp = new IntNode(value);
    temp->next = dummyTail;
    temp->prev = dummyTail->prev;
    dummyTail->prev->next = temp;
    dummyTail->prev = temp;
}
void IntList::pop_back()                        //works
{
    if (dummyTail->prev != dummyHead)
    {
        IntNode* temp = dummyTail->prev;
        dummyTail->prev = temp->prev;
        temp->prev->next = dummyTail;
        delete temp;
        temp = nullptr;
    }
}
bool IntList::empty() const {               //works
    if (dummyHead->next == dummyTail)
    {
        return true;
    }

    return false;
}

ostream& operator<<(ostream& out, const IntList& rhs)      //works
{
    IntNode* curr = rhs.dummyHead->next;

    while (curr != rhs.dummyTail)
    {
        out << curr->data;

        if (curr->next != rhs.dummyTail)
        {
            out << " ";
        }

        curr = curr->next;
    }

    return out;
}

void IntList::printReverse() const {                //works
    if (dummyTail->prev != nullptr)
    {
        IntNode* curr = dummyTail->prev;

        while (curr != dummyHead)
        {
            cout << curr->data;

            if (curr->prev != dummyHead)
            {
                cout << " ";
            }

            curr = curr->prev;
        }
    }
}
