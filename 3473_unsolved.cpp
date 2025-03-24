//https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-ii/
//3463. Check If Digits Are Equal in String After Operations II
class Solution {
public:

    vector<int> fib(int n){
        vector<int> ans;
        int k=1;
        int p=1;
        ans.push_back(1);
        bool f=true;
        while(n>0){
            p=((p/k)*n)%10;
            ans.push_back(p);
            k+=1;
            n-=1;
        }
        p=ans.size()-1;
        for(int i=0;i<ans.size();i++)
        {   if(ans[i]!=0){
                ans[p-i]=ans[i];
                }
        }

        for(int i=p;i>=0;i--)
        {   cout<<ans[i]<<endl;
        }

        return ans;
    }

    bool hasSameDigits(string s) {
        int t1,t2;
        t2=0;
        vector<int> v=fib(s.size()-2);
        t1=int(s[0])%10;
        for(int i=1;i<s.size()-1;i++){
            t1+=(int(s[i])*v[i])%10;
            t2+=(int(s[i])*v[i-1])%10;
        }
        t2+=int(s[s.size()-1])%10;
        return t1%10==t2%10;
    }
};