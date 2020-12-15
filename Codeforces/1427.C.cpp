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
	int r,n;
	cin>>r>>n;
	vvi T(n+1,vi(3));
	T[0] = {0,1,1};
	for(int i=1;i<=n;i++)
	{
		take(T[i],0,3);
	}
	vi dp(n+1,-MOD);
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=min(n,i+4*r+5);j++)
		{
			if(abs(T[j][1]-T[i][1])+abs(T[j][2]-T[i][2])<=T[j][0]-T[i][0])
			{
				dp[j] = max(dp[j],dp[i]+1);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
}	