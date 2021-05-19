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
int MOD = 1e9+7,MAX = 2e5+5;
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
	ll sum(int k) 
	{
		k+=n;
		ll ans = Tree[k];
		for(k=k/2;k>=1;k/=2)
		{
			ans += Tree[k];
		}
		return ans;
	}
	void add(int a, int b, int x)
	{
		a+=n;b+=n;
		while(a<=b)
		{
			if(a%2==1) Tree[a++]+=x;
			if(b%2==0) Tree[b--]+=x;
			a/=2;b/=2;
		}
	}
};

int main()
{

	int n,t;
	cin>>n>>t;
	SegTree ST;
	ST.init(n);
	vi vis(n+1);
	for(int i=0;i<t;i++)
	{
		int k;
		cin>>k;
		int low=1,high=n;
		int ans = -1;
		while(low<=high)
		{
			int mid = low + (high-low)/2;
			int sum;
			if(!vis[mid])
			{
				cout<<"? "<<1<<" "<<mid<<endl;
				cin>>sum;
				ST.add(mid,mid,sum);
				vis[mid]=1;
			}
			else sum = ST.sum(mid);

			if(mid - sum >=k )
			{
				ans = mid;
				high = mid-1;
			}
			else low = mid+1;
		}
		ST.add(ans,n,1);
		cout<<"! "<<ans<<endl;
	}
}