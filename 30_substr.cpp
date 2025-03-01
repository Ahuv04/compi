

//two sosutions all failed for a particular testcase-181/182

//https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//30. Substring with Concatenation of All Words
class Solution {
public:

    bool strHelper(string s, unordered_map<string,int> m, int total, int ws){
        string h;
        for(int i=0;i<s.size();i+=ws)
        {   h=s.substr(i,ws);
             if(m.find(h)==m.end() || --m[h]<0)
             {
                return false;
             }
        }
        return true;

    }

    vector<int> findSubstring(string s, vector<string>& words) {

        int total=words.size()*words[0].size();
        vector<int> ans;
        if(words.empty() || s.empty() || s.size()<total) return ans;
        unordered_map<string, int> m;

        for(string str: words)
        {
            m[str]++;
        }

        for(int i=0; i+total<=s.size();i++)
        {   if(strHelper(s.substr(i,total), m, total, words[0].size()))
            {   ans.push_back(i);}
        }

        return ans;
    }
};
/*
//time limit execceeded
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int total=words.size()*words[0].size();
        vector<int> ans;
        if(s.size()<total) return ans;
        sort(words.begin(),words.end());
        
        for(int i=0;i+total<=s.size();i++)
        {   vector<string> temp;
            for(int j=i;j<i+total;j+=words[0].size()){
                temp.push_back(s.substr(j,words[0].size()));
            }
            sort(temp.begin(),temp.end());
            if(temp==words)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
*/