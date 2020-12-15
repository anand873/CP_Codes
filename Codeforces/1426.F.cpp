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
	int n;
	string s;
	cin>>n>>s;
	vl dp(n);
	dp[0]=0;
	ll a_bef=0;
	ll t_s = 1;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='b') dp[i+1] = (dp[i]+a_bef)%MOD;
		if(s[i]=='?')
		{
			dp[i+1] = (dp[i]*3 + a_bef)%MOD;
			a_bef = (a_bef*3+t_s)%MOD;
			t_s = (t_s*3)%MOD;
		}
		if(s[i]=='a') {a_bef += t_s;a_bef%=MOD;dp[i+1]=dp[i];}
		if(s[i]=='c') dp[i+1] = dp[i];
	}
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		if(s[i]=='c') ans = (ans + dp[i])%MOD;
		if(s[i]=='?') ans = ((ans*3)%MOD + dp[i])%MOD; 
	}
	cout<<ans<<endl;
}	