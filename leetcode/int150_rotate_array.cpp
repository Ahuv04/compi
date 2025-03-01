//https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int s=v.size();
        k=k%s;
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+k);
        reverse(v.begin()+k,v.end());
    }
};