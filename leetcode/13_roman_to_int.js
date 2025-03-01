//https://leetcode.com/problems/roman-to-integer/
//13. Roman to Integer
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let ans=0;
    let prev;
    for(let i=0;i<s.length;i++)
    {   if(i!=0)
        {   prev=s[i-1];
            if(s[i]==='I')
            {   
                ans+=1;
            }
            else if(s[i]==='V')
            {   if(prev==='I')
                {
                    ans=ans-2;
                }
                ans+=5;
            }
            else if(s[i]==='X')
            {
                if(prev==='I')
                {
                    ans=ans-2;
                }
                ans+=10;
            }
            else if(s[i]==='L')
            {
                if(prev==='X')
                {
                    ans=ans-20;
                }
                ans+=50;
            }
            else if(s[i]==='C')
            {
                if(prev==='X')
                {
                    ans=ans-20;
                }
                ans+=100;
            }
            else if(s[i]==='D')
            {
                if(prev==='C')
                {
                    ans=ans-200;
                }                
                ans+=500;
            }
            else{
                if(prev==='C')
                {
                    ans=ans-200;
                }                  
                ans+=1000;
            }
        }
        else
        {
            if(s[i]==='I')
            {
                ans+=1;
            }
            else if(s[i]==='V')
            {
                ans+=5;
            }
            else if(s[i]==='X')
            {
                ans+=10;
            }
            else if(s[i]==='L')
            {
                ans+=50;
            }
            else if(s[i]==='C')
            {
                ans+=100;
            }
            else if(s[i]==='D')
            {
                ans+=500;
            }
            else{
                ans+=1000;
            }
        }

    }
    return ans;
    
};