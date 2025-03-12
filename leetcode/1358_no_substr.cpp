//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
//1358. Number of Substrings Containing All Three Characters

//good solution
//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
//1358. Number of Substrings Containing All Three Characters
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }
        return count;
    }
};

//tatti solution
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        vector<vector<int>> v;
        int ca=0,cb=0,cc=0;
        int n=s.length();
        int p1,p2,p3;

        for(int i=0;i<n;i++){
            vector<int> p;
            if(s[i]=='a')   { if(ca==0){p1=i;} ca++;}
            else if(s[i]=='b')   { if(cb==0){p2=i;} cb++;}
            else { if(cc==0){p3=i;} cc++;}
            if(ca>0 && cb>0 && cc>0) ans+=1;
            p.push_back(ca);
            p.push_back(cb);
            p.push_back(cc);
            v.push_back(p);
        }
        p1=max(p1,p2);
        p1=max(p1,p3);

        if(ca==0 || cb==0 || cc==0) return 0;

        for(int i=0;i<n;i++){
            for(int j=p3>i?p3:i+2;j<n;j++){
                if(v[j][0]-v[i][0]>0 && v[j][1]-v[i][1]>0 && v[j][2]-v[i][2]>0){
                    ans+=n-j;
                    break;
                }
            }
        }
        return ans;
    }
};