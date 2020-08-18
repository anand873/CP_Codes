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
	int n;
	vl T;

	void init(int sz)
	{
		n = sz;
		T.resize(4*n);
	}
	void set(int k,ll x)
	{
		k+=n;
		T[k]=x;
		k/=2;
		while(k>=1)
		{
			T[k]=min(T[2*k],T[2*k+1]);
			k/=2;
		}
	}
	ll sum(int l,int r)
	{
		l+=n;
		r+=n;
		ll s = MOD;
		while(l<=r)
		{
			if(l%2) s=min(s,T[l++]);
			if(r%2==0) s=min(s,T[r--]);
			l/=2;r/=2;
		}
		return s;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	SegTree ST;
	ST.init(n);

	for(int i=0;i<n;i++)
	{
		int v;
		cin>>v;		
		ST.set(i,v);
	}
	for(int i=0;i<m;i++)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			int p,v;
			cin>>p>>v;
			ST.set(p,v);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			r--;
			cout<<ST.sum(l,r)<<endl;
		}
	}
}	