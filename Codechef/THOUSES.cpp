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

ll dfs(int u, int p)
{
	vl T;
	for(auto v:V[u])
	{
		if(v!=p)
		{
			ll x = dfs(v,u);
			T.push_back(x);
		}
	}
	if(T.empty()) return 1;

	sort(all(T));
	reverse(all(T));
	ll currans = 1;
	for(int i=0;i<(int)T.size();i++)
	{
		currans += (T[i]*(i+1));
	}
	return currans;
}

int main()
{
	fastio
	test()
	{
		int n,x;
		cin>>n>>x;
		V.resize(n+1);
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			V[u].push_back(v);
			V[v].push_back(u);
		}
		ll ans = dfs(1,0);
		ans = ((ans%MOD)*x)%MOD;
		cout<<ans<<'\n';
		V.clear();
	}
}