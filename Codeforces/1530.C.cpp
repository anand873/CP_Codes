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

int main()
{
	test()
	{
		int n;
		cin>>n;
		vi A(n+1),B(n+1);
		take(A,1,n);
		take(B,1,n);
		sort(all(A));
		sort(all(B));

		ll suma = 0,sumb = 0;
		for(int i=1;i<=n;i++)
		{
			suma+=A[i];
			sumb+=B[i];
		}
		for(int i=1;i<=n;i++)
		{
			A[i]+=A[i-1];
			B[i]+=B[i-1];
		}
		int low = n, high = 4*n;
		int ans = 4*n;
		while(low <= high)
		{
			int mid = low + (high - low)/2;
			int ex = mid - n;
			ll nowsuma = suma + ex*100;
			ll nowsumb = sumb;

			int top = mid/4;
			nowsuma -= A[top];
			nowsumb -= B[max(0,top-ex)];
			if(nowsumb <= nowsuma)
			{
				ans = mid;
				high = mid-1;
			}
			else low = mid+1;
		}
		cout<<ans - n<<endl;
	}
}	