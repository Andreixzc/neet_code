#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool isValid(string s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char current = s[i];
        if (current == '[' || current == '(' || current == '{')
            st.push(current);
        else {
            if (st.empty()) return false;
            if (current == ']' && st.top() != '[') return false;
            if (current == ')' && st.top() != '(') return false;
            if (current == '}' && st.top() != '{') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << isValid("{)}{}");

    return 0;
}
