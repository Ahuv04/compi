//https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
//2115. Find All Possible Recipes from Given Supplies
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, bool> m;
        vector<string> ans;

        for(int i=0;i<recipes.size();i++){
            if(m.find(recipes[i])!=m.end()){
                if(m[recipes[i]]) ans.push_back(recipes[i]);
            }
            else{
                m[recipes[i]]=true;
                for(int j=0;j<ingredients[i].size();j++){
                    if(m.find(ingredients[i][j])!=m.end()){
                        if(!m[ingredients[i][j]]){
                            break;
                        }
                    }
                    else{
                        if(find(supplies.begin(),supplies.end(),ingredients[i][j])!=supplies.end()){    
                            m[ingredients[i][j]]=true;
                        }
                        else{
                            m[ingredients[i][j]]=false;
                            m[recipes[i]]=false;
                            break;
                        }
                    }
                }
                if(m[recipes[i]]) ans.push_back(recipes[i]);
            }

            cout<<recipes[i]<<m[recipes[i]]<<endl;
        }
        return ans;
    }
};