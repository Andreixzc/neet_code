#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int maxProfit(vector<int>& prices) {
    int ans = 0;
    int current = 0;
    int left = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[left]) {
            current = prices[i] - prices[left];
        } else {
            left = i;
        }
        ans = max(ans, current);
    }

    return ans;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> prices = { 10, 1, 5, 6, 7, 1 };
    cout << maxProfit(prices) << endl;

    return 0;
}
