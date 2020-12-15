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

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
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
	fastio
	int n,m;
	cin>>n>>m;
	vi D(n);
	take(D,0,n);
	sort(all(D));
	vl PS(n+1);;
	for(int i=0;i<n;i++) PS[i+1] = (PS[i] + D[i])%MOD;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;

		// Greater than b is big;
		ll small = lower_bound(all(D),b) - D.begin();
		ll big = n - small;
		if(big<a) {cout<<0<<endl;continue;}
		// Big does damage with probability 	(big-a)/big;
		// small does damage with probability 	(big+1-a)/(big+1);

		ll ans = 0;
		ll invB = powN(big,MOD-2);
		ll invB1 = powN(big+1,MOD-2);
		ans += (((PS[small]*(big+1-a))%MOD)*invB1)%MOD;
		ans += ((((PS[n]-PS[small])*(big-a))%MOD)*invB)%MOD;
		cout<<(ans%MOD + MOD)%MOD<<endl;
	}
	
}	