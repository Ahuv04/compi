//https://leetcode.com/problems/happy-number/
//202. Happy Number
class Solution {
public:

    bool isHappy(int n) {
        map<int , bool> m;
        int ans;
        while(true)
        {   ans=0;
            while(n>0)
            {  ans+=(n%10)*(n%10);
                n=n/10;
            }
            n=ans;
            if(ans==1)
            {
                return true;
            }
            if(m.find(ans)!=m.end())
            {
                return false;
            }
            m[ans]=true;
        }
        
        return false;
    }
};