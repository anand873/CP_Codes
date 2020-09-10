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
	ll z = powN(a,p/2);
	z*=z;
	z%=MOD;
	if(p%2) z*=a;
	z%=MOD;
	return z;
}

int main()
{
	fastio
	
	int n,m;
	cin>>n>>m;
	string a,b;
	cin>>a>>b;
	vector<int> B(m+1);
	for(int i=0;i<m;i++)
	{
		B[i+1] = B[i] + (b[i]-'0');
	}

	ll ans = 0; 
	for(int i=max(0,n-m)+1;i<=n;i++)
	{
		ans += (a[i-1]-'0')*(B[m-n+i]*(powN(2ll,n-i)))%MOD;
		ans%=MOD;
	}
	cout<<ans<<endl;
}
