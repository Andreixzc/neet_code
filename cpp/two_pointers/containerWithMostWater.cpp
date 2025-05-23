#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int maxArea(vector<int>& heights) {
    int ans = 0;
    int left = 0;
    int right = heights.size() - 1;

    while (left < right) {
        int curr = min(heights[left], heights[right]) * (right - left);
        if (heights[right] > heights[left])
            left++;
        else if (heights[right] < heights[left])
            right--;
        else {
            right--;
            left++;
        }
        ans = max(curr, ans);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> heights = { 1, 7, 2, 400, 400, 7, 3, 6 };
    cout << maxArea(heights) << endl;
    return 0;
}
