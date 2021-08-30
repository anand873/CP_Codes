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
const int MOD = 1e9 + 7,MAX = 1e6 + 5;
const ll INF = 1e18 + 5;

int f(int x, int y,int k)
{
	vi X,Y;
	for(int i=0;i<30;i++)
	{
		X.push_back(x%k);
		x/=k;

		Y.push_back(y%k);
		y/=k;
	}
	ll ans = 0;
	ll curr = 1;
	for(int i=0;i<30;i++)
	{
		int bit = (X[i] + Y[i]) % k;
		ans += curr*bit;

		curr *= k;
		if(curr > 1000000000) break;
	}
	return ans;
}

int main()
{
	test()
	{
		int n,k;
		cin>>n>>k;

		cout<<0<<endl;
		int x;
		cin>>x;
		if(x==1)
		{
			continue;
		}
		int curr = 0;
		bool can = false;
		for(int i=1;i<n-1;i++)
		{
			int top = f(curr,i,k);
			cout<<top<<endl;
			cin>>x;
			if(x==1)
			{
				can  = true;
				break;
			}
			curr = f(curr,top,k);
		}
		if(!can)
		{
			
		}

	}
}	