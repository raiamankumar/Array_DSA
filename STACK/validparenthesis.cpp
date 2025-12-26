#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.size() == 0) {
                    return false;
                } else if (
                    (st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')
                ) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter the string of brackets: ";
    cin >> s;

    if (obj.isValid(s)) {
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}
