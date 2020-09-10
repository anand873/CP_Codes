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

vl A;
vvi V;
vector<bool> mark;
vvi P;
vector<bool> vis;
void dfs(int u)
{
	if(mark[u]==true) return;
	for(auto v:P[u])
	{
		for(auto vv:P[v])
		{
			dfs(vv);
			A[u] += A[vv];
			A[vv] = 0;
		}
	}
	mark[u] = true;
}
void ddfs(int u)
{
	vis[u]=true;
	for(auto v:V[u])
	{
		if(!vis[v])
		{
			P[u].push_back(v);
			ddfs(v);
		}
	}
}


int main()
{
	fastio
	test()
	{
		int n,q;
		cin>>n>>q;
		A.resize(n+1);
		take(A,1,n);
		V.resize(n+1);
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			V[u].push_back(v);
			V[v].push_back(u);
		}
		vis.resize(n+1);
		P.resize(n+1);
		ddfs(1);
		mark.resize(n+1);
		while(q--)
		{
			int x;
			cin>>x;
			if(!mark[x]) dfs(x);
		}
		for(int i=1;i<=n;i++) cout<<A[i]<<" ";
		cout<<endl;
		A.clear();
		mark.clear();
		V.clear();
		P.clear();
		vis.clear();
	}	
}
