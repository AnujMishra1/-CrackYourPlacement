#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int a=haystack.find(needle);
        if(a!=-1)
        {
            return a;
        }
        return -1;
        
    }
};