#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ans(temperatures.size(), 0);
    stack<pair<int, int>> st;
    st.push({temperatures[0], 0});
    for (int i = 1; i < temperatures.size(); i++) {
        int current = temperatures[i];
        while (!st.empty() && current > st.top().first) {
            ans[st.top().second] = i - st.top().second;
            st.pop();
        }
        st.push({current, i});
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input = {30, 38, 30, 36, 35, 40, 28};
    vector<int> output = dailyTemperatures(input);
    for (auto element : output) {
        cout << element << " ";
    }
    return 0;
}
