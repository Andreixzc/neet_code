#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int maxSum(vector<int> array, int k) {
    if (k > array.size()) return -1;
    int ans = 0, currentSum = 0;
    for (int i = 0; i < k; i++) {
        currentSum += array[i];
    }
    ans = currentSum;
    for (int i = 1; i < array.size() - k + 1; i++) {
        int aux = currentSum;
        for (int j = i; j < i + k; j++) {
            aux += array[j];
        }
        aux -= array[i - 1];
        ans = max(ans, aux);
        currentSum = aux;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    cout << maxSum(input, 4) << endl;
    return 0;
}
