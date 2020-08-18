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
#define forn(f,n) for(int i=f;i<f+n;i++)
#define rforn(l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i];
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
	int h,w;
	cin>>h>>w;
	vvi M(h+5,vi(w+5));
	for(int i=1;i<=h;i++)
	{
		int r;
		cin>>r;
		for(int j=1;j<=r;j++)
		{
			M[i][j]=1;
		}
		M[i][r+1]=-1;
	}
	bool ans=true;
	for(int j=1;j<=w;j++)
	{
		int c;
		cin>>c;
		for(int i=1;i<=c;i++)
		{
			if(M[i][j]!=-1)
				M[i][j]=1;
			else ans=false;
		}
		if(M[c+1][j]!=1)
			M[c+1][j]=-1;
		else ans=false;
	}
	int ding=0;
	if(!ans) {cout<<0<<endl;return 0;}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(M[i][j]==0) ding++;
		}
	}
	cout<<powN(2,ding)<<endl;
}		