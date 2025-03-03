//https://leetcode.com/problems/generate-parentheses/
//22. Generate Parentheses
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==1){
            ans.push_back("()");
            return ans;
        }
        else if(n==2){
            ans.push_back("()()");
            ans.push_back("(())");
            return ans;
        }

        ans=generateParenthesis(n-1);
        vector<string> t1;
        map<string, bool> m;
        for(int i=0;i<ans.size();i++){
            string temp=ans[i];
            string p="";
            string k="";
            for(int j=0;j<temp.size();j++){
                p+=temp[j];
                if(j!=temp.size()-1) k=p+"()"+temp.substr(j+1,temp.size()-j-1);
                else k=p+"()";

                if(m.find(k)==m.end()){
                    // cout<<"does it enter here?"<<endl;
                    m[k]=true;
                    t1.push_back(k);
                }
            }
        }        
        return t1;
    }
};