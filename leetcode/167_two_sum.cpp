//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//167. Two Sum II - Input Array Is Sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int pos=0;
        int las=num.size()-1;

        while(pos!=las)
        {   if(target==num[pos]+num[las])
            {
                return vector<int>({pos+1,las+1});
            }
            else if(target<num[pos]+num[las]){
                las-=1;
            }
            else{
                pos+=1;
            }
        }
        return vector<int>({0,0});
    }
};