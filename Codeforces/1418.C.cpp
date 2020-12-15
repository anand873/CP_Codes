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
	test()
	{
		int n;
		cin>>n;
		vi A(n+1);
		take(A,1,n);
		vvi dp(n+1,vi(2,MOD));
		dp[0][0] = MOD;
		dp[0][1] = 0;
		dp[1][0] = A[1];
		dp[1][1] = MOD;
		for(int i=2;i<=n;i++)
		{
			dp[i][0] = min(dp[i-1][1]+A[i],dp[i-2][1]+A[i-1]+A[i]);
			dp[i][1] = min(dp[i-1][0],dp[i-2][0]);
		}
		// for(int i=1;i<=n;i++)
		// {
		// 	cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		// }
		cout<<min(dp[n][1],dp[n][0])<<endl;
	}
}	