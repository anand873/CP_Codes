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
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;
vvi A;
vi dp;
vi dif;
string C;
vi CC;

void dfs(int u,int p)
{
	dp[u]=0;
	dif[u]=0;

	for(auto v:A[u])
	{
		if(v!=p)
		{
			dfs(v,u);
			dp[u] += dp[v]+abs(dif[v]);
			dif[u] += dif[v];
		}
	}
	if(C[u-1]-'0'!=CC[u])
	{
		if(C[u-1]=='0')
		{
			dif[u] -= 1;
		}
		else dif[u] += 1;
	}
}

int main()
{
	test()
	{
		int n;
		cin>>n;
		A.resize(n+1);
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			A[u].push_back(v);
			A[v].push_back(u);
		}
		cin>>C;
		CC.resize(n+1);
		queue<int> Q;
		Q.push(1);
		vi vis(n+1);
		vis[1]=true;
		CC[1]=1;
		while(!Q.empty())
		{
			int curr = Q.front();
			Q.pop();
			for(auto v:A[curr])
			{
				if(!vis[v])
				{
					CC[v] = 1-CC[curr];
					vis[v]=true;
					Q.push(v);
				}
			}
		}
		dp.resize(n+1);
		dif.resize(n+1);
		dfs(1,-1);
		ll ans = INF;
		if(dif[1]==0)
		{
			ans = min(ans,(ll)dp[1]);
		}

		for(int i=0;i<n;i++)
		{
			C[i] = '0'+(1-(C[i]-'0'));
		}
		dfs(1,-1);
		if(dif[1]==0)
		{
			ans = min(ans,(ll)dp[1]);
		}

		if(ans==INF) cout<<-1<<endl;
		else cout<<ans<<endl;

		A.clear();
		dp.clear();
		dif.clear();
		CC.clear();
		
	}
}	