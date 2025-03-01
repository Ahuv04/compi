// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        double ans=0;
        int g=0;
        if(x==-2147483648)
        {return 0;}
        if(x<0)
        {   g=-1;
            x*=-1;
        }
        while(x>0)
        {   ans=ans*10+x%10;
            x/=10;
        }
        if(g==-1)
        {ans*=-1;}
        cout<<ans;
        if(ans>pow(2,31)-1 || ans<-1*pow(2,31))
        {
            return 0;
        }
        g=ans;
        return g;
    }
};
