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

vvi A;
vl SC;
vl P;
vl H;
vector<bool> vis;

void dfs(int x)
{
	vis[x]=true;
	SC[x]+=P[x];
	for(auto y:A[x])
	{
		if(!vis[y])
		{
			dfs(y);
			SC[x]+=SC[y];
		}
	}
}

int main()
{
	test()
	{
		int n,m;
		cin>>n>>m;

		P.resize(n+1);
		take(P,1,n);

		H.resize(n+1);
		take(H,1,n);

		A.resize(n+1);
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			A[x].push_back(y);
			A[y].push_back(x);
		}

		SC.resize(n+1);
		vis.resize(n+1);

		dfs(1);

		bool can=true;
		vl G(n+1),B(n+1);

		for(int x=1;x<=n;x++)
		{
			if((SC[x]+H[x])%2|| (SC[x]<H[x])) {can=false;break;}
			else
			{
				G[x] = (SC[x]+H[x])/2;
				B[x] = (SC[x]-H[x])/2;
			}
		}

		if(!can)
		{

			SC.clear();
			vis.clear();
			A.clear();
			P.clear();
			H.clear();

			cout<<"NO"<<endl;
			continue;
		}

		vis.clear();
		vis.resize(n+1);
		queue<int> Q;
		Q.push(1);
		vis[1]=true;
		while(!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			ll good=0,bad=0;
			for(auto y:A[x])
			{
				if(!vis[y])
				{
					vis[y]=true;
					good+=G[y];
					bad+=B[y];

					Q.push(y);
				}
			}
			// cout<<good<<" "<<bad<<" "<<G[x]<<" "<<B[x]<<endl;
			if(good<=G[x]&&(good+bad==G[x]+B[x]-P[x])) continue;
			else {can=false;break;}
		}

		SC.clear();
		vis.clear();
		A.clear();
		P.clear();
		H.clear();
		if(!can) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}	