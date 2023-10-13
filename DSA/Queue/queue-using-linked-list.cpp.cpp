#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int n)
	{
		data = n;
		next = NULL;

	}
};
class Queue
{
    public:
        node *front;
        node *rear;
    
    Queue()
    {
        front = NULL;
        rear = NULL;

    }
    bool Enque(int n)
    {
       node* new_node = new node(n);
		if (rear == NULL)
		{
			rear = new_node;
            front = new_node;
        }
		else
		{
            rear->next = new_node;
            rear = new_node;
        }
    }
    int Dequeu()
    {
        if(isEmpty()==true)
        {
            cout << "Queue is Empty!" << endl;
            return 0;

        }
        else
        {
            int temp = front->data;
            node *p = front;
            front = front->next;
            delete p;
            return temp;

        }
    }

    void display()
    {
        node *temp = front;
        while(temp!=NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
    }
    bool isEmpty()
    {
        return front == NULL;
    }

};
int main(){
    Queue object;
    object.Enque(50);
     object.Enque(60);
     object.Enque(70);
     cout << "current queue is : ";
     object.display();
     cout << endl;
     cout << object.Dequeu() << " ";
     cout << object.Dequeu() << " ";
     cout << object.Dequeu() << " ";
    cout << object.Dequeu() << " ";
}
