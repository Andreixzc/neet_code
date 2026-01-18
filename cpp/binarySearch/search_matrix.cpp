#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int largura = matrix[0].size();
    int altura = matrix.size();
    int left = 0;
    int right = (largura * altura) - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        int i = mid / largura;
        int j = mid % largura;
        if (target == matrix[i][j]) return true;
        if (target > matrix[i][j])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
