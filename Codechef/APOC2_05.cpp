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
	int n;
	ll c;
	cin>>n>>c;
	vpll X(n);
	for(int i=0;i<n;i++)
	{
		cin>>X[i].first>>X[i].second;
	}
	vl Diff(n);
	for(int i=0;i<n;i++)
	{
		Diff[i] = X[i].second;
	}
	vl Left(n+1);
	ll curr = c;
	Left[0] = 0;
	for(int i=1;i<=n;i++)
	{
		Left[i] = Left[i-1] + X[n-i].second - (curr - X[n-i].first); 
		curr = X[n-i].first;
	}
	// prinv(Left);
	vl Maxa(n+1);
	Maxa[1] = Diff[0];
	for(int i=1;i<n;i++)
	{
		Diff[i] += Diff[i-1];
		Maxa[i+1] = max(Maxa[i],Diff[i]-X[i].first);
	}
	// prinv(Maxa);
	ll ans = Maxa[n];
	for(int i=1;i<n;i++)
	{
		ll temp = Left[i] + Maxa[n-i] - (c-X[n-i].first);
		ans = max(ans,temp);
	}
	ans = max(ans,Left[n]);
	cout<<ans<<endl;	
}	