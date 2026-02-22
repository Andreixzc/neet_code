#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int findDuplicate(vector<int>& nums) {

    int slow = 0;
    int fast = 0;

    while (1) {
        slow = nums[slow];       // value at pos[slow]
        fast = nums[nums[fast]]; // value that the current index points to based off his own index;
        if (slow == fast) break;
    }

    int slow2 = 0;
    while (1) {
        slow = nums[slow];
        slow2 = nums[slow2];
        if (slow2 == slow) return slow;
    }
}
int main() {
    ios::sync_with_stdio(0);
    return 0;
}
