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
#define KStest(t,t1) int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e5+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p,ll mod)
{
	if(p==0) return 1;
	ll z=powN(a,p/2,mod);
	z=(z*z)%mod;
	if(p%2) z=(z*a)%mod;
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
	int n,m,p,z;
	cin>>n>>m>>p>>z;
	vl W(m+1);
	take(W,1,m);

	vl HOW(10);
	for(int i=1;i<=m;i++) HOW[W[i]]++;

	vvl dp(n+1,vl(z));
	for(int i=1;i<=m;i++)
	{
		dp[1][W[i]%z]++;
	}
	vvl EX(n+1,vl(10));
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			EX[i][j]=(j*powN(10,i,z))%z;
		}
	}

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int rem=0;rem<z;rem++)
			{
				dp[i+1][(rem+EX[i][j])%z] += (dp[i][rem]*HOW[j])%MOD;
				dp[i+1][(rem+EX[i][j])%z]%=MOD;
			}
		}
	}
	ll ans=0;
	for(int rem=0;rem<=p;rem++) {ans+=dp[n][rem];ans%=MOD;}
	cout<<ans<<endl;
}		