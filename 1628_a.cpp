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

vector<ll> v;

vector<ll> get_ans(ll a)
{   vector<ll> cop = v;
    sort(cop.begin(),cop.end());
        


}

int main()
{
    boost();
    ll n;
    cin>>n;
    ll m;
    wh(n)
    {   ll temp;
        cin>>m;
        fr(i,m)
        {cin>>temp;
            v.pb(temp);
        }
        vector<ll> ans=get_ans(0);
        fr(i,ans.size())
        {   cout<<ans[i]<<" ";}
        cout<<endl;
        v.clear();
    }
}