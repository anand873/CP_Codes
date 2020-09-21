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
		int n;
		cin>>n;
		vi A(n);
		take(A,0,n);
		sort(all(A));
		vi H(n+1);
		for(int i=0;i<n;i++) H[A[i]]++;

		int maxcnt = 0;
		for(auto h:H) maxcnt = max(maxcnt,h);
		int e = 0;
		for(auto h:H)
		{
			if(h==maxcnt) e++;
		}
		int low = 0,high = n-2;
		int ans=0;
		while(low<=high)
		{
			int mid = low + (high-low)/2;

			if((ll)(maxcnt-1)*(mid+1)+e>n)
			{
				high = mid-1;
			}
			else
			{
				ans = mid;
				low = mid + 1;
			}
		}
		cout<<ans<<endl;
	}
}	