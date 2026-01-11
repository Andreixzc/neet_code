#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    vector<int> prefix(n);
    vector<int> sufix(n);
    prefix[0] = 1;
    sufix[n - 1] = 1;
    for (int i = 1; i < nums.size(); i++) prefix[i] = nums[i - 1] * prefix[i - 1];
    for (int i = n - 2; i >= 0; i--) sufix[i] = nums[i + 1] * sufix[i + 1];
    for (int i = 0; i < nums.size(); i++) ans[i] = sufix[i] * prefix[i];
    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 1, 2, 4, 6 };
    vector<int> ans = productExceptSelf(input);

    for (int i : ans) cout << i << " ";

    return 0;
}
