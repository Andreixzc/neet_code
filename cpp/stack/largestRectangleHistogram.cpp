#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int largestRectangleArea(vector<int>& heights) {
    stack<pair<int, int>> st;  // height - index
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        int leftConsider = i;
        while (!st.empty() && st.top().first > heights[i]) {
            maxArea = max(maxArea, st.top().first * (i - st.top().second));
            leftConsider = st.top().second;
            st.pop();
        }
        st.push({heights[i], leftConsider});
    }

    int n = (int)heights.size();
    while (!st.empty()) {
        maxArea = (max(maxArea, st.top().first * (n - st.top().second)));
        st.pop();
    }
    return maxArea;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> array = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(array) << endl;
    return 0;
}
