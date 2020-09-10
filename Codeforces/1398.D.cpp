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
	int r,g,b;
	cin>>r>>g>>b;
	vi R(r),G(g),B(b);
	take(R,0,r);
	take(G,0,g);
	take(B,0,b);

	sort(all(R));
	sort(all(G));
	sort(all(B));
	reverse(all(R));
	reverse(all(G));
	reverse(all(B));

	ll dp[r+1][g+1][b+1];

	for(int i=0;i<=r;i++)
	{
		for(int j=0;j<=g;j++)
		{
			for(int k=0;k<=b;k++)
			{
				dp[i][j][k]=0;
			}
		}
	}
	dp[0][0][0] = 0;

	for(int i=0;i<=r;i++)
	{
		for(int j=0;j<=g;j++)
		{
			for(int k=0;k<=b;k++)
			{
				if(i<r&&j<g)
				{
					dp[i+1][j+1][k] = max(dp[i+1][j+1][k],dp[i][j][k]+R[i]*G[j]);
				}
				if(i<r&&k<b)
				{
					dp[i+1][j][k+1] = max(dp[i+1][j][k+1],dp[i][j][k]+R[i]*B[k]);
				}
				if(j<g&&k<b)
				{
					dp[i][j+1][k+1] = max(dp[i][j+1][k+1],dp[i][j][k]+G[j]*B[k]);
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=r;i++)
	{
		for(int j=0;j<=g;j++)
		{
			for(int k=0;k<=b;k++) ans = max(ans,dp[i][j][k]);
		}
	}
	cout<<ans<<endl;
}	