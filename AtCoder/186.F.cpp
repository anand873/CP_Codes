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

struct SegTree 
{
	// 1-Based
	int n;
	vector<ll> Tree;
	void init(int sz)
	{
		n = sz;
		Tree.resize(4*n);
	}
	void set(int k, ll x) 
	{
		k+=n;
		Tree[k]=x;
		for(k=k/2;k>=1;k/=2)
		{
			Tree[k]=Tree[2*k]+Tree[2*k+1];
		}
	}
	ll sum(int a, int b)
	{
		a+=n;b+=n;
		ll s=0;
		while(a<=b)
		{
			if(a%2==1) s+=Tree[a++];
			if(b%2==0) s+=Tree[b--];
			a/=2;b/=2;
		}
		return s;
	}
};

int main()
{
	int h,w,m;
	cin>>h>>w>>m;
	vi C(w+5,h+1);
	vpii R(h+1);
	for(int i=1;i<=h;i++)
	{
		R[i] = {w+1,i};
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		R[x].first = min(R[x].first,y);
		C[y] = min(C[y],x);
	}
	ll ans = 0;
	int y = 0;
	for(int i=1;i<=w;i++) if(C[i]>1) {ans += (C[i]-1);y++;}
	
	SegTree M;
	M.init(h+5);
	for(int i=1;i<=h;i++)
	{
		if(R[i].second==1) break;
		M.set(R[i].first,)
		ans += R[i].first - M.sum(R[i].second+1,h+1);
	}
	cout<<ans<<endl;
}	