#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> map;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.count(nums[i]) > 0)
        {
            ans.push_back(map[nums[i]]);
            ans.push_back(i);
        }
        map[target - nums[i]] = i;

    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
