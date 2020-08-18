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
	vpii P(m);
	vector<int> P1,P2;
	for(int i=0;i<m;i++)
	{
		cin>>P[i].first>>P[i].second;
	}
	P1 = {P[0].first,P[0].second};
	P2 = P1;
	for(int i=1;i<m;i++)
	{
		if(P[i].first!=P1[0]&&P[i].first!=P1[1]&&P[i].second!=P1[0]&&P[i].second!=P1[1])
		{
			P2 = {P[i].first,P[i].second};
			break;
		}
	}
	bool maincan=false;
	for(auto p1:P1)
	{
		for(auto p2:P2)
		{
			bool can = true;
			for(int i=0;i<m;i++)
			{
				if(P[i].first!=p1&&P[i].first!=p2&&P[i].second!=p1&&P[i].second!=p2)
				{
					can = false;
					break;
				}
			}
			if(can) maincan=true;
		}
	}
	if(maincan) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;



}	