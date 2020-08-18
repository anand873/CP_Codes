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

const int MOD = 1e9+7,MAX = 1e6+5;
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
		ll n,p;
		cin>>n>>p;
		vi K(n);
		take(K,0,n);
		sort(all(K));
		vi H(K[n-1]+1);
		for(auto k:K) H[k]++;
		ll bias = 0;
		int done=0;
		for(int k = K[n-1];k>=0;k--)
		{
			done+=H[k];
			H[k]%=2;
			bias+=H[k]*powN(p,k);
			bias%=MOD;
			if(H[k])
			{
				ll howfar = p;
				for(int next = k-1;next>=0;next--)
				{
					if(H[next]>=howfar)
					{
						bias = (bias - (H[next]*powN(p,next))%MOD+MOD)%MOD;
						done+=H[next];
						H[next]-=howfar;
						break;
					}
					else
					{
						howfar = max(n,(howfar-H[next])*p);
					} 
				}
			}
		}
		cout<<bias<<endl;
	}
}		