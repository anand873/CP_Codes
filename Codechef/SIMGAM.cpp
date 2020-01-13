#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
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
		int C[n];
		int i;
		vvi A(n);
		forn(i,n)
		{
			cin>>C[i];
			int j;
			A[i].resize(C[i]);
			forn(j,C[i])
			{
				cin>>A[i][j];
			}
		}
		ll sum=0;
		vi X;
		forn(i,n)
		{
			int j;
			forn(j,C[i]/2) sum+=A[i][j];
			if(C[i]%2) X.push_back(A[i][C[i]/2]);
			//cout<<sum<<endl;  
		}
		sort(all(X));
		while(X.size()>1)
		{
			sum+=X.back();
			X.pop_back();
			X.pop_back();
		}
		if(X.size()==1) sum+=X.back();
		cout<<sum<<endl;
	}
}