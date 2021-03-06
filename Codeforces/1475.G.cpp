//Author: Anand Raj doubleux
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
	vvi F(MAX);
	for(int i=1;i<MAX;i++)
	{
		for(int j=i;j<MAX;j+=i)
		{
			F[j].push_back(i);
		}
	}
	test()
	{
		int n;
		cin>>n;
		vi A(n+1);
		take(A,1,n);
		sort(1+all(A));
		vi M(MAX);
		vi dp(n+1);
		dp[1] = 1;
		for(int i = 1 ; i<=n ; i++)
		{
			dp[i] = 1;
			for(auto f:F[A[i]])
			{
				if(M[f]!=0)
				{
					dp[i] = max(dp[i],dp[M[f]]+1);
				}
			}
			M[A[i]] = max(M[A[i]],i);
		}
		int ans = 0;
		for(int i=1;i<=n;i++) ans = max(ans,dp[i]);
		cout<<n - ans<<endl;
	}
}	