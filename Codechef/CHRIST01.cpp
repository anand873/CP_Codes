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

const int MOD = 1e9+7,MAX = 260005;
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

vl F(MAX),I(MAX);

ll C(ll n,ll r)
{
	if(r>n) return 0;
	else
	{
		return (((F[n]*I[r])%MOD)*I[n-r])%MOD;
	}
}

int main()
{
	F[0]=1;
	I[0]=1;
	for(ll i=1;i<MAX;i++)
	{
		F[i]=(i*F[i-1])%MOD;
		I[i]=powN(F[i],MOD-2);
	} 

	test()
	{
		int n,k;
		//n=2;
		//k=100-t;
		cin>>n>>k;
		ll sum=0;
		vl PK(n+1),In(n+1);
		PK[0]=1;
		In[0]=1;
		for(int i=1;i<=n;i++)
		{
			PK[i]=(PK[i-1]*F[k])%MOD;
			In[i]=powN(PK[i],MOD-2);
		}
		//prin(In);
		for(int i=1;i<=n;i++)
		{
			ll coe = C(n,i);
			ll num = F[(n-i)*k+i];
			ll den = In[n-i];
			//what((num*den)%MOD);
			if(i%2)
			{
				sum+=(((num*den)%MOD)*coe)%MOD;
				sum%=MOD;
			}
			else
			{
				sum-=(((num*den)%MOD)*coe)%MOD;
				sum+=MOD;
				sum%=MOD;
			}
		}
		cout<<sum<<endl;
	}
}		