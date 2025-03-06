//https://leetcode.com/problems/contiguous-array/
//525. Contiguous Array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> m1;
        map<int, int> m2;
        int temp=0;
        int ans=0;
        m1[0]=-1;
        m2[0]=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) temp-=1;
            else temp+=1;

            if(m1.find(temp)!=m1.end()){
                m1[temp]=i;
                ans=max(ans,m1[temp]-m2[temp]);
            }
            else{
                m2[temp]=i;
                m1[temp]=i;
            }
        }

        return ans;
    }
};


/*
time limit exceeded

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int k=nums.size();
        if(k==2 && nums[0]!=nums[1]) return 2;
        for(int i=1;i<k;i++){
            nums[i]+=nums[i-1];
        }
        int temp=0;
        for(int i=-1;i<k;i++){
            for(int j=i+2;j<k;j+=2){
                if(i==-1){
                    if(nums[j]==(j-i)/2) temp=max(temp,j-i);
                } 
                else if(nums[j]-nums[i]==(j-i)/2) temp=max(temp,j-i);
            }
        }
        return temp;
    }
};
*/