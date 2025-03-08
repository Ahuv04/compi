//https://leetcode.com/problems/minimum-window-substring/
//76. Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";

        unordered_map<char,int> mp;

        for (char ch : t) {
            mp[ch]++;
        }

        int st=0;
        int rem=t.length();
        int minw[2]={0,INT_MAX};

        for(int ed=0;ed<s.length();ed++){
            char ch=s[ed];
            if(mp.find(ch)!=mp.end() && mp[ch]>0){
                rem--;
            }
            mp[ch]--;

            if(rem==0){
                while(true){
                char chars=s[st];
                    if(mp.find(chars)!=mp.end() && mp[chars]==0){
                        if(ed-st<minw[1]-minw[0]){
                            minw[1]=ed;
                            minw[0]=st;                            
                        }
                        mp[chars]++;
                        rem++;
                        st++;
                        break;
                    }
                    else{
                        mp[chars]++;
                        st++;
                    }
                }
            }
        }

        return minw[1] >= s.length() ? "" : s.substr(minw[0],minw[1]-minw[0]+1);
    }
};