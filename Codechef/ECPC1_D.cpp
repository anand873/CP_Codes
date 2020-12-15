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

vi P;
vvi V;
vi B;

void dfs(int u)
{
	int one=0,notone=0;
	for(auto v:V[u])
	{
		dfs(v);
		if(B[v]==1) one++;
		else notone+=B[v];
	}
	B[u] = one%3 + notone + 1;
}

int main()
{
	test()
	{
		int n;
		cin>>n;
		V.resize(n+1);
		P.resize(n+1);
		for(int i=2;i<=n;i++)
		{
			cin>>P[i];
			V[P[i]].push_back(i);
		}
		B.resize(n+1);
		dfs(1);
		// prinv(B);
		cout<<B[1]<<endl;
		V.clear();
		P.clear();
		B.clear();
	}
}	