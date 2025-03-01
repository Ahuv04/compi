//https://leetcode.com/problems/evaluate-reverse-polish-notation/
//150. Evaluate Reverse Polish Notation
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1) return stoi(tokens[0]);
        
        stack<int> s;
        int a,b;

        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                if(tokens[i]=="+") s.push(a+b);
                else if(tokens[i]=="-") s.push(b-a);
                else if(tokens[i]=="*") s.push(a*b);
                else s.push(b/a);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
        
    }
};