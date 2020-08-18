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
	test()
	{
		int n,k,z;
		cin>>n>>k>>z;
		vl A(n);
		take(A,0,n);
		ll ans = 0;
		
		for(int times=0;times<=z;times++)
		{
			ll here = 0;
			ll sum = 0;
			for(int i=0;i<=k-2*times;i++)
			{
				if(i!=0) here = max(here,A[i]+A[i-1]);
				sum+=A[i];
			}
			ans = max(ans,sum+times*here);

			if(times!=0)
			{
				sum = 0;
				for(int i=0;i<=k-2*times+1;i++)
				{
					sum+=A[i];
				}
				if(k-2*times>=0)
					ans = max(ans,sum+times*A[k-2*times]+(times-1)*A[k-2*times+1]);
			}
		}
		cout<<ans<<endl;
	}	
}	