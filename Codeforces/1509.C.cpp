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
const int MOD = 998244353,MAX = 1e6+5;
const ll INF = 1e18+5;

int main()
{
	fastio
	int n;
	cin>>n;
	vi S(n);
	take(S,0,n);
	sort(all(S));
	vi X;
	map<int,int> M;
	M[S[0]]++;
	X.push_back(S[0]);
	for(int i=1;i<n;i++)
	{
		M[S[i]]++;
		if(X.back()!=S[i])
		{
			X.push_back(S[i]);
		}
	}
	sort(all(X));
	vi SS;
	int m = X.size();
	for(int i=0;i<(m+1)/2;i++)
	{
		SS.push_back(X[i]);
		if(i!=m-1-i) SS.push_back(X[m-1-i]);
	}
	reverse(all(SS));
	prinv(SS);
	ll ans=0;
	int mix=MOD,man=0;
	for(int i=0;i<m;i++)
	{
		mix = min(mix,SS[i]);
		man = max(man,SS[i]);
		ans += (ll)(man - mix)*M[SS[i]];
	}
	cout<<ans<<'\n';

	
}	