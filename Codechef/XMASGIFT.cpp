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

ll lcm(int n, int m)
{
	return (ll)(n/__gcd(n,m))*m;
}

ll f(int n,int a,int d)
{
	ll ans = 0;
	for(int i=0;i<5;i++)
	{
		ans += n/(a+i*d);
	}
	// cout<<ans<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			ans -= n/(lcm(a+i*d,a+j*d));
		}
	}
	// cout<<ans<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			for(int k=j+1;k<5;k++)
			{
				ans += n/(lcm(a+i*d,lcm(a+j*d,a+k*d)));
			}
		}
	}
	// cout<<ans<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			for(int k=j+1;k<5;k++)
			{
				for(int l=k+1;l<5;l++)
				{
					ans -= n/lcm(lcm(a+i*d,a+l*d),lcm(a+j*d,a+k*d));
				}
			}
		}
	}
	// cout<<ans<<endl;
	ans += n/lcm(a,lcm(a+d,lcm(a+2*d,lcm(a+3*d,a+4*d))));
	return n-ans;
}

int main()
{
	test()
	{
		int n,m,a,d;
		cin>>n>>m>>a>>d;
		cout<<f(m,a,d) - f(n-1,a,d)<<endl;
	}
	
}	