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

vvi A;
vi H;
vector<set<pii>> S;
vi In,Out;
int tim=0;
vi Height;
vi DT;

void dfsH(int u,int p)
{
	H[u] = MOD;
	Height[u] = Height[p]+1;
	for(auto v:A[u])
	{
		if(v!=p)
		{
			dfsH(v,u);
			H[u] = min(H[u],H[v]+1);
		}
	}
	if(H[u]==MOD) H[u] = 0;	
}
void dfs(int u,int p)
{
	In[u] = tim++;
	DT.push_back(u);
	for(auto v:S[u])
	{
		if(v.second==p) continue;
		dfs(v.second,u);
	}
	Out[u] = tim++;
}

bool is_upar(int u, int v)
{
	return (In[u]>Out[v]);
}

int main()
{
	test()
	{
		int n;
		cin>>n;
		A.resize(n+1);
		H.resize(n+1);
		S.resize(n+1);
		In.resize(n+1);
		Out.resize(n+1);
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			A[u].push_back(v);
			A[v].push_back(u);
		}
		Height.resize(n+1);
		dfsH(1,0);

		for(int i=1;i<=n;i++)
		{
			for(auto v:A[i])
			{
				S[i].insert({H[v],v});
			}
		}
		prinv(H);
		dfs(1,0);
		int k = 0;
		prinv(DT);
		for(int i=1;i<DT.size();i++)
		{
			if(is_upar(DT[i],DT[i-1]))
			{
				cout<<DT[i]<<" "<<DT[i-1]<<" "<<Height[DT[i-1]]+Height[DT[i]]-2<<endl;
				k = max(k,Height[DT[i-1]]+Height[DT[i]]-2);
			}
		}
		for(int i=1;i<=n;i++) k = max(k,Height[i]-1);
		cout<<k<<endl;

		A.clear();
		S.clear();
		H.clear();
		Height.clear();
		In.clear();
		Out.clear();
		tim = 0;
		DT.clear();
	}
}
	