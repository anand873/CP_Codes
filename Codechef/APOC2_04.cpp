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

ll make_same(int n, int len)
{
	ll base = n;
	for(int i=1;i<len;i++)
	{
		base = base*10 + n;
	}
	return base;
}

int main()
{
	test()
	{
		ll n;
		cin>>n;
		// n = 1-t;
		string s = to_string(n);
		int len = s.length();
		ll upto = 0;
		for(int i=0;i<len;i++)
		{
			ll check = upto*pow(10,len-i);
			for(int j=9;j>=0;j--)
			{
				if(check+make_same(j,len-i)<=n)
				{
					upto = upto*10 + j;
					break;
				}
			}
		}
		cout<<upto<<endl;

	}	
}	