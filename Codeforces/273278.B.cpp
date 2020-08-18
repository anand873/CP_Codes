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
			T[k]=T[2*k]+T[2*k+1];
			k/=2;
		}
	}
	ll sum(int l,int r)
	{
		l+=n;
		r+=n;
		ll s = 0;
		while(l<=r)
		{
			if(l%2) s+=T[l++];
			if(r%2==0) s+=T[r--];
			l/=2;r/=2;
		}
		return s;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	vi A(n);
	SegTree T;
	T.init(n);

	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		T.set(i,A[i]);
	}

	for(int i=0;i<m;i++)
	{
		int t,x;
		cin>>t>>x;
		if(t==1)
		{
			T.set(x,1-A[x]);
			A[x] = 1-A[x];
		}
		else
		{
			int ans=-1;
			int low = 0,high = n-1;
			while(low<=high)
			{
				int mid = low+(high-low)/2;
				if(T.sum(0,mid)<x+1)
				{
					low = mid+1;
				}
				else
				{
					ans = mid;
					high = mid-1;
				}
			}
			cout<<ans<<endl;
		}
	}
}	