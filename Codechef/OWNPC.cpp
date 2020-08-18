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
	int n,m,k;
	cin>>n>>m>>k;
	vector<pii> dp(5000005);
	dp[0]={0,0};
	vi M(n+5),P(n+5);
	for(int i=1;i<=n;i++)
	{
		cin>>M[i]>>P[i];
	}
	for(int j=0;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(dp[j].first+M[i]>=dp[j+P[i]].first)
				dp[j+P[i]]={dp[j].first+M[i],dp[j].second+1};
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=0;j<=m;j++)
	// 	{
	// 		if(dp[j].first+M[i]>=dp[j+P[i]].first)
	// 			dp[j+P[i]]={dp[j].first+M[i],dp[j].second+1};
	// 	}
	// }
	int ma=0;
	for(int i=0;i<=m;i++)
	{
		if(dp[i].second>=k) ma=max(ma,dp[i].first);
	}
	if(ma>0)
		cout<<"YES "<<ma<<endl;
	else cout<<"NO"<<endl;


}		