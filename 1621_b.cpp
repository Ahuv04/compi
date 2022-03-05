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

vector<vector<int>> v;

ll get_ans(ll p_min, ll p_max, ll p_duo)
{	ll ans=-1;
	// if(p_min==p_max)
	// {	
	// 	ans=v[p_min][2];}
	ans = v[p_min][2]+v[p_max][2];
	if(p_duo!=-1 && v[p_duo][2]<ans)
	{return v[p_duo][2];}
		return ans;
}

int main()
{  
	boost();
	ll n;
	cin>>n;

	while(n>0)
	{ n-=1;
		v.clear();

		ll m,s=1;
		cin>>m;

		vector<int> p;
		ll a1,a2,a3;

		ll min = mm;
		ll max=-1;

		ll p_min_solo,p_max_solo, p_duo;
		p_duo=-1;

		fr(i,m) 
		{	
			//cin>>p[0]>>p[1]>>p[2];
			cin>>a1>>a2>>a3;
			p.pb(a1);
			p.pb(a2);
			p.pb(a3);

			if(p[0]<min || (p[0]==min && p[2]<v[p_min_solo][2]))
			{	min=p[0];
				p_min_solo=i;
				if(p_duo!=-1 && v[p_duo][0]>min)
				{	p_duo=-1;}
			}
			if(p[1]>max || (p[1]==max && p[2]<v[p_max_solo][2]))
			{	max=p[1];
				p_max_solo=i;
				if(p_duo!=-1 && v[p_duo][1]<max)
				{	p_duo=-1;}
			}
			if(p[0]<=min && p[1]>=max && (p_duo==-1 || p[2]<v[p_duo][2]))
			{
				p_duo=i;
			}

			v.pb(p);
			p.clear();
			cout<<get_ans(p_min_solo,p_max_solo,p_duo)<<endl	;
		}
	}
}