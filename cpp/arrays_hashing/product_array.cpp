#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n), postfix(n), ans(n);

    if (n == 0) return ans;

    prefix[0] = 1;
    postfix[n - 1] = 1;

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        postfix[i] = postfix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++) {
        ans[i] = prefix[i] * postfix[i];
    }

    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 1, 2, 4, 6 };
    input.pb(1);
    vector<int> output;
    output = productExceptSelf(input);
    for (int e : output) cout << e << endl;

    return 0;
}
