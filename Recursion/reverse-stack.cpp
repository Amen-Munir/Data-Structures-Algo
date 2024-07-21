#include<iostream>
#include<stack>
using namespace std;
void reverseStack(stack<int> &s1)
{
    if(s1.empty())
    {
        return;
    }
    else
   { int temp=s1.top();
    s1.pop();
    return reverseStack(s1);
    s1.push(temp);
    }
}
int main()
{
stack<int> s1;
s1.push(10);
s1.push(20);
s1.push(30);
s1.push(40);
s1.push(50);
reverseStack(s1);
while(s1.empty()==false)
{
    cout<<s1.top()<<" ";
    s1.pop();
}
}