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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n,k;
		cin>>n>>k;
		vi C(n+1);
		take(C,1,n);
		vvi dp(n+1,vi(105,n));
		dp[n][C[n]]=n+1;
		for(int i=n-1;i>0;i--)
		{
			for(int j=1;j<=100;j++) dp[i][j] = i;
			dp[i][C[i]] = dp[i+1][C[i]];
		}

		int ans = MOD;
		for(int i=1;i<=100;i++)
		{
			int step = 0;
			int curr = dp[1][i];
			while(curr<=n)
			{
				step++;
				if(curr+k>n) break;
				else curr = dp[curr+k][i];
			}
			ans = min(ans,step);
		}
		cout<<ans<<endl;
	}
}	