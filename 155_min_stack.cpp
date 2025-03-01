//https://leetcode.com/problems/min-stack/
//155. Min Stack
class MinStack {
public:
    int m;
    stack<int> s;
    map<int, int> c;


    MinStack() {
        s=stack<int>();
        c=map<int, int>();
    }
    
    void push(int val) {
        if(s.empty())
        {   m=val;}
        else{
            m=min(m,val);
        }
        s.push(val);
        c[val]+=1;
        return;
    }
    
    void pop() {
        if(s.empty()) return;

        if(s.top()==m)
        {   c[m]-=1;
            if(c[m]==0)
            {   map<int, int>::iterator it=c.begin();
                while(it!=c.end())
                {   if(it->second!=0)
                    {   m=it->first;
                        break;
                    }
                    it++;
                }
            }
            s.pop();
            return;
        }
        c[s.top()]-=1;
        s.pop();
        return;
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */