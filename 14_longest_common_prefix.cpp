//https://leetcode.com/problems/longest-common-prefix/
//14. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp=strs[0];
        int pos=temp.size();
        string ans="";

        for(int i=0;i<pos;i++)
        {   for(int j=0;j<strs.size();j++)
            {   if(strs[j].size()<=i || strs[j][i]!=temp[i])
                {
                    return ans;
                }
            }
            ans+=temp[i];
        }

        return ans;
    }
};