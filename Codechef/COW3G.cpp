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
#define test() int _;cin>>_;while(_--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int _=f;_<f+n;_++) cin>>V[_]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

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
}
//////////////////Sieve////////////////////

ll __lcm(int a,int b)
{
	return (ll)(a/__gcd(a,b))*b;
}

int main()
{
	Sieve();
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	sort(all(A));
	set<int> S;
	int candi=n-1;
	ll lastma=A[n-1];
	while(S.count(candi)==0)
	{
		ll ma=0;
		S.insert(candi);
		for(int i=0;i<n;i++)
		{
			if(i==candi) continue;
			ll lcm=__lcm(A[i],A[candi]);
			if(lcm>ma)
			{
				ma=lcm;
				candi=i;
			}
		}
		if(ma>lastma)
		{
			lastma=ma;
		}
		else break;
	}
	cout<<lastma<<endl;
	
}		