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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	vl P10(MAX);
	P10[0]=1;
	for(int i=1;i<MAX;i++) P10[i]=(P10[i-1]*10)%MOD;
	vvl dp(MAX,vl(9));
	vvl hm(MAX,vl(9));
	for(int i=0;i<9;i++) hm[1][i]=1;
	dp[1][1]=1;
	dp[1][2]=2;
	dp[1][3]=3;
	dp[1][4]=4;
	dp[1][5]=5;
	dp[1][6]=6;
	dp[1][7]=7;
	dp[1][8]=8;
	dp[1][0]=9;
	for(int i=0;i<MAX;i++)
	{
		for(int j=10;j<=99;j++)
		{
			if(j%10==j/10&&(2*(j%10))%9==i) {dp[2][i]+=j;hm[2][i]++;}
		}
	}
	//for(int i=0;i<9;i++) cout<<dp[2][i]<<" ";
	//cout<<endl;
	for(int i=3;i<MAX;i++)
	{
		for(int k=1;k<=9;k++)
		{
			for(int l=0;l<9;l++)
			{
				dp[i][(l+2*k)%9]+=(dp[i-2][l]*10)%MOD+(hm[i-2][l]*(k+(P10[i-1]*k)%MOD))%MOD;
				dp[i][(l+2*k)%9]%=MOD;
				hm[i][(l+2*k)%9]+=hm[i-2][l];
				hm[i][(l+2*k)%9]%=MOD;
			}
		}
	}
	test()
	{
		int n;//=100000;
		cin>>n;
		if(n==1) {cout<<9<<endl;continue;}
		else if(n==2)
		{
			cout<<99<<endl;
			continue;
		}
		else cout<<dp[n][0]<<endl;
	}
}		