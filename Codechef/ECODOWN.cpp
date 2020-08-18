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

const ll MOD = 1e9+7,MAX = 1e5+5,MOD1 = MOD-1;
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

pll fib(ll n)
{
	if(n==0) return {0ll,1ll};

	auto p=fib(n/2);
	ll c=(p.first*((2*p.second-p.first+MOD1)%MOD1))%MOD1;
	ll d=((p.first*p.first)%MOD1+(p.second*p.second)%MOD1)%MOD1;
	if(n&1)
		return {d%MOD1,(c+d)%MOD1};
	else
		return {c%MOD1,d%MOD1};
}

int main()
{
	test()
	{
		ll p,q,n;
		cin>>p>>q>>n;
		if(n==0) cout<<p<<endl;
		else if(n==1) cout<<q<<endl;
		else
		{
			auto P=fib(n-1);
			ll ans1=powN(p+1,P.first);
			ll ans2=powN(q+1,P.second);
			ll ans=(ans1*ans2)%MOD;
			ans--;
			ans+=MOD;
			ans%=MOD;
			cout<<ans<<endl;
		}
		
	}
}		