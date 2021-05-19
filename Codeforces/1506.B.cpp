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
	test()
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		reverse(all(s));
		while(s.back()!='*') s.pop_back();
		reverse(all(s));
		while(s.back()!='*') s.pop_back();
		int sz = s.length();
		vvi dp(sz,vi(2,MOD));
		dp[0][1] = 1;
		for(int i=1;i<sz;i++)
		{
			if(s[i]=='.')
			{
				dp[i][0] = min(dp[i-1][0],dp[i-1][1]);
				continue;
			}

			for(int j=max(0,i-k);j<i;j++)
			{
				dp[i][1] = min(dp[j][1]+1,dp[i][1]);
			}
		}
		cout<<dp[sz-1][1]<<endl;
	}
}	