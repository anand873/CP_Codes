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
		ll n;
		cin>>n;
		ll sum1=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				sum1+=i|j;
				sum1%=MOD;
			}
		}
		//cout<<sum1<<endl;

		ll sum=0;
		int bits=0;
		ll ding=n;
		while(bits<33)
		{
			ll x = (n/powN(2,bits+1))*powN(2,bits);
			ll y = (n%(ll)powN(2,bits+1))+1;
			y-=powN(2,bits);
			if(y<=0) y=0;
			//what(x);
			x+=y;
			//what(x);
			x=x*(2*n-x);
			ll ones = ((x)%MOD);
			//ll tot = ((n*n)%MOD)
			sum+=(ones*powN(2,bits))%MOD;
			sum%=MOD;
			bits++;
		}
		//cout<<sum<<endl;

		if(sum!=sum1) cout<<"Wrong on N = "<<n<<endl;
		else cout<<"Good"<<endl;
	}
	
}