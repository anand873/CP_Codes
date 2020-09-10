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
	fastio;
	int n,m;
	cin>>n>>m;
	vector<vector<char>> V(n,vector<char>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>V[i][j];
		}
	}
	vvi dpu(n,vi(m,1)),dpd(n,vi(m,1)),dpl(n,vi(m,1)),dpr(n,vi(m,1));

	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(V[i][j]==V[i][j-1]) dpl[i][j] = dpl[i][j-1]+1;
		}
		for(int j=m-2;j>=0;j--)
		{
			if(V[i][j]==V[i][j+1]) dpr[i][j] = dpr[i][j+1]+1;
		}
	}

	for(int j=0;j<m;j++)
	{
		for(int i=1;i<n;i++)
		{
			if(V[i][j]==V[i-1][j]) dpu[i][j] = dpu[i-1][j]+1;
		}
		for(int i=n-2;i>=0;i--)
		{
			if(V[i][j]==V[i+1][j]) dpd[i][j] = dpd[i+1][j]+1;
		}
	}
	vvi dptl(n,vi(m,1)),dptr(n,vi(m,1));
	ll ans = 0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(V[i][j]==V[i][j-1])
			{
				dptl[i][j] = min(dptl[i][j-1]+1,min(dpu[i][j],dpd[i][j]));
			}
		}
		for(int j=m-2;j>=0;j--)
		{
			if(V[i][j]==V[i][j+1])
			{
				dptr[i][j] = min(dptr[i][j+1]+1,min(dpu[i][j],dpd[i][j]));
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ans += min(dptl[i][j],dptr[i][j]);
		}
	}
	cout<<ans<<endl;

}	