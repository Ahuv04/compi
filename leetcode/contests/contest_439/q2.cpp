//Q2. Longest Palindromic Subsequence After at Most K Operations
//failed because question says subsequence, dolution is for substring
class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        if(s.empty()){
            return 0;
        }        
        int st=0;
        int ed=0;
        int ml=0;
        for(int i=0;i<s.length();i++){
            int o=ep(s, i, i, k);
            int e=ep(s, i, i+1, k);
            int max_len=max(o,e);
            ml=max(ml,e);
            ml=max(ml,o);
        }
        return ml;
    }

private:
    int ep(string s, int left, int right, int k) {
        while (left >= 0 && right < s.length()) {
            if(s[left] == s[right]){
            left--;
            right++;}
            else if(k>=min(abs(s[left]-s[right]), 26-abs(s[left]-s[right]))){
                k=k- min(abs(s[left]-s[right]), 26-abs(s[left]-s[right]));
                left--;
                right++;
            }
            else{
                break;
            }
        }
        return right - left - 1;
    }    
};