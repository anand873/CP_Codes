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
		vector<ll> A(n+1);
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		A[n]=-1;
		map<ll,int> M;
		set<ll> S;
		for(int i=0;i<n;i++)
		{
			if(S.count(A[i])==0)
			{
				S.insert(A[i]);
				M.insert({A[i],1});
			}
			else M[A[i]]++;
			int j=i+1;
			while(A[j]==A[i])
			{
				j++;
			}
			i=j-1;
		}
		ll sum=0;
		int ma=0;
		for(auto s:S)
		{
			sum+=M[s];
			ma=max(M[s],ma);
		}
		cout<<sum-ma<<endl;
	}
}