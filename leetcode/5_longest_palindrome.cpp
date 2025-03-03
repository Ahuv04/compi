//https://leetcode.com/problems/longest-palindromic-substring/
//5. Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i + 1);
            int max_len = max(odd, even);

            if (max_len > end - start) {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }

        return s.substr(start, end - start + 1);        
    }

private:
    int expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }    
};

//brute force method : really bad
//time limit execeeded
/*
class Solution {
public:

    bool isPalindrome(string s){
        if(s.size()==0) return true;

        for(int i=0;i<=s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(isPalindrome(s)) return s; 
        string ans="";
        string p;
        for(int i=0;i<s.size();i++){
            for(int j=1;j<=s.size()-i;j++){
                p=s.substr(i,j);
                if(isPalindrome(p) && ans.size()<j){
                    ans=p;
                }
            }
        }

        return ans;
    }
};
*/