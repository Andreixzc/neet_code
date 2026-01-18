#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool testar(vector<int>& piles, int k, int h) {
    double total = 0;
    if (k == 0) return false;
    for (int i = 0; i < piles.size(); i++) {
        total += (int)ceil((double)piles[i] / k);
        if (total > h) return false;
    }
    return true;
}
int minEatingSpeed(vector<int>& piles, int h) {

    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    while (left <= right) {
        int mid = (right + left) / 2;
        if (testar(piles, mid, h))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
