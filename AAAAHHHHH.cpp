// AAAAHHHHH.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


namespace bad
{
    struct Node
    {
        int index;
        string value;
        Node* next;
        Node(string val) : value(val) {}
    };

    class LList
    {
    public:
        int length;
        Node* n1;
        //create new list with given value as first element
        LList(string val)
        {
            n1 = new Node(val);
            length = 1;
        }
        //get element by given index
        Node* getElementByIndex(int index)
        {
            if (index > length - 1)
            {
                index = length - 1;
            }
            Node* cur = n1;
            for (size_t i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            cur->index = index;
            return cur;
        }
        //add given node at the end of list
        void add(Node* node)
        {
            Node* curLast = getElementByIndex(length - 1);
            curLast->next = node;
            curLast->index = length - 1;
            node->index = length;
            length++;
        }
        //add node at given index
        //shifts that current index and everything past it by one
        void add(Node* node, int index)
        {
            Node* prevNode = getElementByIndex(index - 1);
            Node* nextNode = getElementByIndex(index);
            prevNode->next = node;
            node->next = nextNode;
            length++;
        }
        //remove element at given index
        void remove(int index)
        {
            
            Node* itemToRemove = getElementByIndex(index);
            Node* prevNode = getElementByIndex(index - 1);
            prevNode->next = itemToRemove->next;
            if (index >= length - 1)
            {
                length--;
                return;
            }
            Node* cur = prevNode->next;
            for (size_t i = 0; i < length - index - 1; i++)
            {
                cur->index = cur->index - 1;
            }
            length--;
            free(itemToRemove);
        }
        //remove last index if no parameter is given
        void remove() { remove(length - 1); }
    };
}

int main()
{
    bad::LList list = bad::LList("7");
    list.add(new bad::Node("stuff"));
    list.add(new bad::Node("stuff2"));
    list.add(new bad::Node("17"), 1);
    list.remove(7);
    cout << "length: " << list.length << endl;
    cout << "list 1: " << list.getElementByIndex(7)->value;
    return 0;
}