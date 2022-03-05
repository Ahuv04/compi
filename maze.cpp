#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void ok(int * arr,int * bo,int a1, int b1, int pre_a, int pre_b)
{	int k,bo1;
	bo1 =*((bo+pre_a*b1)+pre_b); 
	k =*((arr+pre_a*b1)+pre_b);
	
	if(bo1!=0)
	{	return;}
	
	bo1=1;
	return;
}

int main()
{	ll n;
	cin>>n;
	ll g,bad;
	
	while(n!=0)
	{	n--;
		ll a,b;
		g=0;
		bad=0;
		char temp;
		cin>>a>>b;
		int m[a][b];
		int bo[a][b];

		for(ll i=0;i<a;i++)
		{	for(ll j=0;j<b;j++)
			{	cin>>temp;
				bo[i][j]=0;
				if(temp=='.')
				{m[i][j]=0;}
				else if(temp=='G')
				{	m[i][j]=1;
					g++;
				}
				else if(temp=='B')
				{	m[i][j]=2;
					bad++;
				}
				else
				{	m[i][j]=3;}
			}
		}

		if(g==0 || bad ==0)
		{
			cout<<"Yes"<<endl;
			continue;
		}

		if(m[a-2][b-1]==2 || m[a-1][b-2]==2)
		{goto ok1;}

		for(ll i=0;i<a;i++)
		{	for(ll j=0;j<b;j++)
			{	if(m[i][j]==2)
				{	if(i+1<a)
					{	if(m[i+1][j]==1)
						{	goto ok1;}
						m[i+1][j]=3;
					}
					if(i-1>=0)
					{	if(m[i-1][j]==1)
						{	goto ok1;}
						m[i-1][j]=3;

					}
					if(j+1<n)
					{	if(m[i][j+1]==1)
						{	goto ok1;}
						m[i][j+1]=3;

					}
					if(j-1>=0)
					{	if(m[i][j-1]==1)
						{	goto ok1;}
						m[i][j-1]=3;
					}
				}
			}
		}

		ok((int *)m,(int *)bo,a,b,a-1,b-1);
		
		cout<<bo[a-1][b-1];

		for(ll i=0;i<a;i++)
		{	for(ll j=0;j<b;j++)
			{	if(m[i][j]==1)
				{	goto ok1;}
			}
		}

		cout<<"Yes"<<endl;
		continue;

		ok1 :
		cout<<"No"<<endl;

	}
	return 0;
}