//https://leetcode.com/problems/trapping-rain-water/
//42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0), right(n,0);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {   left[i]=max(left[i-1],height[i]);
            right[n-i-1]=max(height[n-i-1],right[n-i]);
           // cout<<left[i]<<right[i]<<endl;
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {   
            ans+=max(0,min(left[i],right[i])-height[i]);
        }

        return ans;
    }
};