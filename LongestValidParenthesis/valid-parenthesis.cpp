#include<iostream>
#include<stack>

bool isValid(std::string s) {
  
    std::stack<char> stack;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack.push(s[i]);
        } else if (stack.empty() || (s[i] == ')' && stack.top() != '(') || (s[i] == '}' && stack.top() != '{') || (s[i] == ']' && stack.top() != '[')) {
            return false;
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            stack.pop();
           
        }
    }
   
    return stack.empty();
}

int main() {
    bool check = isValid("()[]{}}");
    if (check) {
        std::cout << "Valid Parenthesis" << std::endl;
    } else {
        std::cout << "Invalid Parenthesis" << std::endl;
    }

    return 0;
}
