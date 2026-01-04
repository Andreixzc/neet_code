#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    vector<int> ans;
    for (int num : nums) freq[num]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto element : freq) {
        pq.push({ element.second, element.first });
        if (pq.size() > k) pq.pop();
    }
    while (!pq.empty()) {
        auto p = pq.top();
        ans.push_back(p.second);
        pq.pop();
    }

    return ans;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 1, 2, 2, 3, 3, 3 };
    int k = 2;
    vector<int> arr;
    arr = topKFrequent(input, k);

    for (int n : arr) cout << n << endl;

    return 0;
}
