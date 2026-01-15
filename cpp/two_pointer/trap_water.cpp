#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int trap(vector<int> heights) {
    vector<int> maxBefore(heights.size());
    vector<int> maxAfter(heights.size());
    maxBefore[0] = -1;
    maxAfter[maxAfter.size() - 1] = -1;
    int ans = 0;
    for (int i = 1; i < heights.size(); i++) maxBefore[i] = max(heights[i - 1], maxBefore[i - 1]);
    for (int i = maxAfter.size() - 2; i >= 0; i--)
        maxAfter[i] = max(heights[i + 1], maxAfter[i + 1]);
    for (int i = 1; i < heights.size(); i++) {
        int sum = min(maxAfter[i], maxBefore[i]) - heights[i];
        if (sum > 0) ans += sum;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 0, 2, 0, 3, 1, 0, 1, 3, 2, 1 };
    cout << trap(input);

    return 0;
}
