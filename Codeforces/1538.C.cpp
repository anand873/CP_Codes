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
const int MOD = 1e9+7,MAX = 5e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n,l,r;
		cin>>n>>l>>r;
		vi A(n);
		take(A,0,n);
		sort(all(A));
		ll ans = 0;
		for(int i=0;i<n-1;i++)
		{
			int low = i+1,high = n-1;
			int lowlim = l - A[i];
			int highlim = r - A[i];
			
			int ll = -1, rr = -1;

			while(low<=high)
			{
				int mid = low+(high-low)/2;
				if(A[mid]<lowlim)
				{
					low = mid+1;
				}
				else
				{
					ll = mid;
					high = mid-1;
				}
			}

			low = i+1,high = n-1;

			while(low<=high)
			{
				int mid = low+(high-low)/2;
				if(A[mid]>highlim)
				{
					high = mid-1;
				}
				else
				{
					rr = mid;
					low = mid+1;
				}
			}
			// cout<<A[i]<<" "<<ll<<" "<<rr<<endl;
			if(ll == -1 || rr == -1) ans += 0;
			else
			{
				ans += rr - ll + 1;
			}

		}
		cout<<ans<<endl;
	}
}	