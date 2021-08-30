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

vvi V,P;
int n,m;
vl Ans;
vi IT,OT;
int x;
vi vis;

ll findans(int u)
{
	// cout<<u<<endl;
	if(Ans[u]!=-2) return Ans[u];
	Ans[u] = 0;
	for(auto p:P[u])
	{
		if(p == u) Ans[u] += MOD;
		else Ans[u] += findans(p);
	}
	return Ans[u];
}

void dfs(int u)
{
	vis[u] = true;
	IT[u] = x++;
	for(auto v:V[u])
	{
		if(!vis[v])
		{
			dfs(v);
		}
		if(v==u)
		{
			Ans[u] = MOD;
		}
		else if(IT[v] < IT[u] && OT[v] == 0)
		{
			Ans[v] = MOD;
		}
	}
	OT[u] = x++;
}

int main()
{
	fastio
	test()
	{
		x = 0;
		cin>>n>>m;
		V.resize(n+1);
		P.resize(n+1);		
		Ans.resize(n+1,-2);
		Ans[1] = 1;
		IT.resize(n+1);
		OT.resize(n+1);
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			V[a].push_back(b);
			P[b].push_back(a);
		}
		vis.resize(n+1);
		dfs(1);

		queue<int> Leaves;
		for(int i=1;i<=n;i++)
		{
			if(V[i].size()==0 && Ans[i]!=0)
			{
				Leaves.push(i);
			}
		}
		
		while(!Leaves.empty())
		{
			int u = Leaves.front();
			Leaves.pop();
			Ans[u] = findans(u);
		}
		for(int i=1;i<=n;i++)
		{
			if(Ans[i]==0) cout<<0<<" ";
			else if(Ans[i]==1) cout<<1<<" ";
			else if(Ans[i] < MOD && Ans[i]>1) cout<<2<<" ";
			else cout<<-1<<" ";
		}
		cout<<"\n";
		V.clear();
		P.clear();
		Ans.clear();
	}
}	