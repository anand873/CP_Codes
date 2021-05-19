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
		int n,m,l;
		cin>>n>>m>>l;
		string s;
		cin>>s;
		string T;
		cin>>T;
		vvi V(n);
		vi F(m),S(m);
		take(F,0,m);
		take(S,0,m);
		for(int i=0;i<m;i++)
		{
			int u = F[i];
			int v = S[i];
			V[u-1].push_back(v-1);
			V[v-1].push_back(u-1);
		}
		vector<map<string,ll>> dp(n);
		for(int i=0;i<n;i++)
		{
			if(T[i]==s[0]) dp[i][s.substr(0,1)]++;
		}
		for(int i=1;i<l;i++)
		{
			string curr = s.substr(0,i+1);
			string prev = s.substr(0,i);
			for(int u=0;u<n;u++)
			{
				if(T[u]!=s[i]) continue;
				for(auto v:V[u])
				{
					dp[u][curr] += dp[v][prev];
					dp[u][curr] %= MOD;
				}
			}
		}
		ll ans = 0;
		for(int i=0;i<n;i++)
		{
			ans += dp[i][s];
			ans %= MOD;
		}
		bool allsame = true;
		for(int i=0;i<l;i++) if(s[i]!=s[0]) allsame = false;

		if(allsame)
		{
			for(int i=0;i<m;i++)
			{
				if(T[F[i]-1] == T[S[i]-1] && T[F[i]-1]==s[0]) ans--;
			}
			ans%=MOD;
			if(ans<0) ans+=MOD;
		}
		cout<<ans<<endl;
	}
}	