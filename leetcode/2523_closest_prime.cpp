//https://leetcode.com/problems/closest-prime-numbers-in-range/
//2523. Closest Prime Numbers in Range
class Solution {
public:
    bool isPrime(int n){
        if(n==1) return false;
        if(n%2==0 && n!=2) return false;
        else if(n==2 || n==3) return true;
        int a=3;

        while(a<=sqrt(n)){
            if(n%a==0) return false;
            a+=1;
        }

        return true;

    }

    vector<int> closestPrimes(int l, int r) {
        if(l<=2 && r>=3) return {2,3};
        vector<int> ans={-1,-1};
        int prev=-1;
        bool po=true;
        if(l==r) return ans;

        while(l<=r){
            if(isPrime(l)){
                if(po && prev==-1) prev=l;
                else if(po){
                    po=false;
                    ans[1]=l;
                    ans[0]=prev;
                }
                else if(l-prev<ans[1]-ans[0]){
                    ans[1]=l;
                    ans[0]=prev;
                }
                prev=l;
            }
            l++;
        }
        return ans;
    }
};