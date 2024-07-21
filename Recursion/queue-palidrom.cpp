#include<iostream>
using namespace std;
#include<queue>
bool isPalindrom(queue<int> q1,int size)
{
    if(size==0)
    {
        return true;
    }
    else if(q1.front()!=q1.back()){
        return false;
    }
    
}