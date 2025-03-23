//https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/
//3494. Find the Minimum Amount of Time to Brew Potions
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long ans=0;
        if(skill.size()==1){
            for(int i=0;i<mana.size();i++)
            {ans+=mana[i]*skill[0];
                
            }        
            return ans;
        }
        vector<vector<long long>> v(mana.size(), vector<long long>(1+skill.size()));
        v[0][0]=0;
        for(int i=0;i<mana.size();i++){
            for(int j=0;j<=skill.size();j++)
            {
                if(i==0){
                    if(j!=0) v[i][j]=v[i][j-1]+mana[i]*skill[j-1];
                }
                else{
                    if(j!=0){
                        v[i][j]=v[i][j-1]+mana[i]*skill[j-1];
                        if(j!=skill.size()){
                             v[i][j]=max(v[i][j],v[i-1][j+1]);   
                        }
                    }
                    else{
                        v[i][j]=v[i-1][j+1];
                    }
                }
            }

            for(int j=skill.size();j>0;j--){
                v[i][j-1]=v[i][j]-mana[i]*skill[j-1];
            }
        }

        return v[mana.size()-1][skill.size()];
        
    }
};
