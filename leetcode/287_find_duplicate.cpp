//https://leetcode.com/problems/find-the-duplicate-number/
//287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int sl=0,ft=0;

        while(true){
            sl=nums[sl];
            ft=nums[nums[ft]];
            if(sl==ft) break;
        }
        sl=0;

        while(sl!=ft){
            sl=nums[sl];
            ft=nums[ft];
        }

        return sl;
    }
};