#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool hasDuplicate(vector<int>& nums) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(nums[i]) != map.end())
            return true;
        map[nums[i]]++;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> array = { 1, 2, 3, 4, 5, 6, 7 };
    vector<int> array2 = { 1, 2, 4, 4, 5, 6, 7 };
    cout << hasDuplicate(array) << endl;
    cout << hasDuplicate(array2) << endl;

    return 0;
}
