#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> dailyTemperatures(vector<int>& temperatures) {

    stack<pair<int, int>> st;
    vector<int> ans(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); i++) {
        while (!st.empty() && temperatures[i] > st.top().second) {
            ans[st.top().first] = i - st.top().first;
            st.pop();
        }
        st.push({ i, temperatures[i] });
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> ans;
    vector<int> input = { 30, 38, 30, 36, 35, 40, 28 };
    ans = dailyTemperatures(input);
    for (auto& element : ans) cout << element;
    return 0;
}
