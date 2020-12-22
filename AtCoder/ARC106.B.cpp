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

vector<int> parent(MAX,-1);
vector<int> Siz(MAX,0);
void make_set(int i)
{
	parent[i]=i;
	Siz[i]=1;
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
		if(Siz[i]>Siz[j]) swap(i,j);
		parent[i]=j;
		Siz[j]+=Siz[i];
	}
}


int main()
{
	int n,m;
	cin>>n>>m;
	vl A(n+1),B(n+1);
	take(A,1,n);
	take(B,1,n);
	for(int i=1;i<=n;i++) make_set(i);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		union_set(u,v);
	}
	map<int,ll> M; 
	for(int i=1;i<=n;i++)
	{
		M[find_set(i)] += A[i] - B[i];
	}
	bool can=true;
	for(auto m:M)
	{
		if(m.second) can=false;
	}
	if(!can) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}	