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
	int n;
	cin>>n;
	vl P(n+1);
	take(P,1,n);
	vector<int> NU(n+2);
	for(int i=1;i<=n;i++)
	{
		if(((n+1)/i)%2==0)
		{
			int x=(n+1)%i;
			NU[0]++;
			NU[x]--;
		}
		else
		{
			int x=(n+1)%i;
			NU[x]++;
			NU[i]--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		NU[i]+=NU[i-1];
	}
	//prin(NU);
	for(int i=0;i<n;i++)
	{
		NU[i]%=2;
	}
	ll Q=0;
	for(int i=1;i<=n;i++)
	{
		Q^=P[i];
	}
	//cout<<Q<<endl;
	for(long long int i=0;i<n;i++)
	{
		if(NU[i]) Q^=i;
	}
	cout<<Q<<endl;
}