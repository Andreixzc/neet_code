#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<vector<int>> dwt(vector<int> seq1, vector<int> seq2) {
    int n = seq1.size();
    int m = seq2.size();
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, INT_MAX));
    dist[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = abs(seq1[i - 1] - seq2[j - 1]);
            dist[i][j] = cost + min({ dist[i - 1][j - 1], dist[i - 1][j], dist[i][j - 1] });
        }
    }

    return dist;
}

int main() {
    vector<int> seq1 = { 2, 1, 5, 4, 2, 1, 5, 6 };
    vector<int> seq2 = { 1, 6, 5, 1, 8, 6, 1, 9 };
    auto dist = dwt(seq1, seq2);

    cout << "distancia: " << dist[seq1.size()][seq2.size()] << endl;
    return 0;
}
