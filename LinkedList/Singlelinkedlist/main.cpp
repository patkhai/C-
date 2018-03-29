//
//  main.cpp
//  Singlelinkedlist
//
//  Created by Pat Khai on 7/13/17.
//  Copyright © 2017 Pat Khai. All rights reserved.
//

#include <iostream>
#include "singlelist.hpp"

using namespace std;
int main()
{
    singlelist obj;
    int options;
    unsigned int index;
    double data;
    node* temp;
    while (1)
    {
        cout << "Implementation of Single Linked List ADT to store Collection of Doubles" << endl;
        cout << "1. Insert a Node at front of the list" << endl;
        cout << "2. Append a Node at back of the list" << endl;
        cout << "3. Remove a Node at Front-end" << endl;
        cout << "4. Remove a Node at Back-end" << endl;
        cout << "5. Insert a New Node at a position" << endl;
        cout << "6. Deletes The Duplicate Element From The List" << endl;
        cout << "7. Returns Element In Position Relative To Last Element of The List" << endl;
        cout << "8. Determines The Size Of List" << endl;
        cout << "9. Print All Data items" << endl;
        cout << "10. Reverse of Linked List" << endl;
        cout << "11. Exit" << endl;
        cout << "Select one choice eg. 1 or 2 : " << endl;
        scanf("%d", &options);
        switch (options)
        {
            case 1:
                cout << "\nEnter the Data To insert at Front eg(double values):" << endl;
                while (!(cin >> data) || cin.get() != '\n') {
                    cout << "Invalid Input." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                obj.pushFront(data);
                cout << "New Node Inserted successfully at the beginning" << endl;
                cout << "----------------------------------------" << endl;
                cout << "New List:" << endl;
                cout << obj << endl;
                cout << endl;
                break;
            case 2:
                cout << "\nEnter the Data To insert at Back:" << endl;
                cin >> data;
                while (!(cin >> data) || cin.get() != '\n') {
                    cout << "Invalid Input." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                obj.pushBack(data);
                cout << "New Node Inserted successfully at the end" << endl;
                cout << "----------------------------------------" << endl;
                cout << "New List:" << endl;
                cout << obj << endl;
                cout << endl;
                break;
            case 3:
                cout << "\nThe list before popFront:" << endl;
                cout << obj << endl;
                temp = obj.popFront();
                if (temp->data == NULL)
                    cout << "Popped: NULL " << endl;
                else
                    cout << "Popped: " << temp->data << endl;
                cout << "The list after popFront:" << endl;
                cout << obj << endl;
                cout << endl;
                break;
            case 4:
                cout << "\nThe list before popBack:" << endl;
                cout << obj << endl;
                temp = obj.popBack();
                if (temp->data == NULL)
                    cout << "Popped: NULL " << endl;
                else
                    cout << "Popped: " << temp->data << endl;
                cout << "The list after popBack:" << endl;
                cout << obj << endl;
                cout << endl;
                break;
            case 5:
                cout << "\nEnter the position to insert the New Node:" << endl;
                cin >> index;
                while (!(cin >> index) || cin.get() != '\n' || index <= 0) {
                    cout << "Invalid Input." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                cout << "Enter The Data" << endl;
                cin >> data;
                while (!(cin >> data) || cin.get() != '\n') {
                    cout << "Invalid Input." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                index = obj.insert(index, data);
                cout << "New Node Inserted successfully at position " << index << endl;
                cout << "----------------------------------------" << endl;
                cout << "New List:" << endl;
                cout << obj << endl;
                cout << endl;
                break;
            case 6:
                cout << "\nEnter The data to remove" << endl;
                cin >> data;
                while (!(cin >> data) || cin.get() != '\n') {
                    cout << "Invalid Input." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                cout << "The list before removing all " << data << endl;
                cout << obj << endl;
                obj.deleteDuplicates(data);
                cout << "The list after removing all " << data << endl;
                cout << obj << endl;
                cout << endl;
                break;
            case 7:
                cout << "\nEnter The position relative to  the Last Element to return" << endl;
                cin >> index;
                while (!(cin >> index) || cin.get() != '\n' || index <= 0) {
                    cout << "Invalid Input." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                temp = obj.mtoLastElement(index);
                if (temp->data == NULL)
                    cout << "Returned: NULL " << endl;
                else
                    cout << "Returned: " << temp->data << endl;
                cout << "The list: " << endl;
                cout << obj << endl;
                cout << endl;
                break;
            case 8:
                cout << "\nThe Size of List: " << obj.size() << endl;
                cout << endl;
                break;
            case 9:
                cout << "\n----------------------------------------" << endl;
                cout << "The Data Element Present in the list " << endl;
                cout << obj << endl;
                cout << endl;
                break;
            case 10:
                cout << "\nThe double linked list order is:" << endl;
                cout << obj << endl;
                obj.reverseList();
                cout << "Reverse order of double linked list is:" << endl;
                cout << obj << endl;
                cout << endl;
                break;
            case 11:
                exit(0);
            default:
                cout << "\nWrong choice Select Correct Option" << endl;
                
        }
    }
    return 0;
}

