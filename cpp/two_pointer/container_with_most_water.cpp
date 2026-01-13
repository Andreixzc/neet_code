#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int maxArea(vector<int>& heights) {
    int left = 0;
    int right = heights.size() - 1;
    int ans = 0;
    while (left < right) {
        int current = min(heights[left], heights[right]) * (right - left);
        if (heights[left] < heights[right]) {
            left++;
        } else if (heights[left] > heights[right]) {
            right--;
        } else {
            right--;
            left++;
        }
        ans = max(ans, current);
    }

    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = { 1, 7, 2, 5, 12, 3, 500, 500, 7, 8, 4, 7, 3, 6 };
    cout << maxArea(arr);

    return 0;
}
