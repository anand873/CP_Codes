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
const ll INF = 1e12+5;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vpii> V(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		V[u].push_back({v,w});
		V[v].push_back({u,w});
	}
	vector<pair<int,ll>> dis(n+1,{1,INF});
	dis[1]={1,0};
	set<pair<ll,int>> S;
	for(int i=1;i<=n;i++)
	{
		S.insert({dis[i].second,i});
	}
	while(!S.empty())
	{
		int u = S.begin()->second;
		S.erase(S.begin());
		for(auto v:V[u])
		{
			if(dis[v.first].second>dis[u].second+v.second)
			{
				S.erase({dis[v.first].second,v.first});
				dis[v.first].second = dis[u].second+v.second;
				dis[v.first].first = u;
				S.insert({dis[v.first].second,v.first});
			}
		}
	}
	if(dis[n].second==INF) {cout<<-1<<endl;return 0;}
	vi P;
	int curr=n;
	while(curr!=1)
	{
		P.push_back(curr);
		curr=dis[curr].first;
	}
	P.push_back(1);
	reverse(all(P));
	prinv(P);
}	