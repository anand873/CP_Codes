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
	int n,m,Sx,Sy;
	cin>>n>>m>>Sx>>Sy;
	vpii V;
	V.push_back({Sx,Sy});
	V.push_back({Sx,1});
	for(int j=2;j<=m;j++)
	{
		if(j!=Sy) V.push_back({Sx,j});
	}
	for(int i = Sx+1;i<=n;i++)
	{
		if((i-Sx)%2)
		{
			for(int j=m;j>=1;j--) V.push_back({i,j});
		}
		else
		{
			for(int j=1;j<=m;j++) V.push_back({i,j});
		}
	}
	int last;
	if((n-Sx)%2==0)
	{
		for(int i=Sx-1;i>0;i--)
		{
			if((Sx-i)%2==0)
			{
				for(int j=1;j<=m;j++) V.push_back({i,j});
			}
			else
			{
				for(int j=m;j>=1;j--) V.push_back({i,j});
			}
		}
	}
	else
	{
		for(int i=Sx-1;i>0;i--)
		{
			if((Sx-i)%2)
			{
				for(int j=1;j<=m;j++) V.push_back({i,j});
			}
			else
			{
				for(int j=m;j>=1;j--) V.push_back({i,j});
			}
		}
	}

	for(auto p:V)
	{
		prinp(p);
	}
}	