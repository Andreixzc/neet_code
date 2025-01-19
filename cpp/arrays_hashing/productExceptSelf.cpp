#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> productExceptSelf(vector<int>& nums){

    vector<int> prefix(nums.size());
    vector<int> postfix(nums.size());
    prefix[0] = nums[0];
    postfix[nums.size()-1] = nums[nums.size()-1];
    int j = nums.size()-2;
    for(int i = 1; i< nums.size(); i++){
        
        prefix[i] = prefix[i-1] *nums[i];
        postfix[j] = postfix[j+1] * nums[j];
        j--;
    }
    nums[0] = postfix[1]; 
    for (int i = 1; i < nums.size() - 1; i++) {
        nums[i] = prefix[i - 1] * postfix[i + 1];
    }
    nums[nums.size() - 1] = prefix[nums.size() - 2]; 
    return nums;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = {1,2,3,4};
    productExceptSelf(input);
    
    return 0;
    
}
