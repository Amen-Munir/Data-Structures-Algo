#include<iostream>
using namespace std;
class Node
{
    public:
    char data;
    Node *next;
};
class linked_list
{
    public:
    Node *top;
    linked_list()
    {
        top=NULL;
    }

    bool push(int n)
    {
        Node *new_node= new Node();
        new_node->data = n;
        new_node->next = top;
        top = new_node;
        return true;
    }
    int pop()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return false;
        }
        else
        {
            Node *temp = top;
            top=top->next;
            int data = temp->data;
            delete temp;
            return data;
        }
    }

   bool isEmpty()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return true;
        }
        else
        {
            cout<<"Stack is not empty"<<endl;
            return false;

        }
    }
};
int main()
{
    linked_list l1;
    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.push(4);
   cout<< l1.pop()<<endl;
     cout<< l1.pop()<<endl;
      cout<< l1.pop()<<endl;
       cout<< l1.pop()<<endl;
      

    l1.isEmpty();
    return 0;
}
