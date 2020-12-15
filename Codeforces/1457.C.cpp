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
		int n,p,k;
		cin>>n>>p>>k;
		string s;
		cin>>s;
		reverse(all(s));
		s.push_back('#');
		reverse(all(s));
		int x,y;
		cin>>x>>y;
		vi dp(n+1);
		dp[n] = 1- (s[n]-'0');
		for(int i=n-1;i>0;i--)
		{
			if(i+k>n) dp[i] = 1 - (s[i]-'0');
			else dp[i] = dp[i+k] + 1 - (s[i]-'0');
		}
		ll ans = INF;
		for(int i=p;i<=n;i++)
		{
			ans = min(ans, (ll)(i-p)*y + (ll)dp[i]*x);
			// cout<<ans<<endl;
		}
		cout<<ans<<endl;

	}
}	