#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(int control, vector<vector<int>>& ans, vector<int>& current, vector<int>& nums) {

    if (control == nums.size()) {
        ans.push_back(current);
        return;
    }

    current.push_back(nums[control]);
    dfs(control + 1, ans, current, nums);
    current.pop_back();
    dfs(control + 1, ans, current, nums);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    dfs(0, ans, current, nums);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = { 1, 2, 3 };
    auto xd = subsets(nums);
    for (auto element : xd) {
        for (auto inner : element) cout << inner << endl;
    }

    return 0;
}
