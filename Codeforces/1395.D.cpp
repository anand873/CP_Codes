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
#define what(x) cerr<<#x<<" = "<<x<<", "
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

vl A;
vl G,B;

ll ok(ll mid,ll d)
{
	ll Bads = B[mid];
	int waste = max(0ll,(mid-1)*d);
	waste -= (B.size()-1-mid);
	waste = max(0,waste);
	int good = G.size()-1 - waste;
	Bads += G[good];
	return Bads;
}

int main()
{
	ll n,d,m;
	cin>>n>>d>>m;

	A.resize(n);
	take(A,0,n);
	sort(all(A));
	int how=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]<=m) G.push_back(A[i]);
		else {B.push_back(A[i]);how++;}
	}
	G.push_back(0);
	B.push_back(0);
	reverse(all(B));
	reverse(all(G));

	for(int i=1;i<(int)B.size();i++)
	{
		B[i]+=B[i-1];
	}
	for(int i=1;i<(int)G.size();i++)
	{
		G[i]+=G[i-1];
	}

	ll ans =0;
	for(int mid = 0;mid<=how;mid++)
	{
		if(mid + (mid-1)*d>n) break;
		ans = max(ans,ok(mid,d));
	}

	cout<<ans<<endl;


}	