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

const int MOD = 1e9+7,MAX = 1e6+5;
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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////
vector<string> C,M;
vvi vis;
void dfs(int i, int j)
{
	vis[i][j]=1;
	if(M[i][j]=='R')
	{
		if(!vis[i][j+1]) dfs(i,j+1);
	}
	else if(M[i][j]=='L')
	{
		if(!vis[i][j-1]) dfs(i,j-1);
	}
	else if(M[i][j]=='D')
	{
		if(!vis[i+1][j]) dfs(i+1,j);
	}
	else
	{
		if(!vis[i-1][j]) dfs(i-1,j);
	}

}

int main()
{
	fastio;
	test()
	{
		int n,m;
		cin>>n>>m;
		C.resize(n);
		M.resize(n);
		take(C,0,n);
		take(M,0,n);
		vis.resize(n);
		vpii Main;
		for(int i=0;i<m;i++)
		{
			vis[i].resize(m);
		}
		int ans1=0,ans2=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(vis[i][j]) continue;
				else
				{
					Main.push_back({i,j});
					dfs(i,j);
					ans1+=2;
				}
			}
		}
		cout<<ans1<<endl;

	}
}		