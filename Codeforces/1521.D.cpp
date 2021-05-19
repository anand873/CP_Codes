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
int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

vvi V;
vvi Ans;

int fath;
vi P,D,C,SC;
int last;

void dfs(int u, int p)
{
	C[u] = u;
	SC[u] = -1;
	for(auto v:V[u])
	{
		if(v!=p)
		{
			dfs(v,u);
			if(D[C[u]] < D[C[v]])
			{
				C[u] = C[v];
			}
			else
			{
				if(SC[u]==-1 || D[SC[u]] < D[C[v]])
				{
					SC[u] = C[v];
				}
			}
		}
	}
}

int find_ans(int u, int p)
{
	int ans = 0;
	int curr = u;
	while(curr!=C[u])
	{
		int maxi = 0;
		int next = -1;
		for(auto v:V[curr])
		{
			if(v!=P[curr])
			{
				if(maxi<D[C[v]])
				{
					maxi = D[C[v]];
					next = v;
				}
			}
		}
		// cout<<curr<<" "<<next<<endl;
		for(auto v:V[curr])
		{
			if(v!=P[curr]&&v!=next)
			{
				int nextlast = find_ans(v,curr);
				Ans.push_back({v,curr,last,v});
				last = nextlast;
			}
		}
		curr = next;
	}
	return curr;
}

int main()
{
	test()
	{
		int n;
		cin>>n;
		V.resize(n+1);
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			V[a].push_back(b);
			V[b].push_back(a);
		}
		queue<int> Q;
		Q.push(1);

		fath=1;
		vi vis(n+1);
		vis[1] = true;
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			fath = u;
			for(auto v:V[u])
			{
				if(!vis[v]) 
				{
					vis[v] = true;
					Q.push(v);
				} 
			}
		}
		D.resize(n+1);
		P.resize(n+1);
		C.resize(n+1);

		D[fath] = 0;
		Q.push(fath);
		vis.clear();
		vis.resize(n+1);
		vis[fath]=1;
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(auto v:V[u])
			{
				if(!vis[v])
				{
					vis[v]=true;
					P[v] = u;
					D[v] = D[u]+1;
					Q.push(v);
				}
			}
		}

		int dia = fath;
		for(int i=1;i<=n;i++)
		{
			if(D[i]>D[dia])
			{
				dia = i;
			}
		}
		dfs(fath,0);
		last = fath;
		int ans = find_ans(fath,0);

		cout<<Ans.size()<<endl;
		for(int i=0;i<Ans.size();i++)
		{
			prinv(Ans[i]);
		}
		P.clear();
		D.clear();
		C.clear();
		V.clear();
		Ans.clear();
	}	
}