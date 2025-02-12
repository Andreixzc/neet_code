#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int findMin(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> array = {4, 5, 6, 1, 2, 3};
    // cout << findMin(array) << endl;
    return 0;
}
