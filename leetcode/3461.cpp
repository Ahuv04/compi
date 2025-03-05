//https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/
//3461. Check If Digits Are Equal in String After
class Solution {
public:
    bool hasSameDigits(string s) {
        int temp;
        string k;
        while(s.size()!=2){
            temp=0;
            k="";
            for(int i=0;i<s.length()-1;i++){
                temp=(s[i]-'0'+s[i+1]-'0')%10;
                k+=to_string(temp);
            }
            s=k;
        }
        
        return s[0]==s[1];
    }
};