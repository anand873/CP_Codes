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
	int n,m;
	cin>>n>>m;
	vector<set<int>> A(n+1);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		A[x].insert(y);
		A[y].insert(x);
	}
	int ans = MOD;
	vector<bool> vis(n+1);
	for(int i=1;i<=n;i++)
	{
		for(auto u:A[i])
		{
			if(vis[u]) continue;
			for(auto v:A[u])
			{
				if(vis[v]) continue;
				if(v==i) continue;

				if(A[i].count(v))
				{
					ans = min(ans,(int)A[i].size()+(int)A[u].size()+(int)A[v].size()-6);
				}
			}
		}
		vis[i]=true;
	}
	if(ans == MOD) cout<<-1<<endl;
	else cout<<ans<<endl;

}	