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
	int n,k;
	cin>>n>>k;
	ll nC2 = ((ll)n*(n-1)/2)%MOD;
	ll n_2C2 = ((ll)(n-2)*(n-3)/2)%MOD;
	ll nC3 = (((ll)n*(n-1)%MOD)*(n-2)%MOD)*166666668%MOD;
	// cout<<nC2<<" "<<n_2C2<<" "<<nC3<<endl;
	ll seclast = 1;
	ll last = nC2;
	cout<<last<<" ";
	for(int i=2;i<=k;i++)
	{
		ll temp = (seclast*((1 + 2*nC3%MOD + ((nC2*n_2C2)%MOD)*500000004%MOD)%MOD))%MOD;
		seclast = last;
		last = temp;
		cout<<last<<" ";
	}
	cout<<endl;

}	