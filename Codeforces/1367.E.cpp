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
ll powN(ll a,ll p,ll mod)
{
	if(p==0) return 1;
	ll z=powN(a,p/2,mod);
	z=(z*z)%mod;
	if(p%2) z=(z*a)%mod;
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
	test()
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		vi H(26);
		for(auto c:s) H[c-'a']++;

		sort(all(H));
		reverse(all(H));
		// prin(H);
		int curr=0;
		set<int> D;
		for(int i=1;i*i<=k;i++)
		{
			if(k%i==0)
			{
				D.insert(i);
				D.insert(k/i);
			}
		}
		int ans = 1;
		for(auto d:D)
		{
			for(int div = H[0];div>=1;div--)
			{
				int sum=0;
				for(int i=0;i<26;i++)
				{
					sum+=H[i]/div;
				}
				// cout<<d<<" "<<sum<<" "<<div<<endl;
				if(sum>=d) ans=max(ans,div*min(d,sum));
			}
		}
		cout<<ans<<endl;
	}

}		