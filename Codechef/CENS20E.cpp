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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

vector<int> parent;
vector<int> size;
void make_set(int i)
{
	parent[i]=i;
	size[i]=1;
}

int find_set(int i)
{
	if(parent[i]==i) return i;
	else return parent[i]=find_set(parent[i]);
}

void union_set(int i,int j)
{
	i=find_set(i);
	j=find_set(j);
	if(i!=j)
	{
		if(size[i]>size[j]) swap(i,j);
		parent[i]=j;
		size[j]+=size[i];
	}
}

int main()
{
	fastio
	test()
	{
		int n,m;
		cin>>n>>m;
		parent.resize(n+1);
		size.resize(n+1);
		for(int i=1;i<=n;i++) make_set(i);
		vi W(n+1);
		take(W,1,n);

		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			if(__builtin_popcount(W[u]^W[v])%2==0)
			{
				union_set(u,v);
			}
		}
		int odmax=0,evmax=0;
		for(int i=1;i<=n;i++)
		{
			if((__builtin_popcount(W[find_set(i)]))%2) odmax=max(odmax,size[find_set(i)]);
			else evmax=max(evmax,size[find_set(i)]);
		}
		int q;
		cin>>q;
		while(q--)
		{
			int x;
			int k;
			cin>>x>>k;
			if(x==1)
			{
				if(__builtin_popcount(k)%2==0)
				{
					cout<<odmax<<endl;
				}
				else cout<<evmax<<endl;
			}
			else
			{
				if(__builtin_popcount(k)%2==0)
				{
					cout<<evmax<<endl;
				}
				else cout<<odmax<<endl;
			}
		}
		parent.clear();
		size.clear();

	}	

}
