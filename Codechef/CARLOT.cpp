//Author: AnandRaj uux
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll; 

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e5+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
/////////////////FastExp///////////////////
//////////////////Sieve////////////////////
vector<bool> is_prime(MAX+1, true);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
        	for (j = i * i; j <= MAX; j += i)
            	is_prime[j] = false;
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	test()
	{
		int m,n;
		cin>>m>>n;
		vector<vector<char>> C(m+1,vector<char>(n+1));
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>C[i][j];
			}
		}
		vi Min(m+1,500),Max(m+1,-1);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(C[i][j]=='P') {Min[i]=min(Min[i],j);Max[i]=max(Max[i],j);}
			}
		}
		int cost=0;

		int fi,la;
		int st=m+1,en=-1;
		for(int i=1;i<=m;i++) 
		{
			if(Max[i]!=-1) {st=i;break;}
		}
		for(int i=m;i>=1;i--)
		{
			if(Max[i]!=-1) {en=i;break;}
		}
		
		if(st<=m)
		{
			if(st%2) fi=Min[st];
			else fi=Max[st];
		}

		for(int i=st;i<=en;i++)
		{
			//cout<<endl;
			//what(i);
			if(i%2)
			{
				if(i==en)
				{
					la=Max[i];
				}
				else
				{
					la=max(Max[i],Max[i+1]);
				}
				//what(fi);
				//what(la);

				if(la==-1)
				{
					cost+=(i!=en);
				}
				else {cost+=max(0,la-fi)+(i!=en);fi=max(fi,la);}
				//what(cost);
			}
			else
			{
				if(i==en)
				{
					la=Min[i];
				}
				else
				{
					la=min(Min[i],Min[i+1]);
				}
				//what(fi);
				//what(la);
				if(la==500)
				{
					cost+=(i!=en);
				}
				else {cost+=max(0,fi-la)+(i!=en);fi=min(fi,la);}
				//what(cost);
			}
		}
		cout<<cost<<endl;

	}
}		