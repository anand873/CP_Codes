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
const int MOD = 1e9+7,MAX = 2e5+5;
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
		if(r>n || r<0 || n<0) return 0;
		return (((F[n]*I[r])%MOD)*I[n-r])%MOD;
	}
};

int main()
{
	PnC P;
	P.init(MAX);

	test()
	{
		int n,l,r;
	
		cin>>n>>l>>r;

		ll ans = 0;
		ll bothgood = min(1-l, r - n);

		ans += ( ( bothgood * P.nCr(n,n/2) %MOD ) * 2) % MOD;
		ans %= MOD;

		for(int k=bothgood+1;;k++)
		{
			int i = max(1,l + k);
			int j = min(n,r - k);

			if(i > n || j  < 1) break;

			int onlyneg = min(n-i+1,n-j);
			int onlypos = min(j,i-1);

			// n/2 -> neg, (n+1)/2 -> pos

			int leftneg = max(0,n/2 - onlyneg);
			int leftpos = max(0,(n+1)/2 - onlypos);
			int leftmids = max(0,j-i+1);

			// cerr<<leftmids<<" "<<leftneg<<" "<<leftpos<<endl;

			if(leftneg + leftpos == leftmids) ans += P.nCr(leftmids,leftneg);
			ans %= MOD;

			// (n+1)/2 -> neg, n/2 -> pos
			// if(n%2==0) continue;
			leftneg = max(0,(n+1)/2 - onlyneg);
			leftpos = max(0,n/2 - onlypos);
			leftmids = max(0,j-i+1);

			// cerr<<leftmids<<" "<<leftneg<<" "<<leftpos<<endl;

			if(leftneg + leftpos == leftmids) ans += P.nCr(leftmids,leftneg);
			ans %= MOD;
		}
		if(n%2==0)
		{
			ans = ans * P.I[2] % MOD;
		}
		cout<<ans<<endl;
	}
}	