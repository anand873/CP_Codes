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

ll powN(ll a,ll p,ll m)
{
	if(p==0) return 1;
	ll z=powN(a,p/2,m);
	z=(z*z)%m;
	if(p%2) z=(z*a)%m;
	return z;
}

int phi(int n)
{
	int ans = n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n/=i;
			}
			ans -= ans/i;
		}
	}
	if(n>1) ans -= ans/n;
	return ans;
}

int main()
{
	test()
	{
		int n,s,k;
		cin>>n>>s>>k;
		int diff = n-s;
		int gcd = __gcd(n,k);
		if(gcd>1&&diff%gcd)
		{
			cout<<-1<<endl;
		}
		else
		{
			n/=gcd;
			diff/=gcd;
			k/=gcd;
			// cout<<n<<endl;
			// cout<<phi(n)<<endl;
			cout<<(powN(k,phi(n)-1,n)*diff)%n<<endl;
		}
	}
}	