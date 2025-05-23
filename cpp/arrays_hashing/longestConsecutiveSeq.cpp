#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int longestConsecutive(vector<int>& nums) {

    unordered_set<int> map;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) map.insert(nums[i]);
    for (auto element : map) {
        int current = 1;
        if (map.find(element - 1) == map.end()) {
            while (map.find(element + 1) != map.end()) {
                current++;
                element++;
            }
        }
        ans = max(current, ans);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> suicidio = { 0, 3, 2, 5, 4, 6, 1, 1 };
    cout << longestConsecutive(suicidio) << endl;

    return 0;
}
