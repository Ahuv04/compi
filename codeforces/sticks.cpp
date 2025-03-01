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
    vector<ll> arr;
    vector<ll> cost;
    ll temp;

    ll avg=0;
fr(i,n)
    {   cin>>temp;
    arr.pb(temp);}
fr(i,n)
    {   cin>>temp;
    cost.pb(temp);}

    temp=0;
    fr(i,n)
    {   avg=avg+arr[i]*cost[i];
        temp+=cost[i];
    }

    ll avg1;
    ll ans=0;
    ll ans_temp=0;
    if(avg%temp==0)
    {   avg/=temp;
        fr(i,n)
        {   ans+=abs(avg-arr[i])*cost[i];}
    }
    else{
        avg1=avg/temp+1;
        avg/=temp;
        fr(i,n)
        {   ans+=abs(avg-arr[i])*cost[i];
            ans_temp+=abs(avg1-arr[i])*cost[i];
        }
        ans=min(ans,ans_temp);
    }
    cout<<ans<<endl;
}