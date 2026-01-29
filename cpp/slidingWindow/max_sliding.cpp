#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 1, 2, 1, 0, 4, 2, 6 };
    vector<int> output = maxSlidingWindow(input, 3);
    for (auto element : output) cout << " " << element;

    return 0;
}
