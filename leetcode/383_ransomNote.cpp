//https://leetcode.com/problems/ransom-note/
//383. Ransom Note
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;

        for(int i=0;i<magazine.size();i++)
        {
            m[magazine[i]]+=1;
        }

        for(int i=0;i<ransomNote.size();i++)
        {   if(m.find(ransomNote[i])!=m.end())
            {   if(m[ransomNote[i]]<=0)
                {
                    return false;
                }
                m[ransomNote[i]]-=1;
            }
            else{
                return false;
            }
        }
        return true;   
    }
};