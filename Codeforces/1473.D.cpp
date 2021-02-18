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
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

struct MinSegTree 
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
	ll sum(int a, int b)
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

struct MaxSegTree 
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
			Tree[k]=max(Tree[2*k],Tree[2*k+1]);
		}
	}
	ll sum(int a, int b)
	{
		a+=n;b+=n;
		ll s=-INF;
		while(a<=b)
		{
			if(a%2==1) s=max(s,Tree[a++]);
			if(b%2==0) s=max(s,Tree[b--]);
			a/=2;b/=2;
		}
		return s;
	}
};

int main()
{
	test()
	{
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		vi PS(n+1);
		MinSegTree MinT;
		MaxSegTree MaxT;
		MinT.init(n);MaxT.init(n);
		for(int i=0;i<n;i++)
		{
			PS[i+1] = PS[i] + 2*(s[i]=='+') - 1;
			MinT.set(i+1,PS[i+1]);
			MaxT.set(i+1,PS[i+1]);
		}
		// prinv(PS);
		for(int i=0;i<m;i++)
		{
			int l,r;
			cin>>l>>r;
			if(l==1&&r==n)
			{
				cout<<1<<endl;
				continue;
			}
			else if(r==n)
			{
				int leftmin = MinT.sum(1,l-1);
				int leftmax = MaxT.sum(1,l-1);
				if(leftmin<0&&leftmax<0)
				{
					cout<<leftmax - leftmin +2<<"\n";
				}
				else if(leftmin>0&&leftmax>0)
				{
					cout<<leftmax - leftmin + 2<<"\n";
				}
				else cout<<leftmax - leftmin + 1<<"\n";

				continue;
			}
			else if(l==1)
			{
				int leftmin = MinT.sum(r+1,n) - PS[r];
				int leftmax = MaxT.sum(r+1,n) - PS[r];
				if(leftmin<0&&leftmax<0)
				{
					cout<<leftmax - leftmin +2<<"\n";
				}
				else if(leftmin>0&&leftmax>0)
				{
					cout<<leftmax - leftmin + 2<<"\n";
				}
				else cout<<leftmax - leftmin + 1<<"\n";

				continue;
			}
			int leftmin = MinT.sum(1,l-1);
			int leftmax = MaxT.sum(1,l-1);
			int rightmin = MinT.sum(r+1,n) - PS[r];
			int rightmax = MaxT.sum(r+1,n) - PS[r];
			int mintot = min(leftmin,PS[l-1] + rightmin);
			int maxtot = max(leftmax,PS[l-1] + rightmax);
			if(maxtot<0 || mintot>0)
			{
				cout<<maxtot - mintot + 2<<"\n";
			}
			else cout<<maxtot - mintot +1 <<"\n";

		}
	}
}	