#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool possible(vector<int>& piles, int h, int rate, int upperBound) {
    int hours = 0;
    for (int i = 0; i < piles.size(); i++) {
        hours += ceil((double)piles[i] / rate);
        if (hours > h) return false;
    }
    return true;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int upperBound = *max_element(piles.begin(), piles.end());
    int left = 1;
    int right = upperBound;
    while (left <= right) {
        int rate = (right + left) / 2;
        if (possible(piles, h, rate, upperBound))
            right = rate - 1;
        else
            left = rate + 1;
    }

    return left;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 1, 4, 3, 2 };
    cout << minEatingSpeed(input, 9) << endl;
    return 0;
}
