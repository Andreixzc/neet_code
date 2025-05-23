#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> twoSum(vector<int>& numbers, int target) {

    int l = 0;
    int r = numbers.size() - 1;

    while (l < r) {
        int current = numbers[l] + numbers[r];
        if (current > target)
            r--;
        else if (current < target)
            l++;
        else
            return { l + 1, r + 1 };
    }
    return {};
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 1, 2, 3, 4, 5, 6, 7 };
    int target = 3;
    vector<int> ans = twoSum(input, target);
    for (auto element : ans) cout << element << endl;

    return 0;
}
