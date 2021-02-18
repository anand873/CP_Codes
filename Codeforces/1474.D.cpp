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

int main()
{
	test()
	{
		int n;
		cin>>n;
		vi A(n+1);
		take(A,1,n);
		vvl dp(n+1,vl(2,INF));
		if(n==2)
		{
			if(A[0]!=A[1]) cout<<"NO\n";
			else cout<<"YES\n";
			continue;
		}
		else if(n==3)
		{
			sort(all(A));
			if(A[0]+A[1]==A[2]) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		else
		{
			dp[n][0] = A[n];
			dp[n][1] = INF;
			dp[n-1][0] = (A[n-1]-A[n]>=0)?A[n-1]-A[n]:INF;
			dp[n-1][1] = (A[n]-A[n-1]>=0)?A[n]-A[n-1]:INF;

			for(int i=n-2;i>1;i--)
			{
				if(dp[i+1][0]!=INF)
				{
					if(A[i]-dp[i+1][0]>=0) dp[i][0] = A[i]-dp[i+1][0];
				}
				if(dp[i+1][1]!=INF)
				{
					if(A[i]-dp[i+1][1]>=0) dp[i][1] = A[i]-dp[i+1][1];
				}
				if(dp[i+2][0]!=INF)
				{
					if(dp[i+2][0] + A[i] <= A[i+1])
					{
						dp[i][1] = A[i+1] - (dp[i+2][0] + A[i]);
					}
				}
			}
			if(dp[2][0]==A[1]||dp[2][1]==A[1]||dp[3][0]+A[2]==A[1]) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}	