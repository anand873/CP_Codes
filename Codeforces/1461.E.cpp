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

int main()
{
	fastio
	ll k,l,r,y,t;
	ll x;
	cin>>k>>l>>r>>t>>x>>y;

	if(y>x)
	{
		bool can=true;
		while(t>0)
		{
			if(k+y<=r)
			{
				ll numm = min(t,(r - k - x)/(y-x));
				k += (y-x)*numm;
				t -= numm;
			}

			ll numd = min(t,(k - (r-y) + (x-1))/x);
			if(k - numd*x < l)
			{
				can=false;
				break;
			}
			else
			{
				if(t==numd) break;
				t -= numd;
				k -= numd*x;
			}
		}
		if(can) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	else if(x==y)
	{
		if(k+y<=r) cout<<"Yes"<<endl;
		else if(k - x < l) cout<<"No";
		else cout<<"Yes"<<endl;
	}
	else
	{
		if(k+y<=r)
		{
			if((k-l)/(x-y)>=t) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else
		{
			if(k-x<l) cout<<"No"<<endl;
			else
			{
				t--;
				k -= x;
				// cout<<k - t*(x-y)<<endl;
				if((k-l)/(x-y)>=t) cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
		}
	}

}	