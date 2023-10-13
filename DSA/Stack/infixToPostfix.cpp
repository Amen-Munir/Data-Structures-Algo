#include<iostream>
#include <stack>
//#include<algorithim>

using namespace std;
int precedenceCheck(char c) 
{  
    
    if(c=='<')  //precedence check karnay k liye values assign kardi 
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
string infixToPostFix(const string str1)
{

    int size = str1.length(); //ye length ka function laga k hum
    //us ki length compute karnay ka 
    stack<char> st;
    string output = "";  //this is the string that is containing the output espression 
    
    for (int i = 0; i < size; i++)
    { 

        //pehla case ye check huraha hay k jo value iterate hui hay wo koi opeand tu  nai hay
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z'))
        {
            output += " ";
            output += str1[i];
        }
        // dosra case mei ye huraha hay k agar value iterate hukay opening bracket araha hay tu hamesha push karain gay 
        else if (str1[i] == '(')
        {
            st.push(str1[i]);
        }
        //third case mai hum cloding bracket ko hadndle karrahe hain k agar closing bracket hay tu tab tak pop karwatay jaiangay jab tak opening nai mil jati
        else if (str1[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                output += " ";
                output += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        // phir last case ye check huraha  hsy k agar operator hay tu pehlaya brackets check hungi anfd then acc to priority popo ya push hujaye ga 
        else
        {
            while (!st.empty() && precedenceCheck(st.top()) >= precedenceCheck(str1[i]))
            {
                output += " ";
                output += st.top();
                st.pop();
            }
            st.push(str1[i]);  //jab opening mil jaye tu us opening ko b end pay push karwa dain 
        }
    }
    // ye loop hamnay lagaya hay k jab hamara input exhaust hujaye tu bas sab pop kardo 

    while (!st.empty()) 
    {
        output += " ";
        output += st.top();
        st.pop();
    }


    return output;
}

int main()
{
    cout << "Enter Expression in infix" ;
    cout << endl;
    string st;
    getline(cin, st);
     cout << "\n CONVERTING TO POSTFIX : "<<endl;
    cout << infixToPostFix(st);
}
