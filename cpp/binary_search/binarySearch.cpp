#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int bSearchRec(vector<int>& nums, int target, int left, int right) {
    int mid = (left + right) / 2;
    if (left > right) return -1;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] > target)
        return bSearchRec(nums, target, left, mid - 1);
    else {
        return bSearchRec(nums, target, mid + 1, right);
    }
}

int search(vector<int>& nums, int target) {
    return bSearchRec(nums, target, 0, nums.size());
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input = {-1, 0, 2, 4, 6, 8};
    int target = 3;

    cout << search(input, target) << endl;
    return 0;
}
