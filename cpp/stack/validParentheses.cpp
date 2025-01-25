#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool isValid(string s) {
    stack<char> stack;
    if (s[0] == '(' || s[0] == '[' || s[0] == '{') {
        stack.push(s[0]);
    } else {
        return false;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')') {
            if (stack.empty() || stack.top() != '(') return false;
            stack.pop();
        } else if (s[i] == ']') {
            if (stack.empty() || stack.top() != '[') return false;
            stack.pop();
        } else if (s[i] == '}') {
            if (stack.empty() || stack.top() != '{') return false;
            stack.pop();
        } else {
            stack.push(s[i]);
        }
    }
    return stack.empty();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "()}{}{[]}";
    cout << isValid(s) << endl;
    return 0;
}
