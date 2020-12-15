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
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n,m;
		cin>>n>>m;
		vvl A(n,vl(m));

		for(int i=0;i<n;i++)
		{
			take(A[i],0,m);
		}
		ll ans = 0;
		
		for(int i=0;i<n/2;i++)
		{
			for(int j=0;j<m/2;j++)
			{
				vl X = {A[i][j],A[i][m-1-j],A[n-1-i][j],A[n-1-i][m-1-j]};
				sort(all(X));
				ans += (X[1]-X[0]) + (X[2]-X[1])*2  + (X[3]-X[2]);
			}
			if(m%2)
			{
				ans += abs(A[i][m/2]-A[n-1-i][m/2]);
			}
		}
		if(n%2)
		{
			for(int j=0;j<m/2;j++)
			{
				ans += abs(A[n/2][j]-A[n/2][m-1-j]);
			}
		}
		cout<<ans<<endl;
	}
}	