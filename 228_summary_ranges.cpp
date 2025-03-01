//https://leetcode.com/problems/summary-ranges/
//228. Summary Ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;
        if(nums.size()==0)
        {return ans;}
        string s;
        int prev=nums[0];
        int state=0;
        s=to_string(prev);

        for(int i=1;i<nums.size();i++)
        {   if(nums[i]==prev+1)
            {   
                if(state==0)
                {   s=to_string(prev);
                    state=1;
                }
                prev++;
            }
            else{
                if(state==0)
                {   ans.push_back(to_string(prev));}
                else{
                    s=s+"->"+to_string(prev);
                    ans.push_back(s);
                    s="";
                }
                state=0;
                prev=nums[i];
            }

        }
        if(state==0)
        {   ans.push_back(to_string(prev));}
        else{
                    s=s+"->"+to_string(prev);
                    ans.push_back(s);
                }

        return ans;
        
    }
};