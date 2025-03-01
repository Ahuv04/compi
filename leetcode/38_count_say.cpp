//https://leetcode.com/problems/count-and-say/
//38. Count and Say
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        else if(n==2) return "11";
        else if(n==3) return "21";
        
        string s=countAndSay(n-1);
        string ans="";

        int temp=1;
        char curr=s[0];
        for(int i=1;i<s.size();i++){
            if(curr==s[i]) temp+=1;
            else{
                ans+=to_string(temp)+curr;
                curr=s[i];
                temp=1;                
            }
        }
        ans+=to_string(temp)+curr;
        
        return ans;
        
    }
};