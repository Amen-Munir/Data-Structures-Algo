#include<iostream>
using namespace std;
string Reverse(string st)
{
    int size=st.length();
    if(size==0)
        return " ";
    else
    return Reverse(st.substr(1,size))+st[0];
    }

int main()
    {
    string s = "1234";
    cout<<Reverse(s);	
    }