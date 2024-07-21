#include<iostream>
using namespace std;
bool is_Palindrom(int i,string s ,int n,int j)
{
    if (i == j)
    {
        return true;
    }
    if (s[i] != s[j])
    {
        return false;
    }
    if (i < j + 1)
    {
        return is_Palindrom( i+ 1, s, n, j - 1);
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    int n=s.length();
    int i = 0;
    int j = n - 1;
    if (is_Palindrom(i, s, n, j))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}