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
const int MOD = 1e9+7,MAX = 1e6+5;
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
	string s;
	cin>>s;
	reverse(all(s));
	ll ans = 0;
	ll n = s.length();
	ll sum = 0;
	for(ll i=0;i<n;i++)
	{
		ll temp = (((n-1-i)*(n-i-2)/2 + n-1-i)*(s[i]-'0'))%MOD;
		// cout<<temp<<endl;
		ans += (temp*powN(10,i))%MOD;
		ans%=MOD;
		sum += (i*powN(10,i-1))%MOD;
		sum%=MOD;
		ans += (sum*(s[i]-'0'))%MOD;
		ans%=MOD;
	}
	cout<<ans<<endl;
}	