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

vi Top;
vector<bool> vis;
vvi V;

void dfs(int u)
{
	vis[u]=true;
	for(auto v:V[u])
	{
		dfs(v);
	}
	Top.push_back(u);
}

int main()
{
	int n;
	cin>>n;
	V.resize(n+1);
	vi P(n+1);
	vl A(n+1);
	vis.resize(n+1);
	take(A,1,n);

	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		if(p==-1) p=0;
		P[i] = p;
		V[p].push_back(i);
	}
	dfs(0);
	vi Good,Bad;
	ll ans = 0;
	// prinv(Top);
	for(auto t:Top)
	{
		if(t==0) break;
		ans+=A[t];
		if(A[t]>0)
		{
			Good.push_back(t);
			A[P[t]]+=A[t];
		}
		else
		{
			Bad.push_back(t);
		}
	}
	reverse(all(Bad));
	for(auto b:Bad)
	{
		Good.push_back(b);
	}
	cout<<ans<<endl;
	prinv(Good);



}	