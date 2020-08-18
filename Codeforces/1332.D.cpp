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
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e5+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
/////////////////FastExp///////////////////
//////////////////Sieve////////////////////
vector<bool> is_prime(MAX+1, true);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
        	for (j = i * i; j <= MAX; j += i)
            	is_prime[j] = false;
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	int k;
	cin>>k;
	int n=2,m=3;
	cout<<n<<" "<<m<<endl;
	vvi A(n,vi(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			A[i][j]=1;
		}
	}
	if(k==0)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	A[0][0]=k+powN(2,(int)log2(k)+1);
	A[0][1]=k;
	A[0][2]=0;
	A[1][2]=k;
	A[1][1]=k+powN(2,(int)log2(k)+1);
	A[1][0]=powN(2,(int)log2(k)+1);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	// vvi dp(n+1,vi(m+1));
	// dp[0][1]=A[0][0];
	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 	{
	// 		dp[i][j]=max(dp[i-1][j]&A[i-1][j-1],dp[i][j-1]&A[i-1][j-1]);
	// 	}
	// }
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<dp[n][m]<<endl;
}		