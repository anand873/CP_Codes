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
const int MOD = 998244353,MAX = 1e6+5;
const ll INF = 1e18+5;

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vl INV(n+1);
	for(int i=1;i<=n;i++)
	{
		INV[i] = powN(i,MOD-2);
	}
	vvi D(n,vi(m));
	for(int i=0;i<n;i++)
	{
		take(D[i],0,m);
	}
	ll ans=0;
	for(int i=0;i<m;i++)
	{
		vi DD(n);
		for(int j=0;j<n;j++) DD[j] = D[j][i];

		sort(all(DD));
		ll prob = 1;
		for(int j=0;j<n;j++)
		{
			prob = (prob*(DD[j]-j-1)%MOD)*INV[j+1]%MOD;
		}
		// cout<<prob<<endl;
		ans += ((1-prob)%MOD+MOD)%MOD;
		ans%=MOD;
	}
	cout<<ans<<endl;

}	