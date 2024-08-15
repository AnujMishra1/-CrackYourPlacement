#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {

        int two=1;
        int three=1;
        int five=1;

        vector<int>arr(n+1);
        arr[1]=1;
       
        for(int i=2;i<=n;i++)
        {
            int a=arr[two]*2;
            int b=arr[three]*3;
            int c=arr[five]*5;

            int nxt=min({a,b,c});

            arr[i]=nxt;

            if(nxt==a)two++;
            if(nxt==b)three++;
            if(nxt==c)five++;
        }

        return arr[n];


        
    }
};