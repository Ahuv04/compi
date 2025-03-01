//https://leetcode.com/problems/text-justification/
//68. Text Justification
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n;
        vector<string> op;
        string a;
        vector<string> ans;
        int curr_left=maxWidth;
        int state=0;
        int last_pos=0;
        for(int i=0;i<words.size();i++)
        {   if((words[i].length()<=curr_left && state==0)||(words[i].length()+1<=curr_left))
            {   
                if(state!=0)
                {
                    words[i]=' '+words[i];
                }
                state=1;   
                curr_left-=words[i].length();
                op.push_back(words[i]);
            }
            else
            {   state=0;
                if(curr_left>0)
                {   
                    a="";
                    if(op.size()-last_pos==1)
                    {   a+=op[last_pos];
                    for(int j=0;j<curr_left;j++)
                    {   a+=" ";}                    
                    }
                    else
                    {                        
                    int per=curr_left/(op.size()-last_pos-1);
                    int extra=curr_left%(op.size()-last_pos-1);
                    cout<<per<<endl;
                    cout<<extra<<endl;
                    cout<<op[last_pos]<<endl;
                    for(int j=last_pos;j<op.size()-1;j++)
                    {   a+=op[j];
                        for(int j=0;j<per;j++)
                        {   a+=" ";
                         cout<<a<<endl;
                            
                        }
                     if(extra>0)
                            {   extra-=1;

                             a+=" ";
                         cout<<a<<endl;

                            }
                    }

                    a+=op[op.size()-1];
                    }
                    ans.push_back(a);                           
                }
                else
                {   a="";
                    for(int j=last_pos;j<op.size();j++)
                    {   a+=op[j];
                    }
                 
                    ans.push_back(a);   
                }
                curr_left=maxWidth;
                last_pos=op.size();
                // op.clear();
                if((words[i].length()<=curr_left && state==0)||(words[i].length()+1<=curr_left))
                {   
                if(state!=0)
                {
                    words[i]=' '+words[i];
                }
                state=1;   
                curr_left-=words[i].length();
                op.push_back(words[i]);
                }
            }
        }
        if(op.size()>0)
        {
                state=0;
                if(curr_left>0)
                {   
                    a="";
                    if(op.size()-last_pos==1)
                    {   a+=op[last_pos];
                    for(int j=0;j<curr_left;j++)
                    {   a+=" ";}                    
                    }
                    else
                    {                        
                    for(int j=last_pos;j<op.size()-1;j++)
                    {   a+=op[j];
                    }
                    a+=op[op.size()-1];
                    for(int k=0;k<curr_left;k++)
                    {
                        a+=" ";
                    }
                    }
                    ans.push_back(a);                           
                }
                else
                {   a="";
                    for(int j=last_pos;j<op.size();j++)
                    {   a+=op[j];
                    }
                 
                    ans.push_back(a);   
                }
                
        }
        return ans;
    }
};