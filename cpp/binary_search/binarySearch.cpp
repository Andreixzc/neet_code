#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> array = { -1, 0, 2, 4, 6, 8 };
    int target = 8;
    cout << search(array, target) << endl;

    return 0;
}
