#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
 int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        unordered_set<int> consider;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!set.count(nums[i] - 1)) consider.insert(nums[i]);
        }
        for (unordered_set<int>::iterator it = consider.begin(); it != consider.end(); ++it) {
            int currentBest = 0;
            int atual = *it;
            while (set.count(atual++)) currentBest++;
            ans = max(currentBest, ans);
        }
        return ans;
    }


    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        vector<int> input = {0,3,2,5,4,6,1,1};
        cout << longestConsecutive(input) << endl;

        return 0;
    }
