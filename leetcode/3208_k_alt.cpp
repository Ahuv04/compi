//https://leetcode.com/problems/alternating-groups-ii/description/
//3208. Alternating Groups II
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0;
        int st=0;
        bool ok=false;
        int n=colors.size();
        while(st<n){
            int ed=st+k;
            if(ok){
                if(colors[(ed-2)%n]==colors[(ed-1)%n]){
                    ok=false;
                    st=ed-1;
                }
                else{
                    ans+=1;
                    st+=1;
                }
                continue;
            }
            ok=true;
            for(int i=st+1;i<ed-1;i++){
                if(colors[i%n]==colors[(i+1)%n]){
                    ok=false;
                    st=i+1;
                    break;
                }
                else if(colors[i%n]==colors[(i-1)%n]){
                    ok=false;
                    st=i;
                    break;
                }
            }
            if(ok){
                ans+=1;
                st+=1;
            }
        }

        return ans;      
    }
};