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
	vpii T;

	void init(int sz)
	{
		n = sz;
		T.resize(4*n);
	}
	void set(int k,int x)
	{
		k+=n;
		T[k]={x,1};
		k/=2;
		while(k>=1)
		{
			if(T[2*k].first<T[2*k+1].first) T[k] = T[2*k];
			else if(T[2*k].first>T[2*k+1].first) T[k] = T[2*k+1];
			else T[k] = {T[2*k].first,T[2*k].second+T[2*k+1].second};
			k/=2;
		}
	}
	pii sum(int l,int r)
	{
		l+=n;
		r+=n;
		pii ans={MOD,1};
		while(l<=r)
		{
			if(l%2)
			{
				if(T[l].first<ans.first) ans = T[l];
				else if(T[l].first==ans.first) ans.second+=T[l].second;
				l++;
			}
			if(r%2==0)
			{
				if(T[r].first<ans.first) ans = T[r];
				else if(T[r].first==ans.first) ans.second+=T[r].second;
				r--;
			}
			l/=2;r/=2;
		}
		return ans;
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
			pii ans = ST.sum(l,r);
			cout<<ans.first<<" "<<ans.second<<endl;
		}
	}
}	