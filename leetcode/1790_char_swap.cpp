//https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
//1790. Check if One String Swap Can Make Strings Equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int k=0;
        int i=0;
        int pos;
        while(i<s1.size() && k<=2)
        {
            if(s1[i]!=s2[i])
            {   
                k+=1;
                if(k==1)
                {pos=i;}    
            if(k>=2)
            {
                if(k>2 || (k==2 && (s1[pos]!=s2[i] || s1[i]!=s2[pos])))
                {   
                    return false;
                }
            }
            
            }
            i++;
        }
        if(k==1)
        {return false;}
        return true;
    }
};