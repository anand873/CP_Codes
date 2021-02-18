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

struct SegTree 
{
	// 1-Based
	int n;
	vector<ll> TZ;
	vector<ll> Tree;
	vi C;
	void dfs(int u)
	{
		if(u>2*n) {C[u] = 0; return;}
		if(u>n&&u<=2*n) {C[u]=1;return;}
		dfs(2*u);
		dfs(2*u+1);
		C[u] = C[2*u] + C[2*u+1];
	}
	void init(int sz)
	{
		n = sz;
		C.resize(4*n);
		Tree.resize(4*n)
		TZ.resize(4*n);
		this->dfs(1);
	}

	void set(int a,int b, ll x) 
	{
		a+=n;
		b+=n;
		while(a<=b)
		{
			if(a%2==1) TZ[a++] = x;
			if(b%2==0) TZ[b--] = x;
			a/=2;
			b/=2;
		}
	}
	ll sum(int a, int b)
	{
		a+=n;b+=n;
		ll s=0;
		while(a<=b)
		{
			if(a%2==1) {s+=C[a]*Tree[a];a++;}
			if(b%2==0) {s+=C[b]*Tree[b];b--;}
			a/=2;b/=2;
		}
		return s;
	}
};

int main()
{
	test()
	{
		SegTree TF;
		int n,q;
		cin>>n>>q;
		TF.init(n);
		string s,f;
		cin>>s>>f;
		for(int i=1;i<=n;i++)
		{
			TF.set(i,i,(f[i-1]-'0'));
		}

		vi L(q),R(q);
		for(int i=0;i<q;i++)
		{
			cin>>L[i]>>R[i];
		}
		reverse(all(L));
		reverse(all(R));
		bool can = true;
		for(int i=0;i<q;i++)
		{
			for(int i=1;i<=2*n;i++) cout<<TF.TZ[i]<<" ";
			cout<<endl;
			int sum = TF.sum(L[i],R[i]);
			cout<<L[i]<<" "<<R[i]<<" "<<sum<<endl;
			if(2*sum>(R[i]-L[i]+1))
			{
				TF.set(L[i],R[i],1);
			}
			else if(2*sum<(R[i]-L[i]+1))
			{
				TF.set(L[i],R[i],0);
			}
			else
			{
				can = false;
				break;
			}
			for(int i=1;i<=n;i++)
			{
				cout<<TF.TZ[i+n];
			}
			cout<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			if(TF.sum(i,i)!=(s[i-1]-'0')) can = false;
		}
		if(!can) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}	