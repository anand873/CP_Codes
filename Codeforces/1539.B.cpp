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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

int main()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	vl dp(n+1);
	dp[0] = 0;
	for(int i=1;i<=n;i++)
	{
		dp[i] = dp[i-1] + (s[i-1] -'a' + 1); 
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<dp[r] - dp[l-1]<<endl;
	}
}	