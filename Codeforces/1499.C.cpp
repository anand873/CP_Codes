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
const int MOD = 1e9+7,MAX = 5e6+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		vi C(n+1);
		take(C,1,n);

		vi ME(n+1,MOD),MO(n+1,MOD);
		ME[0] = MOD;
		MO[0] = MOD;
		vl PS(n+1);
		for(int i=1;i<=n;i++)
		{
			PS[i] = PS[i-1] + C[i];
			if(i%2) {MO[i] = min(MO[i-1],C[i]);ME[i] = ME[i-1];}
			else {ME[i] = min(ME[i-1],C[i]);MO[i] = MO[i-1];}
		}
		// prinv(ME);
		// prinv(MO);
		ll ans = INF;
		for(int i=2;i<=n;i++)
		{
			ll temp = PS[i] + (ll)ME[i]*(n-(i/2)) + (ll)MO[i]*(n-(i+1)/2);
			ans = min(ans,temp);
		}
		cout<<ans<<endl;

	}
}	