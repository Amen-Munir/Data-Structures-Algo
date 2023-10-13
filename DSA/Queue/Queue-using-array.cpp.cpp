#include<iostream>
using namespace std;
class Queue
{
    public:
        int no_elements;
        int rear;
        int front;
        int size=2;
        int que[2];
 Queue()
 {
     rear = -1;
     front = -1;
     no_elements = 0;
 }
  bool isfull()
  {
     return no_elements == size;
  }
 bool isEmpty()
 {
     return no_elements == 0;
 }
 bool Enque(int n)
 { 
    if(!isfull())
    {
        rear++;
        rear = rear % size;
        que[rear] = n;
        no_elements++;
        return true;

    }
    else
    {
        return false;

    }
 }

 int edeque()
 {
   
    if(!isEmpty())
    {
        front++;
        front = front % size;
        int temp = que[front];
        no_elements--;
        return temp;

    }
    else
        return 0;
 }
};
int main()
{
 Queue obj1;
 obj1.Enque(9);
 obj1.Enque(10);
 obj1.Enque(0);

 cout << obj1.edeque() << endl;
 cout << obj1.edeque() << endl;
 cout << obj1.edeque() << endl;


}