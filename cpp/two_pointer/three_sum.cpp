#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int current = nums[i] + nums[left] + nums[right];
            if (current > 0)
                right--;
            else if (current < 0)
                left++;
            else {
                ans.push_back({ nums[i], nums[left], nums[right] });
                while (left < right && nums[left + 1] == nums[left]) left++;
                while (left < right && nums[right - 1] == nums[right]) right--;
                left++;
                right--;
            }
        }
    }

    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = { 1, -1, -1, 0 };

    vector<vector<int>> result = threeSum(nums);
    for (const auto& triplet : result) {
        cout << "[ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
