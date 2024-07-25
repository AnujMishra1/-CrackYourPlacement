class Solution {
public:
    bool backspaceCompare(string s, string t) {

        
        string scopy="";
        string tcopy="";

        int i=0;
        while(i<s.size())
        {
            if(s[i]=='#')
            {
                if(scopy.size()>0)
                {
                    scopy.pop_back();
                }
            }
            else
            {
                scopy.push_back(s[i]);
            }
            i++;
        }
        i=0;

        while(i<t.size())
        {
            if(t[i]=='#')
            {
                if(tcopy.size()>0)
                {
                    tcopy.pop_back();
                }
            }
                else
                {
                    tcopy.push_back(t[i]);
                }
            
            i++;
        }
        cout<<scopy<<"  "<<tcopy;
        return scopy==tcopy;
        
    }
};