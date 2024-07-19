#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(std::string s, std::string p) {
    int l = 0, r = 0, count = 0, minLen = INT_MAX;
    int  startIndex = -1;
   vector<int> mp(26, 0);
    int n = s.size(), m = p.size();
    
    for (char c : p) {
        mp[c - 'a']++;
    }

    while (r < n) {
        if (mp[s[r] - 'a'] > 0) {
            count++;
        }
        mp[s[r] - 'a']--;
        
        while (count == m) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                startIndex = l;
            }
            mp[s[l] - 'a']++;
            if (mp[s[l] - 'a'] > 0) {
                count--;
            }
            l++;
        }
        r++;
    }
    return minLen == INT_MAX ? "-1" : s.substr(startIndex, minLen);
}

    
};
