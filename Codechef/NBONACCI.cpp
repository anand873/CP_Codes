//Author: AnandRaj anand873
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
#define forn(i,a,b) for(int i=a;i<b;i++)
#define rforn(i,b,a) for(int i=b-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl;

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
	fastio
	int n,q;
	cin>>n>>q;
	vector<int> F;
	ll xo=0;
	for(int i=0;i<n;i++)
	{
		ll f;
		cin>>f;
		xo^=f;
		F.push_back(f);
	}
	F.push_back(xo);
	vector<ll> S(n+1);
	for(int i=1;i<=n;i++)
	{
		S[i]=S[i-1]^F[(i-1)%n];
	}
	//prin(S);
	while(q--)
	{
		int x;
		cin>>x;
		cout<<S[x%(n+1)]<<endl;
	}

}