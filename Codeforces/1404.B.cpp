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
vi D;
int maxb;

void dfs(int u,int p)
{
	D[u] = D[p]+1;
	for(auto v:A[u])
	{
		if(v==p) continue;
		else
		{
			dfs(v,u);
		}
	}
}

int main()
{
	test()
	{
		int n,a,b,da,db;
		cin>>n>>a>>b>>da>>db;
		
		A.clear();
		D.clear();

		A.resize(n+1);
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			A[u].push_back(v);
			A[v].push_back(u);
		}
		if(db<=2*da) cout<<"Alice"<<endl;
		else
		{
			D.resize(n+1);
			D[0]=-1;
			dfs(a,0);
			if(D[b]<=da) cout<<"Alice"<<endl;
			else
			{
				int en=0;
				for(int i=1;i<=n;i++)
				{
					if(D[en]<D[i])
					{
						en=i;
					}
				}	
				D[0]=-1;
				dfs(en,0);
				int mad = 0;
				for(int i=1;i<=n;i++) mad = max(D[i],mad);
				if(mad>2*da) cout<<"Bob"<<endl;
				else cout<<"Alice"<<endl;
			}

		}
		
	}
}	