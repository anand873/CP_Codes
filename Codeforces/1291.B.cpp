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
	test(t)
	{
		int n;
		cin>>n;
		vi A(n+1);
		take(A,1,n);
		vi BA(n+5),CH(n+5);
		if(A[1]>=0) BA[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(A[i]>=i-1) BA[i]=BA[i-1]+1;
			else BA[i]=BA[i-1];
		}
		if(A[n]>=0) CH[n]=1;
		for(int i=n-1;i>0;i--)
		{
			if(A[i]>=n-i) CH[i]=CH[i+1]+1;
			else CH[i]=CH[i+1];
		}
		bool ans=false;
		for(int i=1;i<=n;i++)
		{
			if(BA[i-1]==i-1&&CH[i+1]==n-i&&A[i]>=i-1&&A[i]>=n-i) ans=true;
		}
		cout<<(ans?"Yes":"No")<<endl;
	}
}		