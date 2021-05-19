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
int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 2e18+5;

int main()
{
	int n,m;
	ll w;
	cin>>n>>m>>w;
	vvi M(n+5,vi(m+5));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>M[i][j];
		}
	}

	set<ll> SS,SE;
	vvi vis(n+1,vi(m+1));
	vvi D(n+1,vi(m+1));
	queue<pii> Q;
	Q.push({1,1});
	vis[1][1] = 1;
	D[1][1]=0;
	ll ans = INF;
	while(!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		if(x==n&&y==m) ans = w*D[n][m];
		Q.pop();
		if(M[x][y]!=0)
		{
			SS.insert(w*D[x][y]+M[x][y]);
		}
		if(x+1<=n && vis[x+1][y]==0 && M[x+1][y]!=-1)
		{
			Q.push({x+1,y});
			vis[x+1][y]=1;
			D[x+1][y]=D[x][y]+1;
		}
		if(x-1>=1 && vis[x-1][y]==0 && M[x-1][y]!=-1)
		{
			Q.push({x-1,y});
			vis[x-1][y]=1;
			D[x-1][y]=D[x][y]+1;
		} 
		if(y+1<=m && vis[x][y+1]==0 && M[x][y+1]!=-1)
		{
			Q.push({x,y+1});
			vis[x][y+1]=1;
			D[x][y+1]=D[x][y]+1;
		} 
		if(y-1>=1 && vis[x][y-1]==0 && M[x][y-1]!=-1)
		{
			Q.push({x,y-1});
			vis[x][y-1]=1;
			D[x][y-1]=D[x][y]+1;
		} 
	}


	vis.clear();
	D.clear();
	D.resize(n+1,vi(m+1));
	vis.resize(n+1,vi(m+1));
	Q.push({n,m});
	vis[n][m] = 1;
	while(!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		// cout<<x<<" "<<y<<endl;
		Q.pop();
		if(M[x][y]!=0)
		{
			SE.insert(w*D[x][y]+M[x][y]);
		}
		if(x+1<=n && vis[x+1][y]==0 && M[x+1][y]!=-1)
		{
			Q.push({x+1,y});
			vis[x+1][y]=1;
			D[x+1][y]=D[x][y]+1;
		}
		if(x-1>=1 && vis[x-1][y]==0 && M[x-1][y]!=-1)
		{
			Q.push({x-1,y});
			vis[x-1][y]=1;
			D[x-1][y]=D[x][y]+1;
		} 
		if(y+1<=m && vis[x][y+1]==0 && M[x][y+1]!=-1)
		{
			Q.push({x,y+1});
			vis[x][y+1]=1;
			D[x][y+1]=D[x][y]+1;
		} 
		if(y-1>=1 && vis[x][y-1]==0 && M[x][y-1]!=-1)
		{
			Q.push({x,y-1});
			vis[x][y-1]=1;
			D[x][y-1]=D[x][y]+1;
		}
	}
	// prinv(SS);
	// prinv(SE);
	if(SE.size()&&SS.size())
	{
		ans = min(ans,*SE.begin() + *SS.begin());
	}
	if(ans == INF) cout<<-1<<endl;
	else cout<<ans<<endl;
	
}