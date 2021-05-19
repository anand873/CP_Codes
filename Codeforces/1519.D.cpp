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

int main()
{
	int n;
	cin>>n;
	vl A(n+1);
	vl B(n+1);
	take(A,1,n);
	take(B,1,n);
	
	vvl RevP(n+1,vl(n+1));
	vl P(n+1);
	for(int i=1;i<=n;i++)
	{
		P[i] = P[i-1] + A[i]*B[i];
	}
	for(int i=1;i<=n;i++)
	{
		RevP[i][i] = A[i]*B[i];
		for(int j=1;i-j>=1 && j+i<=n;j++)
		{
			RevP[i-j][i+j] = RevP[i-j+1][i+j-1] + A[i-j]*B[i+j] + A[i+j]*B[i-j];
		}
		if(i+1<=n)
		{
			RevP[i][i+1] = A[i]*B[i+1] + A[i+1]*B[i];
		}
		for(int j=1;i-j>=1 && j+i+1<=n;j++)
		{
			RevP[i-j][i+1+j] = RevP[i-j+1][i+j] + A[i-j]*B[i+j+1] + A[i+j+1]*B[i-j];
		}
	}
	ll ans = P[n];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans = max(ans , P[i-1] + P[n] - P[j] + RevP[i][j]);
		}
	}
	cout<<ans<<endl;
}	