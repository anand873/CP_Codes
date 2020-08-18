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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		vl A(n);
		take(A,0,n);
		if(n==1)
		{
			cout<<"YES"<<endl;
			continue;
		}
		vl Ou(n),Of(n);
		Ou[0] = A[0];
		for(int i=1;i<n;i++)
		{
			Ou[i]=A[i]|Ou[i-1];
		}
		Of[n-1] = A[n-1];
		for(int i=n-2;i>=0;i--)
		{
			Of[i] = Of[i+1]|A[i];
		}
		bool can = true;
		if(((A[0]|Of[1])==Of[1])||((A[n-1]|Ou[n-2])==Ou[n-2])) can=false;
		for(int i=1;i<n-1;i++)
		{
			ll rest = Ou[i-1]|Of[i+1];
			if((rest|A[i])==rest) can=false;
		}
		if(can) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}	