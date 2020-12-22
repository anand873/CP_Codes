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
	int r,c,k;
	cin>>r>>c>>k;
	vvl M(r,vl(c));
	for(int i=0;i<k;i++)
	{
		ll ri,ci,vi;
		cin>>ri>>ci>>vi;
		M[ri-1][ci-1] = vi;
	}
	ll dp[r][c][4];
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			for(int h=0;h<4;h++) dp[i][j][h] = 0;
		}
	}

	dp[0][0][1] = M[0][0];
	// cout<<"HERE"<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i+1<r)
			{
				if(M[i+1][j]!=0)
				{
					dp[i+1][j][0] = max(dp[i+1][j][0],max({dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]}));
					dp[i+1][j][1] = max(dp[i+1][j][1],M[i+1][j]+max({dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]}));
				}
				else
				{
					dp[i+1][j][0] = max({dp[i+1][j][0],dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]});
				}
			}
			if(j+1<c)
			{
				if(M[i][j+1]!=0)
				{
					for(int last = 0;last<3;last++)
					{
						dp[i][j+1][last] = max(dp[i][j][last],dp[i][j+1][last]);
						dp[i][j+1][last+1] = max(dp[i][j+1][last+1],dp[i][j][last]+M[i][j+1]);
					}
					dp[i][j+1][3] = max(dp[i][j][3],dp[i][j+1][3]);
				}
				else
				{
					for(int last=0;last<=3;last++)
					{
						dp[i][j+1][last] = max(dp[i][j+1][last],dp[i][j][last]);
					}
				}
			}
		}
	}
	cout<<max({dp[r-1][c-1][0],dp[r-1][c-1][1],dp[r-1][c-1][2],dp[r-1][c-1][3]})<<endl;
}	