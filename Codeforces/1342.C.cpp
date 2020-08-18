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

const int MOD = 998244353,MAX = 1e5+5;
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
/*
	
	If a<b then,
	Any number X, between b and lcm-1 satisfies (X%a)%b!=(X%b)%a
	Therefore there are lcm-b total good numbers.

	Rest is usual technique plus manage some extras.


*/
int main()
{
	test()
	{
		ll a,b,q;
		cin>>a>>b>>q;
		if(a>b) swap(a,b);
		ll LCM=a*b/__gcd(a,b);
		ll how=LCM-b;
		vector<ll> Ans;
		while(q--)
		{
			ll l,r;
			cin>>l>>r;
			ll x1=((l-1)/LCM)*how;
			ll final1=(l-1)%LCM;
			x1+=max(0ll,final1-b+1);

			ll x2=((r)/LCM)*how;
			ll final2=(r)%LCM;
			x2+=max(0ll,final2-b+1);
			Ans.push_back(x2-x1);
		}
		for(auto a:Ans)
		{
			printf("%lld ",a);
		}
		printf("\n");

	}
}		