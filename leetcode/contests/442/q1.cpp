//https://leetcode.com/problems/maximum-containers-on-a-ship/
//3492. Maximum Containers on a Ship
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        return min(n*n,maxWeight/w);        
    }
};