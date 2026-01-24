#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> maior;
    vector<int> menor;
    if (nums1.size() >= nums2.size()) {
        maior = nums1;
        menor = nums2;
    } else {
        maior = nums2;
        menor = nums1;
    }
    int left = 0;
    int right = menor.size();
    vector<int> ordered;

    while (left <= right) {
        int p1 = (left + right) / 2;
        int p2 = ((maior.size() + menor.size() + 1) / 2) - p1;

        int p1min;
        if (p1 == 0)
            p1min = INT_MIN;
        else
            p1min = menor[p1 - 1];

        int p2min;
        if (p2 == 0)
            p2min = INT_MIN;
        else
            p2min = maior[p2 - 1];

        int p1max;
        if (p1 == menor.size())
            p1max = INT_MAX;
        else
            p1max = menor[p1];

        int p2max;
        if (p2 == maior.size())
            p2max = INT_MAX;
        else
            p2max = maior[p2];

        if (p1min <= p2max && p2min <= p1max) {
            ordered.push_back(p1min);
            ordered.push_back(p2min);
            ordered.push_back(p1max);
            ordered.push_back(p2max);
            break;
        } else if (p1min > p2max)
            right = p1 - 1;
        else
            left = p1 + 1;
    }

    int n = maior.size() + menor.size();
    sort(ordered.begin(), ordered.end());

    if ((n % 2) == 0) {
        return (double)(ordered[1] + ordered[2]) / 2;
    } else {
        return ordered[1];
    }
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = { 1, 2, 3 };
    cout << arr.size();

    return 0;
};
