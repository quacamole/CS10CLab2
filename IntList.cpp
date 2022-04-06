//
// Created by keraw on 4/5/2022.
//

#include "IntList.h"

IntList()
: dummyHead(nullptr), dummyTail(nullptr) {}

~IntList(){
    if (dummyHead == nullptr && dummyTail == nullptr) {
        return;
    }
    
}
void push_front(int value);
void pop_front();
void push_back(int value);
void pop_back();
bool empty() const;

friend ostream & operator<<(ostream &out, const IntList &rhs);
void printReverse() const;