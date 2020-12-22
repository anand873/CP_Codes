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

const int MOD = 1e9+7,MAX = 1e7+5;
const ll INF = 1e18+5;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vl F(MAX),I(MAX);

ll C(int n,int r)
{
	return (((F[n]*I[r])%MOD)*I[n-r])%MOD;
}

int main()
{
	int n,m;
	cin>>n>>m;
	F[0]=I[0]=1;
	F.resize(m+1);
	I.resize(n+1);
	for(ll i=1;i<=m;i++)
	{
		F[i]=(F[i-1]*i)%MOD;
		I[i]=powN(F[i],MOD-2);
	}	
	ll inv = powN(m-1,MOD-2);
	ll ans = powN(m-1,n);

	for(int i=2;i<=n;i++)
	{
		int sign = 2*(i%2)-1;
		
		ll temp = C(n,i);
		temp*= (m-i);
		temp%=MOD;
		temp*=powN(m-1,n-i);
		temp%=MOD;
		ans+=sign*temp;
		ans%=MOD;
		if(ans<0)
			ans+=MOD;
	}

	ans*=C(m,n);
	ans%=MOD;
	ans*=F[n];
	ans%=MOD;

	cout<<ans<<endl;
}		