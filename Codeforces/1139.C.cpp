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
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}

int sz=0;
vector<bool> vis;
vvi A;
void dfs(int u)
{
	vis[u]=true;
	sz++;
	for(auto v:A[u])
	{
		if(!vis[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	fastio
	int n,k;
	cin>>n>>k;
	A.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(w==0)
		{
			A[u].push_back(v);
			A[v].push_back(u);
		}
	}
	ll ans=0;
	vis.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		sz=0;
		if(!vis[i]) 
		{
			dfs(i);
			ans += powN(sz,k);
			ans%=MOD;
		}
	}
	cout<<((powN(n,k)-ans)%MOD+MOD)%MOD<<endl;
}
