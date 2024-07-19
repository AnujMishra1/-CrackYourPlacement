#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        string ans;
        while(num!=0)
        {
            if(num>=1000)
            {
                ans.push_back('M');
                num-=1000;
            }
            else if(num>=500)
            {
                if(num>=900)
                {
                    ans+="CM";
                    num-=900;
                }
                else
                {
                    ans.push_back('D');
                    num-=500;
                }
            }
            else if(num>=100)
            {
                if(num>=400)
                {
                    ans+="CD";
                    num-=400;
                }
                else
                {
                    num-=100;
                    ans.push_back('C');
                }
            }
            else if(num>=50)
            {
                if(num>=90)
                {
                    ans+="XC";
                    num-=90;
                }
                else
                {
                    ans.push_back('L');
                    num-=50;
                }
            }
            else if(num>=10)
            {
                if(num>=40)
                {
                    ans+="XL";
                    num-=40;
                }
                else
                {
                    num-=10;
                    ans.push_back('X');
                }
            }
            else if(num>=5)
            {
                if(num>=9)
                {
                    ans+="IX";
                    num-=9;
                }
                else
                {
                    num-=5;
                    ans.push_back('V');
                }
            }
            else if(num>=1)
            {
                if(num>=4)
                {
                    ans+="IV";
                    num-=4;
                }
                else
                {
                    ans.push_back('I');
                    num-=1;
                }
            }
        }
        return ans;
        
    }
};