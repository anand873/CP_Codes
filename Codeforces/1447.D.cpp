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

void test_case()
{
	int n,m;
	cin>>n>>m;
	string a,b,ta,tb;
	cin>>ta>>tb;
	a = "#" + ta;
	b = "#" + tb;
	vvi dp(n+1,vi(m+1,-MOD));
	for(int i=0;i<=n;i++) dp[i][0] = -i;
	for(int j=0;j<=m;j++) dp[0][j] = -j;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j]) dp[i][j] = 2;
			dp[i][j] = max(dp[i][j], dp[i][j-1] - 1);
			dp[i][j] = max(dp[i][j], dp[i-1][j] - 1);
			dp[i][j] = max(dp[i][j], dp[i-1][j-1] - 2 + 4*(a[i]==b[j]));
			if(j>=2) dp[i][j] = max(dp[i][j], dp[i-1][j-2] - 3 + 4*(a[i]==b[j]));
			if(i>=2) dp[i][j] = max(dp[i][j], dp[i-2][j-1] - 3 + 4*(a[i]==b[j]));
			if(i>=2&&j>=2) dp[i][j] = max(dp[i][j], dp[i-2][j-2] - 4 + 4*(a[i]==b[j]));
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
}

int main()
{
	test_case();
}	