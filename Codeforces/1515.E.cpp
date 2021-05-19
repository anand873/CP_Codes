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
int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}

ll nC3(ll n)
{
	return ((2ll*n*(n-1)%MOD)*(n-2)%MOD)*powN(6,MOD-2)%MOD;
}

int main()
{
	int n,m;
	cin>>n>>m;
	MOD = m;
	vvl dp(n+1,vl(n+1,0));
	dp[1][1] = 1;
	dp[2][2] = 2;
	dp[0][0] = 1;
	for(int i=2;i<n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i+1][j+1] = (((dp[i-1][j] + dp[i][j])%MOD)* (j+1) % MOD - ((j-2>=0)?dp[i-2][j-2]*nC3(j+1)%MOD:0ll) )%MOD;
			if(dp[i+1][j+1]<0) dp[i+1][j+1]+=MOD;
		}
	}
	for(int i=1;i<=n;i++)
	{
		prinv(dp[i]);
	}
	ll ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(dp[n][i]!=-1) ans = (ans + dp[n][i])%MOD;
	}
	cout<<ans<<endl;
}	