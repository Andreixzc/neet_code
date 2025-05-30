#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& current, int i) {
    if (i >= nums.size()) {
        ans.push_back(current);
        return;
    }
    current.push_back(nums[i]);
    dfs(nums, ans, current, i + 1);
    current.pop_back();
    dfs(nums, ans, current, i + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> current;
    dfs(nums, ans, current, 0);

    return ans;
}

int main() {
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> result = subsets(nums);

    for (auto& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    return 0;
}
