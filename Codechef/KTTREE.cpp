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
const int MOD = 998244353,MAX = 1e6+5;
const ll INF = 1e18+5;


int main()
{
	test()
	{
		// cout<<"Here"<<endl;
		int n,k;
		cin>>n>>k;
		vi A(n+1);
		take(A,1,n);
		vvi V(n+1);
		
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			V[u].push_back(v);
			V[v].push_back(u);
		}
		vvi M;
		vi vis(n+1);
		for(int i=1;i<=n;i++)
		{
			if(vis[i]||A[i]==0) continue;
			queue<int> Q;
			Q.push(i);
			vis[i]=true;
			vi X(k+1);
			while(!Q.empty())
			{
				int x = Q.front();
				// cout<<x<<" ";
				Q.pop();
				X[A[x]]++;
				for(auto v:V[x])
				{
					if(!vis[v]&&A[v]!=0)
					{
						vis[v]=true;
						Q.push(v);
					}
				}
			}
			M.push_back(X);
			// prinv(X);
		}
		int numset = M.size();
		vvl dp(numset+1,vl(1<<k));
		for(int i=1;i<=numset;i++)
		{
			dp[i] = dp[i-1];
			for(int j=1;j<=k;j++)
			{
				if(M[i-1][j]==0) continue;
				dp[i][1<<(j-1)] += M[i-1][j];
			}
			for(int j=0;j<(1<<k);j++)
			{
				for(int l=1;l<=k;l++)
				{
					if(((j>>(l-1))&1)==0&&M[i-1][l])
					{
						dp[i][j^(1<<(l-1))] += (dp[i-1][j]*M[i-1][l])%MOD;
						dp[i][j^(1<<(l-1))]%=MOD;
					}
				}
			}
			// prinv(dp[i]);
		}
		cout<<dp[numset][(1<<k) - 1]<<endl;
	}
}	