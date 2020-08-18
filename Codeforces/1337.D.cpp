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

const ll MOD = 2e18+7,MAX = 2e5+5;
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

ll f(ll x, ll y, ll z)
{
	return (x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z);
}

int main()
{
	test()
	{
		ll nr,ng,nb;
		cin>>nr>>ng>>nb;
		set<ll> M[3];
		for(int i=0;i<nr;i++)
		{
			ll x;
			cin>>x;
			M[0].insert(x);
		}
		for(int i=0;i<ng;i++)
		{
			ll x;
			cin>>x;
			M[1].insert(x);
		}
		for(int i=0;i<nb;i++)
		{
			ll x;
			cin>>x;
			M[2].insert(x);
		}


		ll ans=MOD;

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					if(i==j||j==k||k==i) continue;
					for(auto x:M[i])
					{
						auto it1=M[j].lower_bound(x);
						auto it2=M[k].upper_bound(x);

						if(it1!=M[j].end()&&it2!=M[k].begin())
						{
							ll y=*it1;
							it2--;
							ll z=*it2;
							ans=min(ans,f(x,y,z));
						}
					}
				}
			}
		}
		

		cout<<ans<<endl;
	}
}		