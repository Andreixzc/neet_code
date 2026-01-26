#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<pair<int, int>> ms;
    vector<int> ans;
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        ms.insert({ nums[right], right });
        if (ms.size() > k) {
            ms.erase({ nums[left], left });
            left++;
        }
        if (ms.size() == k) ans.push_back(ms.rbegin()->first);
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
