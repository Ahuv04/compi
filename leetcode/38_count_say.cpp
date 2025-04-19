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

//https://leetcode.com/problems/count-and-say/
//38. Count and Say
class Solution {
public:
    vector<pair<int,int>> op(string a){
        int count=1;
        vector<pair<int,int>> ans;
        char prev=a[0];
        for(int i=1;i<a.size();i++){
            if(prev==a[i]){
                count+=1;
            }
            else{
                ans.push_back({count,prev-'0'});
                prev=a[i];
                count=1;
            }
        }
        ans.push_back({count,prev-'0'});

        return ans;
    }
    string ok(vector<pair<int,int>> a){
        string ans;
        for(int i=0;i<a.size();i++){
            ans=ans+to_string(a[i].first)+to_string(a[i].second);
        }
        return ans;
    }

    string countAndSay(int n) {
        string ans="1";
        if(n==1) return ans;
        while(n>1){
            n-=1;
            ans=ok(op(ans));
        }
        return ans;
    }
};