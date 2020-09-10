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

vi ST;
vvi A;
vi vis;

void dfs(int u)
{
	ST[u] = 1;
	vis[u]=true;
	for(auto v:A[u])
	{
		if(!vis[v])
		{
			dfs(v);
			ST[u] += ST[v];
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
		A.resize(n+1);
		vis.resize(n+1);
		ST.resize(n+1);
		vpii E;
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			A[u].push_back(v);
			A[v].push_back(u);
			E.push_back({u,v});
		}
		
		int m;
		cin>>m;
		vi K(m);
		take(K,0,m);

		dfs(1);

		sort(all(K));

		vl X;
		if(m>n-1)
		{
			for(int i=0;i<n-1;i++) X.push_back(K[i]);

			for(int i=n-1;i<m;i++)
			{
				X[n-2] = (X[n-2]*K[i])%MOD;
			} 
		}
		else
		{
			for(int i=0;i<m;i++) X.push_back(K[i]);
			for(int i=m;i<n-1;i++) X.push_back(1);

			sort(all(X));
		}
		vl EdW(n-1);
		for(int i=0;i<n-1;i++)
		{
			int x = E[i].first;
			int y = E[i].second;

			if(ST[x]>ST[y]) swap(x,y);
			EdW[i] = (ll)ST[x]*(n-ST[x]);
		}
		sort(all(EdW));
		reverse(all(EdW));

		reverse(all(X));
		ll ans = 0;
		for(int i=0;i<n-1;i++)
		{
			ans += ((EdW[i]%MOD)*X[i])%MOD;
			ans%=MOD;
		}
		cout<<ans<<endl;

		ST.clear();
		A.clear();
		vis.clear();

	}
}	