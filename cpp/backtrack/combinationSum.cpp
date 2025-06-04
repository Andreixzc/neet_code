#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(vector<vector<int>>& ans, int target, int start, vector<int>& nums, vector<int>& current) {

    int sum;
    for (int i = 0; i < current.size(); i++) sum += current[i];

    if (sum > target) return;

    if (sum == target) {
        ans.push_back(current);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        dfs(ans, target, i, nums, current);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> current;
    dfs(ans, target, 0, nums, current);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
