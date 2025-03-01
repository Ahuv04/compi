//https://leetcode.com/problems/plus-one/
//66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--)
        {   
            digits[i]+=1;
            if(digits[i]==10 && i!=0) digits[i]=0;
            else break;
        }
        
        if(digits[0]==10){
            digits[0]=1;
            digits.push_back(0);
        }

        return digits;
    }
};