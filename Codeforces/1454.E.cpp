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
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

vvi V;
vi vis;
int bad=-1;
vi ST;
vi P;
void dfs(int u,int p)
{
	ST[u]=1;
	vis[u]=true;
	for(auto v:V[u])
	{
		if(v==p) continue;
		if(vis[v])
		{
			if(bad==-1)
			{
				bad = v;
			}
		}
		else
		{
			P[v] = u;
			dfs(v,u);
			ST[u] += ST[v];
		}
	}
}
int main()
{
	test()
	{
		int n;
		cin>>n;
		V.resize(n+1);
		vis.resize(n+1);
		ST.resize(n+1);
		P.resize(n+1);
		for(int i=0;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			V[u].push_back(v);
			V[v].push_back(u);
		}
		dfs(1,0);
		ll ans = (ll)n*(n-1)/2;
		
		ans += (ll)ST[bad]*(n-ST[bad]);
		cout<<ans<<endl;
		V.clear();
		vis.clear();
		ST.clear();
		P.clear();
	}
}	