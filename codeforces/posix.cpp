#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

#define ll                  long long
#define lld                 long long double
#define lf                  long float
#define scl(n)              scanf("%lld", &n)
#define scf(n)              scanf("%lf", &n)
#define pfl(x)              printf("%lld\n",x)
#define md                  10000007
#define mm					1000000001
#define pb                  push_back
#define pf                  push_front
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define wh(n)               while(n>0)

void boost()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << setprecision(10);
}

int main()
{
    boost();
    ll n;
    cin>>n;
    stack<ll> s;
    char c;
    string s1;
    //bas input sahi se nhi aara -> format '3 2 10 * +' 
    fr(i,n)
    {  cin>>c;
        cout<<c;
        s1.push_back(c);
    }
    ll temp=0;
    ll top,top1;
    fr(i,s1.size())
    {   if(isdigit(s1[i]))
        {   temp = temp*10+int(s1[i]);}
        else if(s1[i]==' ')
        {   s.push(temp);
            temp=0;
        }
        else{
            if(s1[i]=='+')
            {
                top=s.top();
                s.pop();
                top1=s.top();
                s.pop();
                top = top+top1;
                s.push(top);
            }
            else if(s1[i]=='-')
            {
                top=s.top();
                s.pop();
                top1=s.top();
                s.pop();
                top = top-top1;
                s.push(top);
            }
            else if(s1[i]=='*')
            {
                top=s.top();
                s.pop();
                top1=s.top();
                s.pop();
                top = top*top1;
                s.push(top);
            }
            if(s1[i]=='/')
            {
                top=s.top();
                s.pop();
                top1=s.top();
                s.pop();
                top = top/top1;
                s.push(top);                
            }
            if(s1[i]=='^')
            {
                top=s.top();
                s.pop();
                top1=s.top();
                s.pop();
                top = pow(top,top1);
                s.push(top);  
            }   
        }
    }
    cout<<s.top()<<endl;
}