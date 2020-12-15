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

bool is_perm(vi A)
{
	sort(all(A));
	for(int i=1;i<A.size();i++)
	{
		if(A[i]!=i) return false;
	}
	return true;
}

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
			Tree[k]=min(Tree[2*k],Tree[2*k+1]);
		}
	}
	ll minimum(int a, int b)
	{
		a+=n;b+=n;
		ll s=INF;
		while(a<=b)
		{
			if(a%2==1) s=min(s,Tree[a++]);
			if(b%2==0) s=min(s,Tree[b--]);
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
		vi A(n+1);
		take(A,1,n);
		SegTree ST;
		ST.init(n);
		for(int i=1;i<=n;i++)
		{
			ST.set(i,A[i]);
		}
		vi Ans(n+1);
		int l=1,r=n;
		int curr=1;
		for(int i=n;i>=1;i--)
		{
			if(ST.minimum(l,r)==curr)
			{
				Ans[i]=1;
			}
			else break;

			if(A[l]==curr) l++;
			else if(A[r]==curr) r--;
			else break;
			
			curr++;
		}
		if(is_perm(A)) Ans[1] = 1;
		for(int i=1;i<=n;i++) cout<<Ans[i];
		cout<<endl;
	}	
}	