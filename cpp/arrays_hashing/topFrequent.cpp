#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, int> freqMap;
    for (int i = 0; i < nums.size(); i++) freqMap[nums[i]]++;
    for (auto element : freqMap) cout << element.first << endl;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto element : freqMap) {
        pq.push({element.second, element.first});
        if (pq.size() > k) pq.pop();
    }
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = {5, 5, 5, 5, 1, 1, 1, 1, 3, 3, 3, 3, 4, 4, 4, 4};
    int k = 2;
    topKFrequent(input, k);

    return 0;
}
