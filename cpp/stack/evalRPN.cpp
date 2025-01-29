#include <bits/stdc++.h>

#include <cctype>

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

// Literaly a accumulator register btw;
using namespace std;

bool isDigit(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int stringToInt(const string& s) {
    return stoi(s);
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (const string& token : tokens) {
        if (isDigit(token) || (token.size() > 1 && token[0] == '-' && isDigit(token.substr(1)))) {
            st.push(stringToInt(token));
        } else {
            if (st.size() < 2) throw invalid_argument("Invalid RPN expression");

            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();

            if (token == "+")
                st.push(num2 + num1);
            else if (token == "-")
                st.push(num2 - num1);
            else if (token == "*")
                st.push(num2 * num1);
            else if (token == "/") {
                if (num1 == 0) throw runtime_error("Division by zero");
                st.push(num2 / num1);
            }
        }
    }
    return st.size() == 1 ? st.top() : throw invalid_argument("Invalid RPN expression");
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> input = {"1", "2", "+", "3", "*", "4", "-"};
    cout << evalRPN(input) << endl;
    return 0;
}
