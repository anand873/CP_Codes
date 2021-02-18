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

struct Path
{
	int u;
	ll sumw = 0;
	ll maxw = 0,minw = INF;
	bool operator<(const Path& B) const
	{
		if (sumw - maxw + minw == B.sumw - B.maxw + B.minw) return u<B.u;
		return sumw - maxw + minw < B.sumw - B.maxw + B.minw;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	set<Path> S;
	vector<vpii> A(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		A[u].push_back({v,w});
		A[v].push_back({u,w});
	}
	vector<Path> Ans(n+1);
	for(int i=1;i<=n;i++) Ans[i].u = i;
	Ans[1].u = 1;
	Ans[1].sumw = 0;
	Ans[1].maxw = 0;
	Ans[1].minw = INF;
	S.insert(Ans[1]);
	vi vis(n+1);
	while(!S.empty())
	{
		Path curr = *S.begin();
		S.erase(curr);
		vis[curr.u] = true;
		for(auto v:A[curr.u])
		{
			if(vis[v.first]) continue;
			ll newweight = curr.sumw + v.second;

			Path newv;
			newv.u = v.first;
			newv.sumw = newweight;
			newv.minw = min(curr.minw,(ll)v.second);
			newv.maxw = max(curr.maxw,(ll)v.second);
			// cout<<curr.u<<" "<<newv.u<<" "<<newv.minw<<" "<<newv.maxw<<" "<<newv.sumw<<endl;
			if(S.count(Ans[v.first]))
			{
				if(newv<Ans[v.first])
				{
					S.erase(Ans[v.first]);
					Ans[v.first] = newv;
					S.insert(Ans[v.first]);
				}
			}
			else
			{
				Ans[v.first] = newv;
				S.insert(Ans[v.first]);
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		cout<<Ans[i].sumw - Ans[i].maxw + Ans[i].minw<<" ";
	}
	cout<<"\n";
}	