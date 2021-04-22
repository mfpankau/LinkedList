#include <iostream>
#include <string>
using namespace std;


namespace bad
{
    struct Node
    {
        int index;
        void* value;
        Node* next;
        Node(void* val) : value(val) {}
    };

    class LList
    {
    public:
        int length;
        Node* n1;
        //create new list with given value as first element
        LList(void* val)
        {
            n1 = new Node(val);
            length = 1;
        }
        //get node by given index
        Node* getNodeByIndex(int index)
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
            Node* curLast = getNodeByIndex(length - 1);
            curLast->next = node;
            curLast->index = length - 1;
            node->index = length;
            length++;
        }
        //add node at given index
        //shifts that current index and everything past it by one
        void add(Node* node, int index)
        {
            Node* prevNode = getNodeByIndex(index - 1);
            Node* nextNode = getNodeByIndex(index);
            prevNode->next = node;
            node->next = nextNode;
            length++;
        }
        //remove element at given index
        void remove(int index)
        {

            Node* itemToRemove = getNodeByIndex(index);
            Node* prevNode = getNodeByIndex(index - 1);
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
    string x = "shrek";
    string n = "bob";
    bad::LList list = bad::LList(&x);
    list.add(new bad::Node(&n));
    list.add(new bad::Node((string*)"stuff2"));
    list.add(new bad::Node((string*)"yes"), 1);
    list.remove(7);
    cout << "length: " << list.length << endl;
    string* temp = (string*)list.getNodeByIndex(0)->value;
    cout << "list 1: " << *(string*)list.getNodeByIndex(0)->value;
    return 0;
}
