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

#define test(t) int t;cin>>t;while(t--)
#define forn(i,n) for(i=0;i<n;i++)
#define rforn(i,n) for(i=n-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
const int MOD = 1e9+7,MAX = 1e5+5;
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
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
ll modInv(ll a)
{
	return powN(a,MOD-2);
}


int main()
{
	test(t)
	{
		int n;
		cin>>n;
		vl H(n),X(n);
		int i;
		for(i=0;i<n;i++) cin>>X[i]>>H[i];
		for(i=0;i<n-1;i++)
		{
			X[i]=X[i+1]-X[i];
		}
		X.pop_back();
		sort(all(H));
		vi Y;
		Y.push_back(X[0]);
		for(i=0;i<n-2;i++)
		{
			Y.push_back(X[i]+X[i+1]);
		}
		Y.push_back(X[n-2]);
		sort(all(Y));
		ll sum=0;
		for(i=0;i<n;i++)
		{
			sum+=H[i]*Y[i];
		}
		cout<<sum<<endl;
	}
}