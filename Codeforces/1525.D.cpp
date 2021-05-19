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
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	vi Empty,Full;

	for(int i=0;i<n;i++)
	{
		if(A[i]) Full.push_back(i);
		else Empty.push_back(i);
	}
	int sz = Full.size();

	int ans = MOD;
	// if(sz==0) {cout<<0<<endl;return 0;}
	vvi dp(n-sz+1,vi(sz+1,MOD));

	for(int i=0;i<=n-sz;i++) dp[i][0]=0;
	dp[0][0] = 0;	
	for(int i=1;i<=n-sz;i++)
	{
		for(int j=1;j<=sz;j++)
		{
			dp[i][j] = min({dp[i-1][j], dp[i-1][j-1]+abs(Full[j-1]-Empty[i-1])});
		}
	}
	cout<<dp[n-sz][sz]<<endl;
}	