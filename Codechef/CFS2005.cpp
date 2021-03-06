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
const int MOD = 998244353,MAX = 2e5+5;
const ll INF = 1e18+5;

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
struct PnC
{
	int n;
	vl F,I;
	void init(int n)
	{
		F.resize(n+1);
		I.resize(n+1);
		F[0]=I[0]=1;
		for(int i=1;i<=n;i++)
		{
			F[i]=(F[i-1]*i)%MOD;
			I[i]=powN(F[i],MOD-2);
		}
	}
	ll nCr(int n,int r)
	{
		if(r>n) return 0;
		return (((F[n]*I[r])%MOD)*I[n-r])%MOD;
	}
};

int main()
{
	fastio
	PnC P;
	P.init(MAX);
	test()
	{
		int n,m;
		cin>>n>>m;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;

		ll ans = 0;
		ans += P.nCr(n+m,n);
		ans -= (P.nCr(x1+y1,x1)*P.nCr(n-x1+m-y1,n-x1))%MOD;
		ans%=MOD;
		ans -= (P.nCr(x2+y2,x2)*P.nCr(n-x2+m-y2,n-x2))%MOD;
		ans%=MOD;
		ans += (((P.nCr(x1+y1,x1)*P.nCr(x2-x1+y2-y1,x2-x1))%MOD)*P.nCr(n-x2+m-y2,n-x2))%MOD;
		ans%=MOD;
		ans+=MOD;
		ans%=MOD;

		cout<<ans<<endl; 

	}

}	