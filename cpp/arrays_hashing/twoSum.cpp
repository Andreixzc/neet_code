#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) == map.end())
            map[nums[i]] = i;
        else
            return { map[complement], i };
    }
    return { 0, 0 };
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> array = { 3, 4, 5, 6 };
    int target = 7;
    auto output = twoSum(array, target);
    for (auto element : output) cout << element;

    return 0;
}
