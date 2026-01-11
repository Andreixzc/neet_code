#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int longestConsecutive(vector<int>& nums) {
    set<int> myset;
    int best = 0;
    for (int& element : nums) myset.insert(element);

    for (int i = 0; i < nums.size(); i++) {
        int current = nums[i];
        int curr_seq = 1;
        if (myset.find(current + 1) != myset.end()) continue;
        int tmp = current - 1;
        while (myset.find(tmp) != myset.end()) {
            curr_seq++;
            tmp--;
        }
        best = max(best, curr_seq);
        curr_seq = 0;
    }

    return best++;
}
int main() {

    ios::sync_with_stdio(0);
    vector<int> input = { 3, 2, 5, 4, 6, 1, 1 };
    cout << longestConsecutive(input) << endl;
    cin.tie(0);

    return 0;
}
