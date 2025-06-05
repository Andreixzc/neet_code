#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(vector<vector<int>>& ans,
         vector<int>& candidates,
         vector<int>& current,
         int target,
         int start,
         int sum) {

    if (sum == target) {
        ans.push_back(current);
        return;
    } else if (sum > target) {
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        current.push_back(candidates[i]);
        dfs(ans, candidates, current, target, i + 1, sum + candidates[i]);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> current;
    dfs(ans, candidates, current, target, 0, 0);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = { 9, 2, 2, 4, 6, 1, 5 };
    int t = 8;
    combinationSum2(arr, t);

    return 0;
}
