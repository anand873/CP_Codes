//Author: Anand Raj (doubleux)
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

const int MOD = 1e9+7,MAX = 2e5+5;
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
	test()
	{
		int n;
		cin>>n;
		vi T(n+1),C(n+1);
		take(T,1,n);
		bool same=true;
		for(int i=1;i<n;i++)
		{
			if(T[i]!=T[i+1]) same=false;
		}
		if(same)
		{
			cout<<1<<endl;
			for(int i=1;i<=n;i++) cout<<1<<" ";
			cout<<endl;
		}
		else
		{
			if(n%2==0)
			{
				cout<<2<<endl;
				for(int i=1;i<=n;i++)
				{
					cout<<1+i%2<<" ";
				}
				cout<<endl;
			}
			else
			{
				int can=0;
				bool done=false;
				for(int i=1;i<n;i++)
				{
					if(T[i]==T[i+1]) can=i;
				}
				if(T[1]==T[n]) can=n;
				if(can)
				{
					cout<<2<<endl;
					for(int i=1;i<=can;i++)
					{
						cout<<1+i%2<<" ";
					}
					for(int i=can+1;i<=n;i++)
					{
						cout<<1+(i-1)%2<<" ";
					}
					cout<<endl;
					
				}
				else
				{
					cout<<3<<endl;
					cout<<3<<" ";
					for(int i=2;i<=n;i++)
					{
						cout<<1+i%2<<" ";
					}
					cout<<endl;
				}
			}
		}
	}
}		