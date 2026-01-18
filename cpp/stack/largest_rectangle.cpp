#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> foward(n, -1);
    vector<int> backwards(n, -1);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[i] < st.top().first) {
            foward[st.top().second] = i - st.top().second - 1;
            st.pop();
        }
        st.push({ heights[i], i });
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[i] < st.top().first) {
            backwards[st.top().second] = st.top().second - i - 1;
            st.pop();
        }
        st.push({ heights[i], i });
    }
    for (int i = 0; i < n; i++) {
        if (foward[i] == -1) {
            foward[i] = n - i - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (backwards[i] == -1) {
            backwards[i] = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int width = backwards[i] + 1 + foward[i];
        ans = max(ans, width * heights[i]);
    }

    return ans;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
