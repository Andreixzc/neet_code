#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int maxProfit(vector<int>& prices) {

    int ans = 0;
    int left = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[left]) {
            ans = max(ans, prices[i], prices[left]);
        } else {
            left = i;
        }
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
