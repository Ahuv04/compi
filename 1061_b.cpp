// exceeds mem limit at test case 10

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define scf(n)              scanf("%lf", &n)
#define pfl(x)              printf("%lld\n",x)
#define md                  10000007
#define mm					1000000001
#define pb                  push_back
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)

void boost()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << setprecision(10);
}

vector<ll> v;
int main()
{
    boost();
    ll n,m;
    ll sum=0;
    ll req=0;
    ll temp;
    ll curr_max=0;
    ll rem=0;
    std::vector<ll>::iterator it;
    cin>>n>>m;

    fr(i,n)
    {   cin>>temp;
        if(temp!=0)
        {
        sum+=temp;
        if(temp>curr_max)
        {   fr(j,temp-curr_max)
            {   v.pb(curr_max+j+1);}
            rem= rem + temp -curr_max;
            curr_max=temp;
        }
        if(rem!=0)
        {   while(temp>0)
            {   it=find(v.begin(),v.end(),temp);
                if(it!=v.end())
                {   rem-=1;
                    v.erase(it);
                    break;
                }
                temp-=1;
            }
            req+=1;
        }
        else
        {   req+=1;}
        }
    }
    req+=rem;
    cout<<sum-req<<endl;
}

