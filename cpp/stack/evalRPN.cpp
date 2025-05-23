#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (int i = 0; i < tokens.size(); i++) {
        string token = tokens[i];
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int tmp1 = st.top();
            st.pop();
            int tmp2 = st.top();
            st.pop();
            if (token == "+")
                st.push(tmp2 + tmp1);
            else if (token == "-")
                st.push(tmp2 - tmp1);
            else if (token == "*")
                st.push(tmp2 * tmp1);
            else if (token == "/")
                st.push(tmp2 / tmp1);
        } else {
            st.push(stoi(token));
        }
    }

    return st.top();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // fix str 1 -> 13;
    vector<string> tokens = { "4", "13", "5", "/", "+" };
    cout << evalRPN(tokens) << endl;

    return 0;
}
