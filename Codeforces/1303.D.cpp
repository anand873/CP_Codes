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
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
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
		ll n,m;
		cin>>n>>m;
		vl A(m+1);
		take(A,1,m);
		ll sum=0;
		for(int i=1;i<=m;i++)
		{
			sum+=A[i];
		}
		if(sum<n) cout<<-1<<endl;
		else
		{
			vector<int> HOW(40);
			for(int i=1;i<=m;i++)
			{
				for(ll j=0;j<40;j++)
				{
					if((A[i]>>j)&1) {HOW[i]=j;break;} 
				} 
			}
			vector<int> NUM(61);
			for(ll i=0;i<61;i++)
			{
				if((n>>i)&1) NUM[i]=1;
			}
			for(int i=0;i<61;i++)
			{
				if(NUM[i]==1)
				{
					ll ding=1ll<<i;
					ll bing=ding;
					for(int j=i-1;j>=0&&bing;j--)
					{
						if(bing>=HOW[j]*(1ll<<j))
						{
							bing-=HOW[j]*(1ll<<j);
							HOW[j]=0;
						}
						else
						{
							ll cing=bing;
							bing%=HOW[j];
							HOW[j]-=cing/HOW[j];
						}
					}
					if(bing==0) continue;
					else
					{
						for(int j=i+1;j<61;j++)
						{
							if(NUM[i])
						}
					}
				}
				else
				{

				}
			}	
		}
	}
}		