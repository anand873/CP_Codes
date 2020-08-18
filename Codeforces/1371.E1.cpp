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
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 100+5;
const ll INF = 1e18+5;
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
///////////////////PnC/////////////////////
vl Fac(MAX),Inv(MAX);
void CalcFac(int mod)
{
	Fac[0]=Inv[0]=1;
	for(int i=1;i<MAX;i++)
	{
		Fac[i]=(Fac[i-1]*i)%mod;
		Inv[i]=powN(Fac[i],mod-2,mod);
	}
}

ll NCR(int n,int r,int mod)
{
	if(r>n) return 0;
	return (((Fac[n]*Inv[r])%mod)*Inv[n-r])%mod;
}
///////////////////PnC/////////////////////
//////////////////Sieve////////////////////
vector<bool> is_prime(MAX, true);
vi MinDiv(MAX);
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	fastio
	int n,p;
	cin>>n>>p;
	vi A(n);
	take(A,0,n);
	sort(all(A));

	int minx=0,maxx=A[n-1];
	for(int i=0;i<n;i++)
	{
		minx=max(minx,A[i]-i);
	}
	int t = minx-1;
	int low=minx,high=maxx-1;
	while(low<=high)
	{
		int x=low+(high-low)/2;
		map<int,int> M;
		ll ans=1;
		int can=0;
		for(int i=0;i<n;i++)
		{
			M[A[i]]++;
			if(A[i]<x) can++;
		}
		for(int pos=0;pos<n;pos++)
		{
			can+=M[x+pos];
			ans*=can;
			can--;
			ans%=p;
		}
		if(ans)
		{
			t=x;
			low=x+1;
		}
		else 
		{
			high=x-1;
		}
	}
	if(t<minx)
	{
		cout<<0<<endl;
	}
	else
	{
		cout<<t-minx+1<<endl;
		for(int i=minx;i<=t;i++) cout<<i<<" ";
		cout<<endl;
	}
		


}	