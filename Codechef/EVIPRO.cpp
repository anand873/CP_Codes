//Author: AnandRaj anand873
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
	test(t)
	{
		string s;
		cin>>s;
		ll n =s.length(); 
		vl H(n+2),L(n+2);
		for(int i=n-1;i>0;i--)
		{
			if(s[i]==s[i-1]) H[i]=H[i+1]+1;
			else H[i]=H[i+1];
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]==s[i+1]) L[i+1]=L[i]+1;
			else L[i+1]=L[i];
		}
		vl dp(n+1);
		ll ans=0;
		if(n==1) {cout<<0<<endl;goto en;}
		if(s[1]==s[0]) dp[1]=H[2];
		else dp[1]=1+H[2];
		for(ll i=1;i<n;i++)
		{
			if(s[i]==s[i-1])
			{
				if(i+1>=n)
				{
					dp[i+1]=dp[i]+i+L[i]-1;
					continue;
				}
				if(s[i]==s[i+1])
				{
					dp[i+1]=dp[i]+H[i+2]+L[i]-1;
				}
				else
				{
					dp[i+1]=dp[i]+2*i+1+H[i+2]+L[i]-1;
				}
			}
			else
			{
				if(i+1>=n)
				{
					dp[i+1]=dp[i]-i+L[i]+1;
					continue;
				}
				if(s[i]==s[i+1])
				{
					dp[i+1]=dp[i]-2*i+H[i+2]+L[i]+1;
				}
				else
				{
					dp[i+1]=dp[i]+H[i+2]+L[i]+2;
				}
			}
		}
		//prin(dp);
		for(int i=1;i<=n;i++) ans+=dp[i];
		cout<<ans<<endl;
		en:;
	}
}