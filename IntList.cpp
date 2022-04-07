//
// Created by keraw on 4/5/2022.
//
#include <iostream>
#include <ostream>
#include "IntList.h"

IntList::IntList(){
    dummyHead = new IntNode(0);
    dummyTail =new IntNode(0);

    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

IntList::~IntList(){
    if (dummyHead == nullptr && dummyTail == nullptr) {
        return;
    }
    
}

void IntList::push_front(int value){        //works
    IntNode* temp = new IntNode(value);
    temp->next = dummyHead->next;
    dummyHead->next->prev = temp;
    temp->prev = dummyHead;
    dummyHead->next = temp;
}
void IntList::pop_front(){                  //To do
    std::cout << "WRITE ME: pop_front" << endl;
}
void IntList::push_back(int value)         //To do
{
    std::cout << "WRITE ME: push_back()" << endl;
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

ostream& operator<<(ostream& out, const IntList& rhs)      //To do
{
    out << "WRITE ME: operator<<" << endl;
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
