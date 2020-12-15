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

int main()
{
	int n,m;
	cin>>n>>m;
	map<pii,int> M;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		M[{u,v+n}]=w;
	}

	int low=1,high=MOD;
	int ans=-1;
	while(low<=high)
	{
		int mid = low+(high-low)/2;
		vector<set<int>> A(2*n+1);
		for(auto ed:M)
		{
			if(ed.second<=mid)
			{
				A[ed.first.first].insert(ed.first.second);
				A[ed.first.second].insert(ed.first.first);
			}
		}
		set<pii> S;
		vi vis(2*n+1);
		for(int i=1;i<=2*n;i++)
		{
			S.insert({A[i].size(),i});
		}
		if(S.begin()->first==0)
		{
			low = mid+1;
		}
		else
		{
			while(!S.empty())
			{
				auto Curr = *S.begin();
				if(Curr.first==0)
				{
					low = mid+1;
					break;
				}
				int p = Curr.second;
				int q = *A[p].begin();
	
				if(vis[q]) break;
				else
				{
					vis[p]=true;
					S.erase(Curr);
					vis[q]=true;
					S.erase({A[q].size(),q});
				}
				for(auto v:A[q])
				{
					if(!vis[v])
					{
						S.erase({A[v].size(),v});
						A[v].erase(q);
						S.insert({A[v].size(),v});
					}
				}
			}
			if(S.empty())
			{
				ans = mid;
				high = mid-1;
			}
		}
	}
	cout<<ans<<endl;
}	