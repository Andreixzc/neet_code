#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

class TimeMap {
  public:
    unordered_map<string, vector<pair<int, string>>> mymap;
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mymap[key].push_back({ timestamp, value });
    }

    string get(string key, int timestamp) {
        int left = 0;
        int right = mymap[key].size() - 1;
        vector<pair<int, string>>& cp = mymap[key];
        if (cp.size() == 0) return "";
        while (left <= right) {
            int mid = (right + left) / 2;
            if (timestamp >= cp[mid].first)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (right > 0) {
            return cp[right].second;
        }
        return "";
    }
};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
