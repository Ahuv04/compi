//https://leetcode.com/problems/unique-paths/
//62. Unique Paths
map<pair<int,int>,int> m1;

class Solution {
public:
    int uniquePaths(int m, int n) { 
        pair<int, int> p = make_pair(m,n);
        int ans;

        if(m1.find(p)!=m1.end()) return m1[p];
        if(m==1 || n==1){        
            return 1;
        }
        m1[p]=uniquePaths(m-1,n)+uniquePaths(m,n-1);
        return m1[p];
    }
};