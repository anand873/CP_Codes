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

struct DSU
{
	vi weight,parent;
	void init(int n)
	{
		weight.resize(n);
		parent.resize(n);
		for(int i=0;i<n;i++)
		{
			parent[i]=i;
			weight[i]=1;
		}
	}
	int find_set(int a)
	{
		if(parent[a]==a) return a;
		else return parent[a]=find_set(parent[a]);
	}
	void union_set(int a, int b)
	{
		a = find_set(a);
		b = find_set(b);
		if(a!=b)
		{
			if(weight[a]>weight[b]) swap(a,b);
			parent[a] = b;
			weight[b] += weight[a];
		}
	}
};

int main()
{
	test()
	{
		int n;
		cin>>n;
		DSU D;
		D.init(n);
		vi H(n);
		take(H,0,n);
		vector<int> Curr;
		Curr.push_back(0);
		vi C(n);
		for(int i=1;i<n;i++)
		{
			while(!Curr.empty() && H[Curr.back()]<H[i])
			{
				Curr.pop_back();
			}
			if(H[Curr.back()]==H[i])
			{
				D.union_set(Curr.back(),i);
				Curr.pop_back();
			}
			Curr.push_back(i);
		}
		for(int i=0;i<n;i++)
		{
			C[i] = D.weight[D.find_set(i)]-1;
		}
		prinv(C);
	}
}	