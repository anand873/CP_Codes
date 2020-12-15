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

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vvi M(n+1,vi(m+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>M[i][j];
		}
	}
	vvi dp(n+1,vi(k));
	for(int i=1;i<=n;i++)
	{
		int dpt[m+1][m+1][k];
		for(int u=0;u<=m;u++)
		{
			for(int v=0;v<=m;v++)
			{
				for(int w=0;w<k;w++)
				{
					dpt[u][v][w]=0;
				}
			}
		}
		// cerr<<"Here"<<endl;
		for(int u=1;u<=m;u++)
		{
			for(int v=0;v<=m;v++)
			{
				for(int w=0;w<k;w++)
				{
					dpt[u][v][w] = max(dpt[u][v][w],dpt[u-1][v][w]);
				}
				if(v==0) continue;
				for(int w=0;w<k;w++)
				{
					if(dpt[u-1][v-1][w]%k!=w) continue;
					dpt[u][v][(w+M[i][u])%k] = max(dpt[u][v][(w+M[i][u])%k],dpt[u-1][v-1][w]+M[i][u]);
				}
			}
		}
		// cerr<<"Here"<<endl;
		vi Maxk(k);
		for(int w=0;w<k;w++)
		{
			for(int v=0;v<=m/2;v++)
			{
				Maxk[w] = max(Maxk[w],dpt[m][v][w]);
			}
		}
		// prinv(Maxk);
		for(int last=0;last<k;last++)
		{
			for(int curr=0;curr<k;curr++)
			{
				if(dp[i-1][last]%k!=last) continue;
				dp[i][(curr+last)%k] = max(dp[i][(curr+last)%k],dp[i-1][last] + Maxk[curr]);
			}
		}
	}

	cout<<dp[n][0]<<endl;
}	