#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> cars;
    stack<int> st;
    int fleet = 0;
    for (int i = 0; i < position.size(); i++) {
        cars.push_back({position[i], speed[i]});
    }
    sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });
    for (int i = 0; i < cars.size(); i++) st.push((target - cars[i].first) / (double)cars[i].second);
    while (!st.empty()) {
        int current = st.top();
        st.pop();
        if (current >= st.top()) fleet++;
    }

    return fleet;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> position = {4, 1, 0, 7};
    vector<int> speed = {2, 2, 1, 1};
    int target = 10;
    cout << carFleet(target, position, speed) << endl;

    return 0;
}
