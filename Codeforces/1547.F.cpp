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
	vector<int> Tree;
	void init(int sz)
	{
		n = sz;
		Tree.resize(4*n);
	}
	void set(int k, int x) 
	{
		k+=n;
		Tree[k]=x;
		for(k=k/2;k>=1;k/=2)
		{
			Tree[k]=__gcd(Tree[2*k],Tree[2*k+1]);
		}
	}
	int sum(int a, int b)
	{
		a+=n;b+=n;
		int s=0;
		while(a<=b)
		{
			if(a%2==1) s = __gcd(s,Tree[a++]);
			if(b%2==0) s = __gcd(s,Tree[b--]);
			a/=2;b/=2;
		}
		return s;
	}
};

int main()
{
	test()
	{
		int n;
		cin>>n;
		SegTree ST;
		ST.init(2*n);
		vi A(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>A[i];
			ST.set(i,A[i]);
		}
		for(int i=1;i<=n;i++)
		{
			A.push_back(A[i]);
			ST.set(n+i,A[i]);
		}
		int ans = 0;
		int low = 0, high = n-1;
		while(low<=high)
		{
			int mid = low + (high - low)/2;
			set<int> S;
			for(int i=1;i<=n;i++)
			{
				S.insert(ST.sum(i,i+mid));
			}
			if(S.size()==1)
			{
				ans = mid;
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		cout<<ans<<endl;
	}
}	