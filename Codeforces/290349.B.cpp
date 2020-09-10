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
	fastio
	int n;
	cin>>n;
	cin>>n;
	vvi X(n+1,vi(n+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cin>>X[i][j];
	}
	int maxs;
	cin>>maxs;

	vvl dp(n+1,vl(n+1));
	for(int j=1;j<=n;j++) dp[1][j] = X[1][j];

	for(int j=1;j<=n;j++)
	{
		for(int i=2;i<=n;i++)
		{
			dp[i][j] += dp[i-1][j] + X[i][j];
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			dp[i][j] += dp[i][j-1];
		}
	}
	int ans = 0;
	int low = 1,high = n;

	while(low<=high)
	{
		int mid = low + (high-low)/2;

		bool can=true;

		for(int i=1;i+mid-1<=n;i++)
		{
			for(int j=1;j+mid-1<=n;j++)
			{
				if(dp[i+mid-1][j+mid-1]+dp[i-1][j-1]-dp[i+mid-1][j-1]-dp[i-1][j+mid-1]>maxs) can=false;
			}
		}

		if(can)
		{
			ans = mid;
			low = mid+1;
		}
		else high = mid-1;
	}
	cout<<ans<<endl;

	


}	