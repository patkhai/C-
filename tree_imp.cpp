#include <stdio.h>
#include<iostream>
#include "tree.h"
using namespace std;

//default constructor
Tree::Tree()
{
    start = NULL;
}

//copy constructor
// must make the first node be nullpointer or copy constructor will never work!
Tree::Tree(const Tree& other) :start(NULL)
{
    //sent to private data
    copyOther(other);
}

//destructor
Tree::~Tree()
{
    clear();
}

// overloaded Assignment operator
Tree& Tree::operator=(const Tree& other)
{
    //check to see if they equal each other
    if (this != &other)
    {
        //delete last list
        clear();
        
        //copy the other list
        copyOther(other);
        
    }
    
    //returns pointer to object
    return *this;
}

// creates node and inserts it at appropriate position.
void Tree::push(int value)
{
    
    TreeNode* N1 = new TreeNode();
    N1->value = value;
    
    // if this is the first number, make it the root
    if (start == NULL)
    {
        start = N1;
        return;
    }
    
    //like insertNode, push value into tree with node and value
    pushFrom(start, N1);
}

// Returns the address of the node containing the value.
TreeNode* Tree::find(int value)const
{
    //implement the find from function
    return findFrom(start, value);
}

// Print the tree data
void Tree::print() const
{
    printFrom(start, 0);
}

void Tree::deleteNode(int value)
{
    ///helper funciton of deleteFrom
    deleteFrom(start, value);
}


void Tree::copyOther(const Tree& other)
{
    //send to private data
    copyFrom(other.start);
}

//delete all the nodes and free memory
void Tree::clear()
{
    if (start == NULL)
    {
        return;
    }
    
    clearFrom(start);
}

// Recursively push a single element into a tree.
void Tree::pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush)
{
    if (startingPoint->value < nodeToPush->value)
    {
        //check to seee if the left side is empty
        if (startingPoint->right == NULL)
        {
            startingPoint->right = nodeToPush;
        }
        else
        {
            //continue to traverse through the list
            pushFrom(startingPoint->right, nodeToPush);
        }
    }
    else
    {
        if (startingPoint->left == NULL)
        {
            startingPoint->left = nodeToPush;
        }
        else
        {
            //continue to traverse through the list
            pushFrom(startingPoint->left, nodeToPush);
        }
    }
}

// Recursively find a single element in a tree.
TreeNode* Tree::findFrom(TreeNode* startingPoint, int value) const
{
    //check if list is empty
    if (startingPoint == NULL)
    {
        //cout << "That value does not exist. \n";
        return NULL;
    }
    
    //basecase
    if (startingPoint->value == value)
    {
        return startingPoint;
    }
    //recuriseve statments
    else if (value < startingPoint->value)
    {
        return findFrom(startingPoint->left, value);
    }
    else
    {
        return findFrom(startingPoint->right, value);
    }
}

//Recursively print the values in a tree.
void Tree::printFrom(TreeNode* startintPoint, int numSpaces) const
{
    // base case
    if (startintPoint == NULL)
    {
        return; // type void so we dont return anyting
    }
    
    for (int i = 0; i < numSpaces; i++)
    {
        cout << " ";
    }
    
    cout << startintPoint->value << endl;
    
    numSpaces = numSpaces + 2;
    printFrom(startintPoint->left, numSpaces);
    printFrom(startintPoint->right, numSpaces);
}

//Recursively copy another tree's nodes.
void Tree::copyFrom(TreeNode* startintPoint)
{
    if (startintPoint == NULL)
    {
        return;
    }
    
    push(startintPoint->value);
    copyFrom(startintPoint->left);
    copyFrom(startintPoint->right);
}

// Recursively delete nodes.
void Tree::clearFrom(TreeNode* startingPoint)
{
    //check if its already empty
    if (startingPoint == NULL)
    {
        return;
    }
    
    clearFrom(startingPoint->left);
    clearFrom(startingPoint->right);
    
    delete startingPoint;
    start = NULL;
}


// Deletes the node with the value specified in the below function.
void Tree::deleteFrom(TreeNode* startintPoint, int value)
{
    //deleting a node
    TreeNode* parentNode = startintPoint;
    
    if (NULL == startintPoint)
    {
        return;
    }
    else if (value > startintPoint->value)
    {
        
        deleteFrom(startintPoint->left, value);
    }
    else if (value > startintPoint->value)
    {
        
        deleteFrom(startintPoint->right, value);
    }
    else
    {
        if(startintPoint->left == NULL && startintPoint->right != NULL){
            TreeNode* temp1 = startintPoint;
            parentNode->right = startintPoint->right;
            delete temp1;
            temp1 = NULL;
            
        }
        else if(startintPoint->right == NULL && startintPoint->left != NULL){
            TreeNode* temp1 = startintPoint;
            parentNode->left = startintPoint->right;
            delete temp1;
            temp1 = NULL;
        }
        else if(startintPoint->left != NULL && startintPoint->right != NULL){
            TreeNode* temp3 = startintPoint->left;
            while(temp3->right != NULL){
                temp3 = temp3->right;
            }
            startintPoint->value = temp3->value;
            deleteFrom(startintPoint->left, temp3->value);
            
        }
        
    }
}

