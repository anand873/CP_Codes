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
		set<int> S;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			S.insert(x);
		}
		for(auto s:S)
		{
			if(S.count(s+1)||S.count(s-1)) continue;
			else S.insert(s+1);
		}
		cout<<S.size()-n<<endl;
	}
}