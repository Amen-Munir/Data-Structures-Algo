#include <stack>
#include <algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int start = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    start = i + 1;
                } else {
                    st.pop();
                    if (st.empty()) {
                        maxLen = max(maxLen, i - start + 1);
                    } else {
                        maxLen = max(maxLen, i - st.top());
                    }
                }
            }
        }
        return maxLen;
    }
};
int main()
{
    Solution s;
    cout << s.longestValidParentheses("");
    return 0;
}