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
	int n;
	cin>>n;
	string s;
	cin>>s;
	string rs=s;
	reverse(all(rs));
	vector<SegTree> ST(26);
	for(int i=0;i<26;i++)
	{
		ST[i].init(n);
		for(int j=1;j<=n;j++)
		{
			ST[i].set(j,0);
		}
	}
	for(int i=0;i<n;i++)
	{
		ST[rs[i]-'a'].set(i+1,1);
	}
	vvi W(26);
	for(int i=0;i<n;i++)
	{
		W[rs[i]-'a'].push_back(i+1);
	}
	for(int i=0;i<26;i++)
	{
		reverse(all(W[i]));
	}
	ll ans = 0;
	int curr=1;
	for(int i=0;i<n;i++)
	{
		ans += max(0ll,ST[s[i]-'a'].sum(curr,W[s[i]-'a'].back()));
		// if(s[i]==rs[curr]) curr++;
		for(int j=0;j<26;j++)
		{
			ST[j].set(W[s[i]-'a'].back(),-1);
		}
		ST[s[i]-'a'].set(W[s[i]-'a'].back(),0);
		W[s[i]-'a'].pop_back();
	}
	cout<<ans<<endl;
}	