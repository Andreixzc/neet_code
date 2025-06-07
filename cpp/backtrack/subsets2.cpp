#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& current, int start) {

    ans.push_back(current);
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        current.push_back(nums[i]);
        dfs(ans, nums, current, i + 1);
        current.pop_back();
    }
}
vector<vector<int>> subsetsWithDupe(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> current;
    dfs(ans, nums, current, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = { 1, 2, 1 };
    vector<vector<int>> output = subsetsWithDup(arr);
    for (auto element : output) {
        for (auto innerElement : element) {
            cout << innerElement << " ";
        }
        cout << endl;
    }
    return 0;
}
