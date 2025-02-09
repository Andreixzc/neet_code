#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ans(temperatures.size(), 0);
    stack<int> st;
    for (int i = 0; i < temperatures.size(); i++) {
        int j = i - 1;
        while (!st.empty() && temperatures[i] > st.top()) {
            ans[j] = i - j;
            st.pop();
            j--;
        }
        st.push(temperatures[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = {30, 29, 28, 27, 32};
    vector<int> output = dailyTemperatures(input);
    for (auto element : output) {
        cout << element << " ";
    }
    return 0;
}
