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
	fastio
	int n;
	cin>>n;
	vi S(n);
	take(S,0,n);

	cin>>n;
	vi R(n);
	take(R,0,n);

	int maxM;
	cin>>maxM;

	vpii X(n);
	for(int i=0;i<n;i++)
	{
		X[i] = {R[i],S[i]};
	}
	sort(all(X));

	ll ans = 0;
	multiset<int> V;
	ll sum = 0;
	for(int i=n-1;i>=0;i--)
	{
		V.insert(X[i].second);
		sum+=X[i].second;

		if(V.size()>maxM)
		{
			sum -= *(V.begin());
			V.erase(V.begin());
		}
		ans = max(ans,sum*X[i].first);
	}
	cout<<ans<<endl;


}	