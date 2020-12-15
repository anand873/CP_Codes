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

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<vpii> V(n+1);
	map<pii,int> M;
	map<pii,int> W;
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		if(x>y) swap(x,y);
		W[{x,y}] = w;
		V[x].push_back({y,w});
		V[y].push_back({x,w});
	}
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;

		vector<vpii> ADJ;
		vi D(n+1,MOD);
		vi P(n+1,-1);

		D[a]=0;
		set<pii> Q;
		Q.insert({0,a});
		while(!Q.empty())
		{
			int u = Q.begin()->second;
			Q.erase(Q.begin());
			for(auto edge:V[u])
			{
				int v = edge.first;
				int w = edge.second;

				if(D[u]+w<D[v])
				{
					Q.erase({D[v],u});
					D[v]=D[u]+w;
					P[v]=u;
					Q.insert({D[v],v});
				}
			}
		}
		prinv(D);
		for(int v=b;v!=a;v=P[v])
		{
			int x = v;
			int y = P[v];
			// cout<<y<<" ";
			if(x>y) swap(x,y);
			M[{x,y}]++;
		}
	}
	int MaxDiff=0;
	ll sum=0;
	for(auto x:M)
	{
		cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
		MaxDiff = max(MaxDiff,x.second*W[x.first]);
		sum += x.second*W[x.first];
	}
	cout<<sum-MaxDiff<<endl;
}	