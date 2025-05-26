#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int maxProfit(vector<int>& prices) {
    int left = 0;
    int right = 1;
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[right] > prices[left]) {
            int current = prices[right] - prices[left];
            profit = max(current, profit);
        } else {
            left = right;
        }
        right++;
    }

    return profit;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input = { 10, 1, 5, 6, 7, 1 };
    cout << maxProfit(input);

    return 0;
}
