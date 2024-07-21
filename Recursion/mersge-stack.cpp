#include<iostream>
using namespace std;
#include<stack>
void Sort(stack<int> &s1, int x)
{
    if(s1.empty())
    {
        return;
    }
    else if(x<s1.top())
    {
 int temp= s1.top(); 
        s1.pop();
        Sort(s1, x);
        s1.push(temp);
    }
    else
    {
        s1.push(x);
    }
}
void mergeStacks(stack<int>&s1, stack<int>&s2)
{
    if(s2.empty())
    {
        return;
    }
int x=s2.top();
s2.pop();
mergeStacks(s1,s2);
Sort(s1,x);

}
int main() {
    stack<int> s1,s2;
    s1.push(1);
    s1.push(3);
    s1.push(52);
    s2.push(20);
    s2.push(4);
    s2.push(16);
    mergeStacks(s1, s2);
    while (!s1.empty()) {
        int temp = s1.top();
        s1.pop();
        s2.push(temp);
    }
    while (!s2.empty()) {
        cout << s2.top() << endl;
        s2.pop();
     ;
    }
    return 0;
}
