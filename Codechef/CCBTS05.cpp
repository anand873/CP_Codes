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

vector<int> P;
vector<vector<pair<int,int>>> V;
vector<vector<int>> PP;
vector<int> H;
vector<ll> DA;

void dfs(int u,int p)
{
  P[u] = p;
  PP[u][0] = p;
  H[u] = H[p] + 1;
  for(auto v:V[u])
  {
    if(v.first!=p)
    {
    	DA[v.first] = DA[u] + v.second;
      	dfs(v.first,u);
    }
  }
}

int lca(int u,int v)
{
  if(H[u]>H[v]) swap(u,v);
  int diff = H[v]-H[u];
  int curr = 0;
  while(diff)
  {
    if(diff%2) v = PP[v][curr];
    diff/=2;
    curr++;
  }
  assert(H[u]==H[v]);
  if(u==v) return u;
  for(int i=19;i>=0;i--)
  {
    if(PP[u][i]!=PP[v][i])
    {
      u = PP[u][i];
      v = PP[v][i];
    }
  }
  return P[u];
}
int main()
{
	fastio
	test()
	{
		int n,q,r;
		cin>>n>>q>>r;
		V.resize(n+1);
		P.resize(n+1);
	    PP.resize(n+1,vector<int>(20));
	    H.resize(n+1);
	    DA.resize(n+1);
		for(int i=0;i<n-1;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			V[u].push_back({v,w});
			V[v].push_back({u,w});
		}
		dfs(1,0);
	    for(int i=1;i<20;i++)
	    {
	      for(int j=1;j<=n;j++)
	      {
	        PP[j][i] = PP[PP[j][i-1]][i-1];
	      }
	    }
		for(int i=0;i<q;i++)
		{
			int u,v;
			cin>>u>>v;
			cout<<DA[u] + DA[v] - 2*DA[lca(u,v)]<<"\n";
		}
		V.clear();
		PP.clear();
		P.clear();
		DA.clear();
		H.clear();
	}
}	