#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> triplets;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int current = nums[i] + nums[left] + nums[right];
            if (current < 0)
                left++;
            else if (current > 0)
                right--;
            else {

                triplets.push_back({ nums[i], nums[left], nums[right] });
                while (nums[left] == nums[left + 1]) left++;
                while (nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            }
        }
    }
    return triplets;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
