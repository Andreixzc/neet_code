#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int bsearch(vector<int>& nums, int start, int end, int target) {
    int left = start;
    int right = end;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (target == nums[mid]) return mid;
        if (target > nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int search(vector<int>& nums, int target) {

    int left = 0;
    int right = nums.size() - 1;
    int n = nums.size() - 1;
    while (left < right) {
        int mid = (right + left) / 2;
        if (nums[mid] >= nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    int rotation = left;
    if (target >= nums[rotation] && target <= nums[n]) {
        return bsearch(nums, rotation, n, target);
    } else {
        return bsearch(nums, 0, rotation - 1, target);
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
