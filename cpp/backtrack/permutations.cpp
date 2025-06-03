#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(vector<vector<int>>& ans, vector<int>& nums, int current) {

    if (current == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = current; i < nums.size(); i++) {
        swap(nums[i], nums[current]);
        dfs(ans, nums, current + 1);
        swap(nums[i], nums[current]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    dfs(ans, nums, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
