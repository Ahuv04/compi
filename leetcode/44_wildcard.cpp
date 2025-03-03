//https://leetcode.com/problems/wildcard-matching/
//44. Wildcard Matching
class Solution {
public:
    bool isMatch(string s, string fp) {
        if(fp=="*") return true;
        if(s.size()==0 && fp.size()==0) return true;

        int st_ind=-1;
        int si=0;
        int fpi=0;
        int match=0;

        while(si<s.size()){
            if(fpi<fp.size() &&(fp[fpi]=='?' || fp[fpi]==s[si])){
                si+=1;
                fpi+=1;
                continue;
            }
            else if(fpi<fp.size() && fp[fpi]=='*'){
                st_ind=fpi;
                fpi+=1;
                match=si;
            }
            else if(st_ind!=-1){
                fpi=st_ind+1;
                match+=1;
                si=match;
            }
            else return false;
        }

        while(fpi<fp.size() && fp[fpi]=='*'){
            fpi+=1;
        }

        return fpi==fp.size();
    }
};