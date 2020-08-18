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
		int n,m,k;
		cin>>n>>m>>k;
		vi A(n+1);
		take(A,1,n);
		int i=1,j=n;
		int bribe=0;
		int ma=0;
		if(k>=m-1)
		{
			for(int i=1;i<=n;i++) ma=max(ma,A[i]);
			cout<<ma<<endl;
		}
		else
		{
			multiset<int> S;
			for(int i=1;i+n-m-1<=n;i++)
			{
				S.insert(A[i]);
			}
			int mi=*S.rbegin();
			for(int i=2;i+n-m-1<=n;i++)
			{
				S.erase(S.find(A[i-1]));
				S.insert(A[i+n-k-1]);
				ma=min(mi,*S.rbegin());
			}
			set<int> GONE;
			S.clear();
			for(int i=1;i+n-m-1<=n;i++)
			{
				S.insert(A[i]);
			}
			for(int i=2;i+n-m-1<=n;i++)
			{
				S.erase(S.find(A[i-1]));
				S.insert(A[i+n-k-1]);
				if(*S.rbegin()==mi)
				{
					for(int j=i;j<=i+n-m-1;j++)
						GONE.insert(j);
					break;
				}
			}
			S.clear();
			while(S.size()!=m-k)
			ma=*S.begin();
			for(int i=2;i+n-k-1<=n;i++)
			{
				S.erase(S.find(A[i-1]));
				S.insert(A[i+n-k-1]);
				ma=max(ma,*S.begin());
			}
			cout<<ma<<endl;
		}
	}
}		