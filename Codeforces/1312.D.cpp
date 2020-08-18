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

const ll MOD = 998244353,MAX = 200005;
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

vl F(MAX+5);
vl I(MAX+5);
ll C(ll n,ll m)
{
	if(m>n) return 0;
	return (((F[n]*I[m])%MOD)*I[n-m])%MOD;
}

int main()
{	
	
	ll n,m;
	cin>>n>>m;
	F[0]=F[1]=1;
	for(ll i=2;i<MAX;i++) F[i]=(i*F[i-1])%MOD;
	for(ll i=0;i<MAX;i++) I[i]=powN(F[i],MOD-2);
	ll ans=C(m,n-1);
	if(n==2) cout<<0<<endl;
	else if(n==3)
	{
		cout<<ans<<endl;
	}
	else
	{
		ans*=(n-2);
		ans%=MOD;
		ans*=powN(2ll,n-3);
		ans%=MOD;
		cout<<ans<<endl;
	}
	

}		