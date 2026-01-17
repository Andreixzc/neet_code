#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    if (n == 0) return 0;
    vector<pair<int, int>> cars;
    for (int i = 0; i < n; i++) {
        cars.push_back({ position[i], speed[i] });
    }
    sort(cars.begin(), cars.end(), [](auto& a, auto& b) {
        return a.first > b.first;
    });

    vector<double> arrival;
    for (int i = 0; i < n; i++) {
        arrival.push_back((double)(target - cars[i].first) / cars[i].second);
    }
    stack<double> st;
    for (int i = 0; i < arrival.size(); i++) {
        if (st.empty()) {
            st.push(arrival[i]);
        } else {
            if (arrival[i] > st.top()) {
                st.push(arrival[i]);
            }
        }
    }

    return st.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> position = { 10, 8, 0, 5, 3 };
    vector<int> speed = { 2, 4, 1, 1, 3 };
    cout << carFleet(12, position, speed) << endl;

    return 0;
}
