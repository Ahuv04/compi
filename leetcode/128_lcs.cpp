//https://leetcode.com/problems/longest-consecutive-sequence/
//128. Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        map<int, int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=1;
        }

        int ans=0;
        map<int,int>::iterator it=m.begin();
        int temp=1;
        int prev=it->first;
        it++;
        while(it!=m.end())
        {   
            if(prev+temp==it->first)
            {
                temp+=1;
                //prev=it->first;
            }
            else{
                ans=max(temp,ans);
                temp=1;
                prev=it->first;
            }

            it++;
        }
        return max(temp,ans);
    }
};