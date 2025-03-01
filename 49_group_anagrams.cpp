//https://leetcode.com/problems/group-anagrams/
//49. Group Anagrams
//alternate way is to sort each string and compare, this would be much easier

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> s;
        int state;
        if(strs.size()==1)
        {   s.push_back(vector<string>({strs[0]}));
            return s;
        }

        vector<map<char, int>> v;

        for(int i=0;i<strs.size();i++)
        {   map<char, int> m;
            state=0;
            for(int j=0;j<strs[i].size();j++)
            {   m[strs[i][j]]+=1;}
            for(int j=0;j<v.size();j++)
            {   if(v[j].size()==m.size() && 
                equal(m.begin(), m.end(), v[j].begin()) )
                {  state=1;
                    s[j].push_back(strs[i]);
                    break;
                }
            }
            if(state==0)
            {   s.push_back(vector<string>({strs[i]}));
                v.push_back(m);
            }
        }
        return s;
    }
};

