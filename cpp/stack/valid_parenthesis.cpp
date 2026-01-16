#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
            continue;
        } else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
                continue;
            } else {
                return false;
            }
        } else if (s[i] == '}') {
            if (!st.empty() && st.top() == '{') {
                st.pop();
                continue;
            } else {
                return false;
            }
        } else if (s[i] == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
                continue;
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "()[";
    cout << isValid(s) << endl;

    return 0;
}
