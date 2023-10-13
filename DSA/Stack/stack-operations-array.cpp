#include<iostream>
using namespace std;
class Cstack
{
    int top;
    public:
    int max_size;
    int *arr;
    
    Cstack(int size)
    {
        max_size = size;
        arr = new int[max_size];
        top=-1;
    }
    bool isFull()
    {
        if(top==max_size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool push(char val)
    {
        if(top<0)
        {
            cout<<"Stack is empty"<<endl;
            return false;

        }
        else if (isFull())
        {
            cout << "Stack is full";
            return false;
        }

        else
        {
            top++;
            arr[top] = val;
            return true;
        }
    }
  char pop()
    {
        if(top<0)
        {
            cout << "List is empty" << endl;
            return false;
        }
        else
        {
           char data = arr[top];
            top--;
            return data;
        }
    }
    
    bool isEmpty()
    {
        if(top<0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int Top()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else
        {
            return arr[top];
        }
    }

    bool isBalanced(string data)
    {
        int length=data.length();
        Cstack s(length);
        for (int i = 0; i < length;i++)
        {
            if (data[i] == '('|| data[i]=='{'|| data[i]=='[')
            {
                push(data[i]);

            }
            else if (isEmpty() || (data[i] == ')' && Top() != '(') || (data[i] == '}' && Top() != '{') || (data[i] == ']' && Top() != '['))
            {
                return false;
            }
            else if (data[i] == ')' || data[i] == '}' || data[i] == ']')
            {
                pop();
                
            }
        
        }
        if(isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
int main()
{
    Cstack obj1(10);
    obj1.isBalanced("({[]})");	
}