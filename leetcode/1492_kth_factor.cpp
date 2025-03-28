//https://leetcode.com/problems/the-kth-factor-of-n/
//1492. The kth Factor of n
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> v;

        for(int i=1;i<=n;i++){
            if(n%i==0) v.push_back(i);
        }
        
        if(v.size()>=k) return v[k-1];
        else return -1;
    }
};