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
	int INF = 1e9+5; 
	string s;
	cin>>s;
	int k;
	cin>>k;
	int n=s.length();
	vi dp(n+2,INF);
	map<char,char> M;
	for(int i=0;i<k;i++)
	{
		char a,b;
		cin>>a>>b;
		M[a]=b;
		M[b]=a;
	}
	vvi W(n+1,vi(26));
	for(int i=0;i<26;i++)
	{
		W[n][i]=n+1;
	}
	for(int i=n-1;i>0;i--)
	{
		for(int j=0;j<26;j++)
		{
			if(j!=s[i]-'a') W[i][j]=W[i+1][j];
			else W[i][j]=i+1;
		}
	}
	vi AA(n+1,INF);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(M[s[i-1]]==(char)(j+'a')) continue;
			AA[i]=min(AA[i],W[i][j]);
		}
	}
	for(int i=1;i<=n;i++) what(AA[i]);
	dp[0]=0;
	for(int i=1;i<=n;i++)
		dp[i]=i-1;
	for(int i=1;i<=n;i++)
	{
		int x=AA[i];
		dp[x]=min(dp[x],dp[i]+x-i-1);
	}
	for(int i=1;i<=n+1;i++) cout<<dp[i]<<endl;
}		