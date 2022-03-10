#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

#define ll                  long long
#define ld                  long double
#define lf                  long float
#define scl(n)              scanf("%ll", &n)
#define scd(n)              scanf("%ld", &n)
#define scf(n)              scanf("%lf", &n)
#define pfl(x)              printf("%ld\n",x)
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

ll get_moves(ll k)
{   ll ans=0;
    if(k==1)
    {   return 0;}
    while(k>1)
    {   ans+=k%2;
        ans+=1;
        k/=2;
    }
    return ans;
}

int main()
{
    boost();
    ll t;
    ll n,k;
    ld k1;
    cin>>t;
    vector<pair<ld,ll>> c;
    pair<ld, ll> temp;
    ll ans=0;

    fr(i,t)
    {   c.clear();
        ans=0;
        cin>>n>>k;
        temp.F=0;
        fr(j,n)
        {   cin>>temp.S;
            c.pb(temp);
        }
        fr(j,n)
        {   cin>>k1;
            c[j].S=get_moves(c[j].S);
            if(c[j].S!=0)
            {c[j].F=k1/c[j].S;}
            else
            {   ans+=k1;
                c[j].F=0;
            }
        }
        sort(c.begin(),c.end());
        ll op=n-1;
        while(k>0 && op>=0)
        {   if(c[op].S<=k && c[op].F!=0)
            {   k-=c[op].S;
                ans=ans + c[op].S*c[op].F;
            }
            op-=1;
        }
        cout<<ans<<endl;
    }
}