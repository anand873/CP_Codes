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
#define test(t) int t;cin>>t;while(t--)
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl

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
	ll INF = 1e12;
	int n,m,k;
	cin>>n>>m>>k;
	vl C(n+1);
	take(C,1,n);
	vvl P(n+1,vl(m+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>P[i][j];
		}
	}
	ll dp[n+1][n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int l=0;l<=m;l++)
			{
				dp[i][j][l]=INF;
			}
		}
	}
	if(C[1]!=0)
	{
		dp[1][1][C[1]]=0;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			dp[1][1][i]=P[1][i];
		}
	}
	for(int i=1;i<n;i++)
	{
		if(C[i+1]==0)
		{
			for(int j=1;j<=i;j++)
			{
				for(int last=1;last<=m;last++)
				{
					if(dp[i][j][last]==INF) continue;
					for(int next=1;next<=m;next++)
					{
						if(last==next)
						{
							dp[i+1][j][next]=min(dp[i+1][j][next],dp[i][j][last]+P[i+1][next]);
						}
						else
						{
							dp[i+1][j+1][next]=min(dp[i+1][j+1][next],dp[i][j][last]+P[i+1][next]);
						}
					}
				}
			}
		}
		else
		{
			for(int j=1;j<=i;j++)
			{
				for(int last=1;last<=m;last++)
				{
					if(dp[i][j][last]==INF) continue;
					if(last==C[i+1])
					{
						dp[i+1][j][C[i+1]]=min(dp[i+1][j][C[i+1]],dp[i][j][last]);
					}
					else
					{
						dp[i+1][j+1][C[i+1]]=min(dp[i+1][j+1][C[i+1]],dp[i][j][last]);
					}
				}
			}
		}
	}
	ll ans=INF;
	if(C[n]==0)
	{
		for(int col=1;col<=m;col++)
		{
			ans=min(dp[n][k][col],ans);
		}
	}
	else
	{
		ans=dp[n][k][C[n]];
	}
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
}