#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int searchRecursive(vector<int>& nums, int target, int left, int right) {
    int mid = (right + left) / 2;
    if (left >= right) return -1;
    if (nums[mid] == target) return mid;
    if (nums[mid] > target)
        return searchRecursive(nums, target, left, mid - 1);
    else
        return searchRecursive(nums, target, mid + 1, right);
}
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (right + left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
