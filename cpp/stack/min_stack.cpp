#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

class MinStack {
  public:
    stack<pair<int, int>> st;

    MinStack() {
    }

    void push(int val) {
        if (st.empty()) {
            st.push({ val, val });
        } else {
            st.push({ val, min(st.top().second, val) });
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

    MinStack minStack;
    minStack.push(4);

    return 0;
}
