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
    vector<string> v;
    vector<string> v1;
    string temp;
    map<ll,char> m;
    ll n;
    cin>>n;
    fr(i,2*n-2)
    {  cin>>temp;
        v.pb(temp);
        if(temp.size()==n-1)
        {   v1.pb(temp);}
    }
    string suffix;
    string prefix;
    if(v1[0].substr(0,n-2).compare(v1[1].substr(1,n-1))==0 && (v1[1][0]==v[1][0] || v1[1][0]==v[1][1]))
    {   //cout<<v1[0].substr(0,n-2)<<endl;
        suffix=v1[0];
        prefix=v1[1];
    }
    else
    {   suffix=v1[1];
        prefix=v1[0];
    }
    // cout<<prefix<<"(((((("<<endl;
    // cout<<suffix<<"))))))))"<<endl;

    // cout<<"/////////////////////////////////////////"<<endl;
    // string a="baba";
    // cout<<prefix<<endl;
    // cout<<a<<endl;
    // cout<<prefix.substr(0,a.size())<<endl;
    // cout<<prefix.substr(0,a.size()).compare(a)<<endl;
    // cout<<"/////////////////////////////////////////"<<endl;

    fr(i,2*n-2)
    {
 if(m[v[i].size()]=='S')
            {   cout<<'P';
            }
            else
            {   if(m[v[i].size()]=='P')
                {cout<<'S';}
                else
                {
            if(prefix.substr(0,v[i].size()).compare(v[i])==0)
            {m[v[i].size()]='P';
            cout<<'P';
            // cout<<v[i]<<"--------------------"<<endl;
            }
            else{m[v[i].size()]='S';
            cout<<'S';
            // cout<<v[i]<<"&&&&&&&&&&&&&&&&&&&&&"<<endl;            
            }
                }
            }
    }
}