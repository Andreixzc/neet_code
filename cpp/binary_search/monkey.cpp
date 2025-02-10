#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool possible(vector<int>& piles, int h, int k) {
    double total = 0;
    // k/pile[i]
    for (int i = 0; i < piles.size(); i++) {
        total += ceil((double)piles[i] / k);
        if (total > h) return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int right = *max_element(piles.begin(), piles.end());
    int left = 1;
    while (left <= right) {
        int k = (left + right) / 2;
        if (!possible(piles, h, k))
            left = k + 1;
        else
            right = k - 1;
    }

    return left;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> piles = {1, 4, 3, 2};
    int h = 9;
    cout << minEatingSpeed(piles, h) << endl;
    return 0;
}
