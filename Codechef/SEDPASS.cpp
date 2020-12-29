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

void testcase()
{
	string s;
	cin>>s;
	int n = s.length();
	vi H(26);
	for(auto c:s)
	{
		if(c=='?') continue;
		H[c-'a']++;
	}
	for(int i=0;i<26;i++) H[i]%=2;

	int big = 0;
	for(int i=0;i<26;i++) big += H[i]*(1<<i);

	vi dp(n+1);
	int num = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='?') num^=(1<<26);
		else num^=(1<<(s[i]-'a'));

		dp[i+1] = num;
	}
	ll ans = 0;
	map<int,int> M;
	for(int i=n;i>=1;i--)
	{
		M[dp[i]]++;
		int val = dp[i-1];
		ans += M[val^big];
		for(int i=0;i<26;i++)
		{
			ans += M[val^((1<<i) + (1<<26))^big];
		}
	}
	cout<<ans<<endl;


}

int main()
{
	test()
	{
		testcase();
	}
}	