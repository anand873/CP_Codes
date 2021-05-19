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

vi A;
vvi dp;

int find(int l, int r)
{
	if(l==r) return dp[l][r] = A[l];
	if(dp[l][r]!=0) return dp[l][r];
	if((r-l+1)%2==0)
	{
		return dp[l][r] = max(-find(l+1,r) + A[l],-find(l,r-1) + A[r]);
	}
	else
	{
		if(A[l]>A[r]) return dp[l][r] = A[l] - find(l+1,r);
		else return dp[l][r] = A[r] - find(l,r-1);
	}
}

int main()
{
	test()
	{
		int n;
		cin>>n;
		A.resize(n+1);
		take(A,1,n);
		dp.resize(n+1);
		for(int i=0;i<=n;i++) dp[i].resize(n+1);
		int score1 = find(1,n);
		// int sum = 0;
		// for(int i=1;i<=n;i++) sum += A[i];

		// for(int i=1;i<=n;i++)
		// {
		// 	for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
		// 	cout<<endl;
		// }

		if(score1 > 0)
		{
			cout<<1<<" "<<score1<<endl;
		}
		else
		{
			cout<<2<<" "<<-score1<<endl;
		}
		A.clear();
		dp.clear();
	}
}	