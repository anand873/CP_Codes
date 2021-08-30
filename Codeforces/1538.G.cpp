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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

ll x,y,a,b;

ll find(ll mid)
{
	if(x>=a*mid && y>=b*mid)
	{
		ll leftx = x-a*mid;
		ll lefty = y-b*mid;
		// if(mid==2) cout<<leftx<<" "<<b<<" "<<lefty<<" "<<a<<endl;
		return mid + min(leftx/b,lefty/a);
	}
	return -1;
}

int main()
{
	test()
	{
		cin>>x>>y>>a>>b;
		ll low = 0, high = min(x/a,y/b);
		ll ans = 0;
		while(low<=high)
		{
			ll mid = low + (high-low)/2;

			ll x1 = find(mid);
			ll x2 = find(mid+1);
			// cout<<mid<<" "<<x1<<" "<<mid+1<<" "<<x2<<endl;
			if(x2==-1)
			{
				ans = max(ans,x1);
				high = mid-1;
			}
			else if(x1<=x2)
			{
				ans = max(ans,x2);
				low = mid+1;
			}
			else 
			{
				ans = max(ans,x1);
				high = mid-1;
			}
		}
		cout<<ans<<endl;
	}
}	