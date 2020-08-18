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
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;
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
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	fastio
	test()
	{
		int n;
		cin>>n;
		vl A(n);
		take(A,0,n);
		if(n==1)
		{
			cout<<A[0]<<endl;
			continue;
		}
		vl PS(n+1);
		for(int i=1;i<=n;i++)
		{
			if(i%2)
			{
				PS[i]=PS[i-1]-A[i-1];
			}
			else PS[i]=PS[i-1]+A[i-1];
		}
		
		vi dpe(n+1);
		dpe[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(i%2==0) dpe[i]=dpe[i-1];
			else
			{
				if(PS[i]<PS[dpe[i-1]])
				{
					dpe[i]=i;
				}
				else dpe[i]=dpe[i-1];
			}
		}

		vi dpo(n+1);
		dpo[1]=0;
		for(int i=2;i<=n;i++)
		{
			if(i%2) dpo[i]=dpo[i-1];
			else
			{
				if(PS[i]<PS[dpo[i-1]])
				{
					dpo[i]=i;
				}
				else dpo[i]=dpo[i-1];
			}
		}
		// prin(dpe);
		// prin(dpo);
		ll maxdiff=0;
		// prin(PS);
		for(int i=n;i>0;i--)
		{
			if(i%2)
			{
				maxdiff=max(maxdiff,PS[i]-PS[dpe[i-1]]);
			}
			else
			{
				maxdiff=max(maxdiff,PS[i]-PS[dpo[i-1]]);
			}
		}

		ll curr=0;
		for(int i=0;i<n;i+=2) curr+=A[i];

		cout<<curr+maxdiff<<endl;

		
	}
}		