#include<iostream>
using namespace std;
int multiplyUsingRecurion(int n1,int n2)
{
    if(n2==0)	
    {
        return 0;
    }
    else
    {
        return n1 + multiplyUsingRecurion(n1, n2-1);
    }
}
int main()
{
    int n1, n2;
    cin >> n2;
    cin >> n1;  
    cout << multiplyUsingRecurion(n1,n2)<<endl;
}

