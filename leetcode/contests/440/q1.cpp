//https://leetcode.com/contest/weekly-contest-440/problems/fruits-into-baskets-ii/
//Q1. Fruits Into Baskets II
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int rem=fruits.size();
    int n=baskets.size();
    vector<bool> f(n,0);
        int j=0;

        for(int i=0;i<fruits.size();i++){
            j=0;
            while(j<baskets.size()){
                if(baskets[j]>=fruits[i] && !f[j]){
                    f[j]=true;
                    rem-=1;
                    break;
                }
                j++;
            }
        }
        
         return rem; 
    }
};©leetcode