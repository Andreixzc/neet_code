#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(vector<vector<int>>& ans,
         vector<int>& nums,
         vector<int>& current,
         int target,
         int sum,
         int start) {

    if (sum == target) {
        ans.push_back(current);
        return;
    }

    if (sum > target) return;

    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        dfs(ans, nums, current, target, sum + nums[i], i);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> current;
    dfs(ans, nums, current, target, 0, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
