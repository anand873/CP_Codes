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

const int MOD = 998244353,MAX = 1e6+5;
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
	int n;
	cin>>n;
	vl A(n);
	ll ans=0;
	take(A,0,n);
	sort(all(A));

	vi Dig(11);
	for(int i=0;i<n;i++)
	{
		int dig=0;
		ll pos = 1;
		ll fakeA = A[i];
		while(A[i])
		{
			dig++;
			ans+=((((((A[i]%10)*11)%MOD)*pos)%MOD)*(n-i))%MOD;
			ans%=MOD;
			A[i]/=10;
			pos*=100;
			pos%=MOD;
		}
		for(int d = 1; d <= dig; d++)
		{
			int how = Dig[d];
			ll pos = 1;
			ll aa = fakeA;
			for(int x = 1;x <= d; x++)
			{
				ans+=((((((aa%10)*11)%MOD)*pos)%MOD)*how)%MOD;
				ans%=MOD;
				aa/=10;
				pos*=100;
				pos%=MOD;
			}
			ans+=(((((aa*powN(10,2*d))%MOD)*how)%MOD)*2)%MOD;
			ans%=MOD;
		}
		Dig[dig]++;
	}
	//prin(Dig);
	cout<<ans<<endl;
}		