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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;


int main()
{
	fastio
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> R(n*m),D(n*m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			int x;
			cin>>x;
			R[i*m+j] = x;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			D[i*m+j] = x;
		}
	}

	
	for(int i=0;i<n*m;i++)
	{
		unordered_map<int,int> dp;
		dp[i] = 0;
		for(int val=1;val<=k;val++)
		{
			unordered_map<int,int> dp_new;
			int cx = i/m;
			int cy = i%m;
			for(auto mm:dp)
			{
				int pos = mm.first;
				int bore = mm.second;
				int x = pos/m;
				int y = pos%m;

				if(x+1<n && (abs(x+1-cx) + abs(y-cy))<=k-val && ((abs(x+1-cx) + abs(y-cy))-k+val)%2==0)
				{
					if(dp_new[(x+1)*m+y]==0) dp_new[(x+1)*m+y] = MOD;
					dp_new[(x+1)*m+y] = min(dp_new[(x+1)*m+y],dp[pos] + D[x*m+y]);
				}
				if(y+1<m && (abs(x-cx) + abs(y+1-cy))<=k-val && ((abs(x-cx) + abs(y+1-cy))-k+val)%2==0)
				{
					if(dp_new[x*m+y+1]==0) dp_new[x*m+y+1] = MOD;
					dp_new[x*m+y+1] = min(dp_new[x*m+y+1], dp[pos] + R[x*m+y]);
				}
				if(x-1>=0 && (abs(x-1-cx) + abs(y-cy))<=k-val && ((abs(x-1-cx) + abs(y-cy))-k+val)%2==0)
				{
					if(dp_new[(x-1)*m+y]==0) dp_new[(x-1)*m+y] = MOD;
					dp_new[(x-1)*m+y] = min(dp_new[(x-1)*m+y],dp[pos] + D[(x-1)*m+y]);

				}
				if(y-1>=0 && (abs(x-cx) + abs(y-1-cy))<=k-val && ((abs(x-cx) + abs(y-1-cy))-k+val)%2==0)
				{
					if(dp_new[x*m+y-1]==0) dp_new[x*m+y-1] = MOD;
					dp_new[x*m+y-1] = min(dp_new[x*m+y-1],dp[pos] + R[x*m+y-1]);
				}
			}
			dp = dp_new;
		}
		if(dp[i]==0) cout<<-1<<" ";
		else cout<<dp[i]<<" ";
		if(i%n==m-1) cout<<'\n';
	}
}	