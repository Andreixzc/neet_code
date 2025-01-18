#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

string encode(vector<string>& strs) {
   string encodedString;
   for (int i = 0; i < strs.size(); i++) {
       int len = strs[i].length();
       encodedString += to_string(len);
       encodedString += '#';            
       encodedString += strs[i];        
   }
   return encodedString;
}

vector<string> decode(string s) {
   vector<string> ans;
   int i = 0;
   while (i < s.length()) {
       int delimiterPos = s.find('#', i);
       if (delimiterPos == string::npos) break;
       string lenStr = s.substr(i, delimiterPos - i);
       int wordLen = stoi(lenStr);
       string word = s.substr(delimiterPos + 1, wordLen);
       ans.push_back(word);
       i = delimiterPos + 1 + wordLen;
   }
   return ans;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   vector<string> input = { "neet","code","love","you" };
   string encoded = encode(input);
   cout << encoded << endl;
   vector<string> test = decode(encoded);
   for(auto elemento : test){
       cout << elemento << endl;
   }
   return 0;
}