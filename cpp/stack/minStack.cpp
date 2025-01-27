#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}

    void push(int val) {
        if (st.empty())
            st.push({ val, val });
        else {
            if (val < st.top().second) {
                st.push({ val, val });
            }
            else {
                st.push({ val, st.top().second });
            }
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    MinStack* minStack = new MinStack(); // Changed to pointer usage
    minStack->push(1);
    minStack->push(2);
    minStack->push(0);
    cout << minStack->getMin() << endl; // return 0
    minStack->pop();
    cout << minStack->top() << endl;    // return 2
    cout << minStack->getMin() << endl; // return 1

    delete minStack; // Free allocated memory
    return 0;
}
