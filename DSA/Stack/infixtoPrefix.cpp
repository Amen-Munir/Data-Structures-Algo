#include<iostream>
#include <stack>
#include <algorithm>

using namespace std;
int precedenceCheck(char c)
{
    if(c=='^')
        return 3;
else if(c=='*'|| c=='/')
{
        return 2;

}
else if( c=='+'|| c=='-')
{
        return 1;

}
else
return -1;



}
string infixToPreFix(string str1)
{
    int size = str1.length();
    stack<char> st;
    string output = " ";
      reverse(str1.begin(), str1.end());

    for (int i = 0; i < size; i++)
    {
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z'))
        {
           output += " ";
           output += str1[i];
        }
        else if (str1[i] == ')')
        {
            
            st.push(str1[i]);
        }
        else if (str1[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                output += " ";
                output += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && precedenceCheck(st.top()) >= precedenceCheck(str1[i]))
            {
              output += " ";
                output += st.top();
                st.pop();
            }
            st.push(str1[i]);
        }
    }

    while (!st.empty())
    {
        output += " ";
        output += st.top();
        st.pop();
    }
   
    reverse(output.begin(), output.end());
    return output;
}

int main()
{
    cout << "Enter Expression in infix" ;
    cout << endl;
    string st;
    getline(cin, st);
    cout << "\n CONVERTING TO PREFIX : "<<endl;
                                      cout
         << infixToPreFix(st);
}
