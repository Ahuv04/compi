//https://leetcode.com/problems/powx-n/
//50. Pow(x, n)
class Solution {
public:
    double mp(double x, long int n){
        if(x==0 || x==1) return x;
        if(n==0) return 1;
        if(x==-1){
            if(n%2==0) return 1;
            else return -1;
        }

        double ans=1;
        long int temp=0;
        while(n>temp){
            ans=ans*x;
            temp+=1;
            if(n>2*temp){
                ans=ans*ans;
                temp*=2;
            }
        }

        return ans;   

    }

    double myPow(double x, int n) {
        if(x==0 || x==1) return x;
        if(n==0) return 1;
        if(x==-1){
            if(n%2==0) return 1;
            else return -1;
        }
        long int k=n;
        double ans=1;
        long int temp=0;

        if(n<0){
            ans=1/mp(x,abs(k));
        }
        while(k>temp){
            ans=ans*x;
            temp+=1;
            if(k>2*temp){
                ans=ans*ans;
                temp*=2;
            }
        }
        return ans;   
    }
};