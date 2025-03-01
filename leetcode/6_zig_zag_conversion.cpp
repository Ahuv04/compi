//https://leetcode.com/problems/zigzag-conversion/
//6. Zigzag Conversion
class Solution {
public:
    string convert(string s, int nr) {
        vector<pair<char , int>> a;
        pair<char, int> p;

        int temp;
        if(nr==1)
        {
            return s;
        }
        for(int i=0;i<s.size();i++)
        {   
            p.first=s[i];            
            //even case
            if((i/(nr-1))%2==0)
            {   p.second=(i%(nr-1))*(nr*s.size())+i/(nr-1);}
            //odd case
            else{
                p.second=(nr-1-i%(nr-1))*(nr*s.size())+i/(nr-1);
            }
            a.push_back(p);
        }

        sort(begin(a), end(a), 
        [&](const auto& a, const auto& b)
        {
            return a.second < b.second;
        });

        string q;
        for(int i=0;i<s.size();i++)
        {   q+=a[i].first;
            
        }

        return q;
    }
};