//506. Relative Ranks
//https://leetcode.com/problems/relative-ranks/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,string> m;
        vector<string> ans;
        vector<int> okay;
        for(int i=0;i<score.size();i++)
        {   okay.push_back(score[i]);
        }

        sort(okay.begin(),okay.end());
        int k=okay.size();
        for(int i=k-1;i>=0;i--)
        {   if(k-1-i==0)
            {   m[okay[i]]="Gold Medal";}
            else if(k-1-i==1)
            { m[okay[i]]="Silver Medal";}
            else if(k-1-i==2)
            { m[okay[i]]="Bronze Medal";}
            else
            {   m[okay[i]]=to_string(k-i);}
        }
        for(int i=0;i<score.size();i++)
        {   ans.push_back(m[score[i]]);
        }

        return ans;
    }
};


//Alternative solution

class Solution {
    public String[] findRelativeRanks(int[] score) {
        
        int n = score.length;
        
        int maxScore = 0;
        for (int i = 0 ; i < n ; i++) {
            maxScore = Math.max(maxScore, score[i]);
        }
        
        int[]  score2Index = new int[maxScore+1];
        
        for (int i = 0 ; i < n ; i++) {
            score2Index[score[i]] = i+1;
        }
        
        String[] ans = new String[n];
        
        int place = 1;
        
        for (int i = maxScore ; i >= 0 ; i--) {
            
            if (score2Index[i] == 0) continue;
                
            int actualIndex = score2Index[i] - 1;
            if (place == 1) {
                ans[actualIndex] = "Gold Medal";
            } else if (place == 2) {
                ans[actualIndex] = "Silver Medal";
            } else if (place == 3) {
                ans[actualIndex] = "Bronze Medal";
            } else {
                ans[actualIndex] = String.valueOf(place);
            }
            place++; 
        }
        
        return ans;
    }
}
