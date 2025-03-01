//https://leetcode.com/problems/word-break/
//139. Word Break
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> a(s.size()+1,false);
        a[0]=true;
        int start;

        for(int i=1;i<=s.size();i++)
        {   for(const string& w:wordDict)
            {   start=i-w.size();
                //this condition that was written is amazing....see a[start] this is very important
                if(start>=0 && a[start] && s.substr(start, w.size())== w)
                {   a[i]=true;
                    break;
                }
            }
        }

        return a[s.size()];
        
    }
};