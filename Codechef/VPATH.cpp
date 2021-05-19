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
int MOD = 1e9+7,MAX = 5e5+5;
const ll INF = 1e18+5;

vvi V;
vvl dp;

void dfs(int u,int p)
{
	ll sum=0;
	ll sqsum=0;
	dp[u][1] = 1;
	for(auto v:V[u])
	{
		if(v!=p)
		{
			dfs(v,u);
			dp[u][1] += 2ll*dp[v][1]%MOD;
			dp[u][1] %= MOD;

			dp[u][0] += dp[v][0];
			dp[u][0] %= MOD;

			sum += dp[v][1];
			sqsum += (dp[v][1]*dp[v][1])%MOD;
			sum%=MOD;
			sqsum%=MOD;
		}
	}
	dp[u][0] += (((sum*sum)%MOD - sqsum)%MOD+MOD)%MOD;
	dp[u][0] %= MOD;
}

int main()
{
	fastio
	test()
	{
		int n;
		cin>>n;
		V.resize(n+1);
		dp.resize(n+1,vl(2));
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			V[u].push_back(v);
			V[v].push_back(u);
		}
		dfs(1,0);
		// for(int i=1;i<=n;i++)
		// {
		// 	cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		// }
		cout<<(dp[1][0] + dp[1][1]) % MOD<<'\n';
		V.clear();
		dp.clear();
	}
}