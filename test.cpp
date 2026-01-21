#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = { 4, 5, 6, 7, 0, 1, 2, 3 };
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] >= arr[right])
            left = mid + 1;
        else
            right = mid;
    }

    cout << right << endl;

    return 0;
}
