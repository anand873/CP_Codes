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
const int MOD =998244353,MAX = 1e6+5;
const ll INF = 1e18+5;

vvl dp;

ll fun(string &x,string &y,int lenx, int leny)
{
	if(lenx==0&&leny==1) return dp[0][1] = 1;
	if(leny==0&&lenx==1) return dp[1][0] = 1; 
	if(dp[lenx][leny]!=-1) return dp[lenx][leny];
	int i = lenx;
	ll ans = 0;
	if(x[lenx-1]!=y[leny-1]) ans += fun(x,y,lenx,leny-1);
	while(i>1)
	{
		if(x[i-1]!=y[leny-1] && y[leny-1]!=x[i-2]) ans += fun(x,y,i-1,leny-1);
		i--;
		if(x[i-1]==x[i-2]) break;
	}
	cout<<lenx<<" "<<leny<<" "<<ans<<endl;
	return dp[lenx][leny] = ans;
}

int main()
{
	string x,y;
	cin>>x>>y;
	int n = x.length();
	int m = y.length();
	dp.resize(n+1,vl(m+1));
	// for(int i=0;i<=m;i++) dp[i].resize(m+1,-1);

	ll ans = fun(x,y,n,m);
	cout<<ans<<endl;

}	