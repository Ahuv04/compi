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

map<ll,ll> m1;
vector<ll> fac;
vector<ll> p2;

ll nearest_fac(ll k)
{   ll temp=2;
    ll ans=1;
    while(ans<k)
    {   ans*=temp;
        temp+=1;
    }

    if(ans==k && find(fac.begin(),fac.end(),ans)==fac.end())
    {   return k;}
    temp-=1;
    ans/=temp;
    while(find(fac.begin(),fac.end(),ans)!=fac.end())
    {   temp-=1;
        ans/=temp;
    }
    return ans;
}

ll nearest_2(ll k)
{   ll ans=1;
    while(ans<k)
    {   ans*=2;}
    if(ans==k && find(p2.begin(),p2.end(),ans)==p2.end())
    {return k;}

    ans/=2;
    while(find(fac.begin(),fac.end(),ans)!=fac.end())
    {  ans/=2;
    }
    return ans;
}

ll get_ans(ll k)
{   
    if(m1.find(k)!=m1.end())
    {   return m1[k];}

    ll rem = k - nearest_fac(k);
    ll rem1= k-nearest_2(k);
    if(rem<rem1)
    {   fac.pb(rem);}
    else
    {   rem=rem1;
        p2.pb(rem);
    }

    m1[k]=1+get_ans(rem);
    return m1[k];
}

int main()
{   ll n,m;
    boost();
    cin>>n;
    m1[0]=0;
    m1[1]=1;
    m1[2]=1;
    m1[4]=1;
    m1[3]=2;
    m1[5]=2;
    m1[6]=1;
    fr(i,n)
    {   p2.clear();
        fac.clear();
        cin>>m;
        cout<<get_ans(m)<<endl;
    }
}