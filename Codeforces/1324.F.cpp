//Author: AnandRaj doubleux
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

vi C(2*MAX);
vvi V(2*MAX);
vi dp(2*MAX);
vi A(2*MAX);
vi vis(2*MAX);

int dfs(int u)
{
	if(vis[u]) return dp[u];
	vis[u]=true;
	int x=C[u];
	for(auto v:V[u])
	{
		if(!vis[v])
		{
			x+=max(0,dfs(v));
		}
	}
	dp[u]=x;
	return dp[u];
}

int dfs2(int u)
{
	if(vis[u]) return A[u];
	vis[u]=true;
	A[u]=dp[u];
	for(auto v:V[u])
	{
		dp[u]-=max(0,dp[v]);
		dp[v]+=max(0,dp[u]);
		A[v]=dfs2(v);
		dp[v]-=max(0,dp[u]);
		dp[u]+=max(0,dp[v]);
	}
	return A[u];
}

int main()
{	
	int n;
	cin>>n;
	C.resize(n+1);
	dp.resize(n+1);
	A.resize(n+1);
	V.resize(n+1);
	vis.resize(n+1);
	take(C,1,n);
	for(int i=1;i<=n;i++) if(!C[i]) C[i]=-1;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	dp[1]=dfs(1);
	for(int i=1;i<=n;i++) vis[i]=false;
	A[1]=dfs2(1);
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}		