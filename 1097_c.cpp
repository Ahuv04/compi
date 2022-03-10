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
#define F                   first
#define S                   second

void boost()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << setprecision(10);
}

pair<ll,ll> get_score(string s)
{
    pair<ll,ll> ans;
    ll a1,a2=0;
    ll r1,r2=0;
    a1=0;
    r1=1;
    fr(i,s.size())
    {   if(s[i]==')')
        {   a2-=1;
            if(a2<0)
            {   a1=-5;
                break;
            }
        }
        else{a2+=1;}
    }
    reverse(s.begin(),s.end());

    fr(i,s.size())
    {   if(s[i]=='(')
        {   r2-=1;
            if(r2<0)
            {   r1=-5;
                break;
            }
        }
        else{r2+=1;}
    }
    if(a1!=0 && r1!=1)
    {
        ans.F=-1;
        ans.S=0;
    }
    else if(a1==0 && r1==1){
        ans.F=2;
        ans.S=0;
    }
    else if(a1==0)
    {   ans.F=0;
        ans.S=a2;
    }
    else{
        ans.F=1;
        ans.S=-1*r2;
    }
    return ans;
}

int main()
{
    boost();
    ll n;
    cin>>n;
    ll ans=0;
    vector<ll> v;
    string s;
    pair<ll,ll> temp;
    vector<ll>::iterator it;
    map<ll,ll> m;
    fr(i,n)
    {   cin>>s;
        temp = get_score(s);
        if(temp.F!=-1)
        {   
            try{
                if(m[-1*temp.S]>0)
                {m[-1*temp.S]-=1;
                ans+=1;}
                else
                {
                m[temp.S]+=1;
                }

            }
            catch(ll num)
            {  
                m[temp.S]=1;
            }
        }
    }
    cout<<ans<<endl;
}