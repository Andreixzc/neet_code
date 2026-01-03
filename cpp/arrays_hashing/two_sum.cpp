#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        int complemento = target - nums[i];
        if (map.find(complemento) != map.end()) {
            return { map[complemento], i };
        } else {
            map[nums[i]] = i;
        }
    }
    return { -1, -1 };
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
