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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;


int main()
{
	fastio
	int n,m;
	cin>>n>>m;
	vvi A(n+1,vi(m+1));
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		// cout<<s<<endl;
		for(int j=1;j<=m;j++) A[i][j] = (s[j-1]-'0');
	}	

	int q;
	cin>>q;
	vvi dp(n+2,vi(m+2));
	while(q--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		dp[x1][y1]++;
		dp[x1][y2+1]--;
		dp[x2+1][y1]--;
		dp[x2+1][y2+1]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j] += dp[i][j-1];
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][j] += dp[i-1][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]%=2;
			A[i][j] ^= dp[i][j];
			cout<<A[i][j];
		}
		cout<<endl;
	}
}
