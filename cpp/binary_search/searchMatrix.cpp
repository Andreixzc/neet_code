#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> array;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            array.push_back(matrix[i][j]);
        }
    }
    int left = 0;
    int right = array.size() -1 ;
    while (left <= right) {
        int mid = (left + right) /2;
        if (array[mid] == target) return true;
        if (array[mid] > target) {
            right = mid - 1;
        } else
            left = mid + 1;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<std::vector<int>> matrix = {
        {1, 2, 4, 8},
        {10, 11, 12, 13},
        {14, 20, 30, 40}};
    cout << searchMatrix(matrix, 4) << endl;
    return 0;
}
