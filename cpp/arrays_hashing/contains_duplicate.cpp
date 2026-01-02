#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++) {
        if (set.find(nums[i]) != set.end()) return true;
        set.insert(nums[i]);
    }
    return false;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
