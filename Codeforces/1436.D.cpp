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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

vvi V;
vl A;
vi Leaves;
vl Sum;

void dfs(int u)
{
	Sum[u] += A[u];
	for(auto v:V[u])
	{
		dfs(v);
		Leaves[u] += Leaves[v];
		Sum[u] += Sum[v];
	}
	if(V[u].empty()) Leaves[u]=1;
}

int main()
{
	int n;
	cin>>n;
	V.resize(n+1);
	Sum.resize(n+1);
	Leaves.resize(n+1);
	for(int i=2;i<=n;i++)
	{
		int p;
		cin>>p;
		V[p].push_back(i);
	}

	A.resize(n+1);
	take(A,1,n);
	ll ans = 0;

	dfs(1);
	// prinv(Sum);prinv(Leaves);

	for(int i=1;i<=n;i++)
	{
		ans = max(ans,(Sum[i]+Leaves[i]-1)/Leaves[i]);
	}
	cout<<ans<<'\n';
}	