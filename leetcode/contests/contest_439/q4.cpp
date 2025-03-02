//Q4. Lexicographically Smallest Generated String
//unattempted
//checks of no string exists is not added
class Solution {
public:
    string generateString(string str1, string str2) {
        string ans="";
        string temp="";
        int p;
        int k=0;
        //string(5, '.') 
        for(int i=0;i<str1.length();i++)
        {
            if(str1[i]=='T'){
                temp=str2;
                ans=ans.substr(0,i);
                ans+=temp;
            }
            else{
                
                p=ans.size()-i;
                p=max(k,p);
                p=str2.size()-p;
                p=max(k,p);
                ans=ans+string(p,'a');
            }
        }
        return ans;
        
    }
};