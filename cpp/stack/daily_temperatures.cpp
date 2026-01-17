#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> st;
    vector<int> ans(temperatures.size());
    for (int i = 0; i < temperatures.size(); i++) {
        if (st.empty())
            st.push({ temperatures[i], i });
        else {
            if (st.top().first < temperatures[i]) {
                while (!st.empty() && st.top().first < temperatures[i]) {
                    ans[st.top().second] = i - st.top().second;
                    st.pop();
                }
                st.push({ temperatures[i], i });
            } else {
                st.push({ temperatures[i], i });
            }
        }
    }
    return ans;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = { 30, 38, 30, 36, 35, 40, 28 };
    vector<int> ans = dailyTemperatures(arr);

    for (int e : ans) cout << e << " ";

    return 0;
}
