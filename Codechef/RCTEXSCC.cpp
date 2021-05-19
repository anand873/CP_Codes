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
const int MOD = 998244357,MAX = 1e6+5;
const ll INF = 1e18+5;

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}

ll mod_div(int num, int deninv)
{
	return (num*deninv)%MOD;
}

ll mod_add(int num, int num2)
{
	return (num+num2)%MOD;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if(k==1)
	{
		cout<<1<<"\n";
		return 0;
	}
	int kk = powN(k,MOD-2);
	if(m==2)
	{
		vvl dp(n+1,vl(2));
		for(int i=1;i<=n;i++)
		{
			dp[i][0] = ((mod_add(dp[i-1][0],dp[i-1][1])*mod_div(1,kk))%MOD + mod_div(mod_div(2*k-3,k),k))%MOD;
			
		}
	}
}	