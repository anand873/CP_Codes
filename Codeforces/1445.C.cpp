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
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e18+5;
const int MAX = 1e6+5;
const ll INF = 1e18+5;

vector<bool> is_prime(MAX+1, true);
vi MinDiv(MAX+1);
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

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}

int main()
{
	test()
	{
		ll p,q;
		cin>>p>>q;
		if(p%q!=0||p<q)
		{
			cout<<p<<endl;
		}
		else
		{
			map<int,int> M;
			ll temp = q;
			for(int i=2;i*i<=q;i++)
			{
				if(is_prime[i]&&temp%i==0)
				{
					while(temp%i==0)
					{
						M[i]++;
						temp/=i;
					}
				}
			}
			if(temp!=1) M[temp]++;
			ll ans = 1;
			for(auto s:M)
			{
				ll val=p;
				while(val%s.first==0)
				{
					val/=s.first;
				}
				val*=powN(s.first,s.second-1);
				if(val%q)
				{
					ans = max(ans,val);
				}
			}
			cout<<ans<<endl;
		}
	}
}	