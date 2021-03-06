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

const int MOD = 1e9+7,MAX = 1e4+5;
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
	test()
	{
		int n,m;
		cin>>n>>m;
		vi A(n+1);
		take(A,1,n);
		sort(1+all(A));
		ll dp[n+1][n+1][MAX];
		for(int i=0;i<n+1;i++)
		{
			for(int j=0;j<n+1;j++)
			{
				for(int k=0;k<MAX;k++)
				{
					dp[i][j][k]=0;
				}
			}
		}
		dp[1][1][A[1]]=1;
		dp[1][0][0]=1;
		for(int i=2;i<=n;i++)
		{
			//If We Take.
			for(int j=0;j<i;j++)
			{
				for(int k=0;k+A[i]<MAX;k++)
				{
					dp[i][j+1][k+A[i]]+=dp[i-1][j][k];
				}
			}
			//If Not Take.
			for(int j=0;j<i;j++)
			{
				for(int k=0;k<MAX;k++)
				{
					dp[i][j][k]+=dp[i-1][j][k];
				}
			}
		}

		// for(int j=0;j<n+1;j++)
		// {
		// 	for(int k=0;k<50;k++)
		// 	{
		// 		cout<<dp[n][j][k]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=dp[n][i][m];
		}
		cout<<ans<<endl;
		
		

	}
	

}		