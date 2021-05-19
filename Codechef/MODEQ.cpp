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
int MOD = 1e9+7,MAX = 5e5+5;
const ll INF = 1e18+5;

int main()
{
	fastio
	vvi Divisors(MAX);
	for(int i=1;i<=MAX;i++)
	{
		for(int j=i;j<MAX;j+=i)
		{
			Divisors[j].push_back(i);
		}
	}
	for(int i=1;i<1e6+5;i++)
	{
		Divisors[0].push_back(i);
	}

	test()
	{
		int n,m;
		cin>>n>>m;

		ll ans = 0;
		for(int b=2;b<=n;b++)
		{
			int x = m%b;
			int mx = m - x;

			ll low = 0, high = (ll)(Divisors[mx].size())-1;
			ll val = -1;
			while(low<=high)
			{
				ll mid = low+(high-low)/2;
				if(Divisors[mx][mid]<b)
				{
					val = mid;
					low = mid+1;
				}
				else
				{
					high = mid-1;
				}
			}
			// cout<<mx<<" "<<b<<" "<<val<<endl;
			ans += val+1;
		}
		cout<<ans<<'\n';
	}
}