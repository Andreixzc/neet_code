#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int search(vector<int>& nums, int target) {

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = (right + left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > nums[left]) {
            if (target >= nums[left] && target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        else {

            if (target >= nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> ans = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0 };
    cout << "VETOR INICIAL: ";
    for (auto element : ans) cout << element << " ";
    cout << endl << endl;

    int res = 0;
    for (int i = 0; i <= 20; i++) {
        cout << "Buscando pelo numero: " << i << " -> ";
        res = search(ans, i);
        if (res != -1) {
            cout << "encontrado no indice " << res << endl;
        } else {
            cout << "nao encontrado" << endl;
        }
    }

    cout << endl;
    int target = 13;
    int target_index = search(ans, target);
    if (target_index != -1) {
        cout << "Target " << target << " encontrado no indice " << target_index << ": "
             << ans[target_index] << endl;
    } else {
        cout << "Target " << target << " nao encontrado" << endl;
    }
    return 0;
}
