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
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e6+5;
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
vector<bool> is_prime(MAX, true);
vector<int> MinDiv(MAX);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
    		MinDiv[i]=i;
        	for (j = i * i; j <= MAX; j += i)
            {
				is_prime[j] = false;
				MinDiv[j]=i;
    		}
    	}
	}
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	string s;
	cin>>s;
	vi W;
	int n=s.length();
	string snew;
	int curr=0;
	snew+=s[0];
	for(int i=1;i<n;i++)
	{
		if(s[i]=='v'&&s[i-1]=='v')
		{
			snew+='v';
		}
		else if(s[i]=='o'&&s[i-1]=='o')
		{
			snew+='o';
		}
		else if(s[i]=='v'&&s[i-1]=='o')
		{
			snew+='v';
		}
		else
		{
			snew.pop_back();
			snew+='o';
		}
	}
	snew.pop_back();
	// cout<<snew<<endl;
	vi dp(snew.length()),pp(snew.length());

	for(int i=1;i<snew.length();i++)
	{
		dp[i]=dp[i-1]+(snew[i-1]=='v');
	}
	for(int i=snew.length()-2;i>=0;i--)
	{
		pp[i]=pp[i+1]+(snew[i+1]=='v');
	}

	ll sum=0;

	for(int i=0;i<snew.length();i++)
	{
		if(snew[i]=='o') sum+=dp[i]*pp[i];
	}
	cout<<sum<<endl;
}		