#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (int i = 0; i < (int)tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();

            if (tokens[i] == "+") {
                st.push(n2 + n1);
            } else if (tokens[i] == "-") {
                st.push(n2 - n1);
            } else if (tokens[i] == "*") {
                st.push(n2 * n1);
            } else if (tokens[i] == "/") {
                st.push(n2 / n1);
            }
        } else {
            st.push(stoi(tokens[i]));
        }
    }

    return st.top();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> tokens = { "1", "2", "+", "3", "*", "4", "-" };
    cout << evalRPN(tokens) << '\n';

    return 0;
}
