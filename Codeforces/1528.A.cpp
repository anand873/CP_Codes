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
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

vvi V;
vi L,R;

vvl dp;

void dfs(int u, int p)
{
	for(auto v:V[u])
	{
		if(v!=p)
		{
			dfs(v,u);

			dp[u][0] += max(dp[v][0]+abs(L[v]-L[u]),dp[v][1]+abs(R[v]-L[u]));
			dp[u][1] += max(dp[v][0]+abs(L[v]-R[u]),dp[v][1]+abs(R[v]-R[u]));
		}
	}
}

int main()
{
	fastio
	test()
	{
		int n;
		cin>>n;
		V.resize(n+1);
		L.resize(n+1);
		R.resize(n+1);
		dp.resize(n+1,vl(2));

		for(int i=0;i<n;i++)
		{
			cin>>L[i+1]>>R[i+1];
		}
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			V[u].push_back(v);
			V[v].push_back(u);
		}
		dfs(1,0);
		
		cout<<max(dp[1][0],dp[1][1])<<'\n';

		V.clear();
		L.clear();
		R.clear();
		dp.clear();
	}
}	