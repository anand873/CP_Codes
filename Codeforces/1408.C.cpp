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
		int n;
		ll l;
		cin>>n>>l;

		vl A(n+2);
		take(A,1,n);
		
		A[0]=0;
		A[n+1]=l;
		
		vector<double> dpf(n+2),dpb(n+2);
		dpb[1] = (A[1]-A[0]);
		
		for(int i=2;i<=n+1;i++)
		{
			dpb[i] = dpb[i-1] + (A[i]-A[i-1])*1.0/i;
		}
		dpf[n] = (A[n+1]-A[n]);
		for(int i=n-1;i>=0;i--)
		{
			dpf[i] = dpf[i+1] + (A[i+1]-A[i])*1.0/(n+1-i);
		}
		double ans=-1;
		for(int i=1;i<=n+1;i++)
		{
			if(dpb[i-1]<=dpf[i-1]&&dpb[i]>=dpf[i])
			{
				double dis = (A[i]-A[i-1]);

				double x = (dpf[i]-dpb[i-1] + dis/(n+2-i))*i*(n+2-i)/(n+2);

				ans = dpb[i-1] + x/i;
				break;
			}
		}
		cout<<setprecision(16)<<ans/1.0<<endl;
		


	}
}	