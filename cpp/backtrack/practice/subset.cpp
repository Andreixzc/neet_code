#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& current, int control) {

    if (control == nums.size()) {
        ans.push_back(current);
        return;
    }

    current.push_back(nums[control]);
    dfs(ans, nums, current, control + 1);
    current.pop_back();
    dfs(ans, nums, current, control + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> current;
    dfs(ans, nums, current, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
