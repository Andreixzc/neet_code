#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int findMin(vector<int>& nums) {

    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = (right + left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] < nums[mid]) { // porção left -> mid está ordenada. Preciso verificar se meu
                                      // numero pode estar la.
            if (nums[left] > target) {
                // se o menor valor da porção exceder o target, meu numero está na porção mid ->
                // right;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 3, 4, 5, 6, 1, 2 };
    int target = 1;

    return 0;
}
