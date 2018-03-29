//
//  singlelist.hpp
//  Singlelinkedlist
//
//  Created by Pat Khai on 7/13/17.
//  Copyright © 2017 Pat Khai. All rights reserved.
//

#ifndef singlelist_hpp
#define singlelist_hpp

#include<iostream>
using namespace std;

struct node {
    double data;
    node* next;
};

class singlelist {
    
private:
    node* head;
    
public:
    singlelist();
    singlelist(singlelist &list);
    ~singlelist();
    void pushFront(double data1);
    void pushBack(double data1);
    node* popFront();
    node* popBack();
    int insert(double index, double val);
    void deleteDuplicates(double val);
    node* mtoLastElement(double m);
    int size();
    friend ostream& operator<<(ostream& out, singlelist const& rhs);
    void reverseList();
    singlelist& operator=(const singlelist& rhs);
};

#endif /* singlelist_hpp */
