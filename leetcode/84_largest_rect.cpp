//https://leetcode.com/problems/largest-rectangle-in-histogram/
//84. Largest Rectangle in Histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int w=1;

        stack<int> s;
        stack<int> curr_w;

        int t1,t2;

        for(int i=0;i<heights.size();i++){
            if(s.empty())
            {   s.push(heights[i]);
                w=1;
                curr_w.push(w);
            }
            else if(heights[i]>s.top()){
                s.push(heights[i]);
                curr_w.pop();
                curr_w.push(w);
                w=1;
                curr_w.push(w);
            }
            else if(heights[i]==s.top()){
                w+=1;
                curr_w.pop();
                curr_w.push(w);
            }
            else{
                curr_w.pop();
                curr_w.push(w);
                t2=0;
                while(!s.empty() && heights[i]<s.top()){
                    t1=s.top();
                    t2+=curr_w.top();
                    ans=max(ans,t1*t2);
                    s.pop();
                    curr_w.pop();
                }
                w=t2+1;
                if(s.empty()){
                    s.push(heights[i]);
                    curr_w.push(w);

                }
                else if(s.top()==heights[i]){
                    w+=curr_w.top();
                    curr_w.pop();
                    curr_w.push(w);
                    // cout<<i<<endl;
                //    cout<<curr_w.top()<<endl;
                }
                else{
                    s.push(heights[i]);
                    curr_w.push(w);
                }
            }
        }
        t2=0;

        while(!s.empty()){
            t1=s.top();
            t2+=curr_w.top();
            ans=max(ans,t1*t2);
            s.pop();
            curr_w.pop();
        }

        return ans;
    }
};

/*
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int temp=0;
        int h;
        int w;
        for(int i=0;i<heights.size();i++)
        {   h=heights[i];
            w=1;
            temp=h;
            for(int j=i+1;j<heights.size();j++){
                w+=1;
                h=min(h,heights[j]);
                temp=max(temp,h*w);
            }
            ans=max(ans,temp);
        }
        return ans;
    }
*/
