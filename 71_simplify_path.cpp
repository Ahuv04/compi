//https://leetcode.com/problems/simplify-path/
//71. Simplify Path
class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        string temp="/";
        int curr=0;
        stack<string> s;
        stack<string> s2;
        
        for(int i=1;i<path.size();i++)
        {   if(curr==0)
            {   if(path[i]=='/')
                {   continue;}
                else if(path[i]=='.')
                {
                    curr=1;
                }
                else{
                    curr=4;
                    temp+=path[i];
                }
            }
            else if(curr==1)
            {   if(path[i]=='.')
                {   curr=2;
                    temp=string("/..");
                }
                else if(path[i]=='/'){
                    curr=0;
                    temp=string("/");
                }
                else{
                    temp=string("/.")+path[i];
                    curr=4;
                }
            }
            else if(curr==2)
            {   if(path[i]=='/')
                {
                    curr=0;
                    temp="/";
                    if(!s.empty())
                    {   s.pop();}
                }
                else{
                    temp+=path[i];
                    curr=4;
                }
            }
            else{
                if(path[i]=='/')
                {
                    curr=0;
                    s.push(temp);
                    temp=string("/");
                }
                else{
                    temp+=path[i];
                }
            }
        }

        if(temp==string("/..") && !s.empty())
        {   s.pop();}
        else if(curr==4)
        {
            s.push(temp);
        }

        while(!s.empty())
        {
            s2.push(s.top());
            s.pop();
        }

        while(!s2.empty())
        {
            ans+=s2.top();
            s2.pop();
        }

        if(ans==string(""))
        {
            return "/";
        }
        return ans;
        
    }
};