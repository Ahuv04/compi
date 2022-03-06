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
    ll n,m;
    boost();

    vector<ll> v;
    ll ans;
    ll temp;
    ll sumb,sumr;
    ll k,q;
    cin>>n;

    fr(i,n)
    {
        k=0;
        sumb=0;
        sumr=0;
        ans=0;
        v.clear();

        cin>>m;
        fr(j,m)
        {   cin>>temp;
            v.pb(temp);
        }
        q=v.size()-1;
        sort(v.begin(),v.end());
        sumb+=v[0];
        k=1;
        while(k<q)
        {   sumb+=v[k];
            sumr+=v[q];
            if(sumr>sumb)
            {   ans=1;
                break;
            }
            k+=1;
            q-=1;
        }
        if(ans==1)
        {
            cout<<"YES"<<endl;
        }
        else{cout<<"NO"<<endl;}
    }
}