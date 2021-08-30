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
#define test() int q;cin>>q;while(q--)
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9,MAX = 3e5+5;
const ll INF = 1e18+5;

int main()
{
	fastio
	test()
	{
		int n,k;
		cin>>n>>k;
		vi A(n+1);
		take(A,1,n);
		vi D(n+1);
		for(int i=1;i<=n;i++)
		{
			if(i >= A[i])
			{
				D[i] = i - A[i];
			}
			else D[i] = -1;
		}

		vvi dp(n+1, vi(n+1,-1));

		dp[0][0] = 0;
		for(int i=1;i<=n;i++)
		{
			dp[i][0] = 0;
			if(D[i]==-1)
			{
				for(int j=1;j<=n;j++)
				{
					dp[i][j] = dp[i-1][j];
				}
			}
			else
			{
				// cout<<"D[i]!=-1"<<endl;
				for(int j=0;j<n;j++)
				{
					int last = dp[i-1][j];
					if(last==-1)
					{
						dp[i][j+1] = -1;
						continue;
					}
					int gone = last - A[last];

					int bacha = i - 1 - last;
					if(D[i] - gone <= bacha && D[i] >= gone)
					{
						dp[i][j+1] = i;
					}
					else dp[i][j+1] = dp[i-1][j+1];
				}
				cout<<i<<"-> ";
				prinv(dp[i]);
			}
		}
		int ans = MOD;
		for(int i=k;i<=n;i++)
		{
			if(dp[n][i]!=-1)
			{
				ans = min(ans,dp[n][i] - i);
			}
		}
		if(ans==MOD) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}	