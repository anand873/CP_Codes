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

const int MOD = 998244353,MAX = 4e7+5;
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

int main()
{
	Sieve();
	vl F(100),I(100);
	F[0]=I[0]=1;
	for(ll i=1;i<100;i++)
	{
		F[i]=(i*F[i-1])%MOD;
		I[i]=powN(F[i],MOD-2);
	}
	ll D;
	cin>>D;
	int q;
	cin>>q;
	vector<ll> Div;
	for(ll i=2;i*i<=D;i++)
	{
		if(D%i==0)
		{
			Div.push_back(i);
			while(D%i==0)
			{
				D/=i;
			}
		}
	}
	if(D!=1) Div.push_back(D);
	sort(all(Div));
	//cout<<Div.size()<<endl;
	
	while(q--)
	{
		ll u,v;
		cin>>u>>v;
		ll hcf=__gcd(u,v);
		ll fir=u/hcf;
		ll sec=v/hcf;
		ll ans=1;
		int tothow1=0,tothow2=0;
		ll fakefir=fir,fakesec=sec;
		//cout<<"Done1"<<endl;
		for(auto i:Div)
		{
			if(i==1) continue;
			int how1=0;
			if(fakefir%i==0)
			{
				while(fakefir%i==0)
				{
					fakefir/=i;
					how1++;
				}
				tothow1+=how1;
				ans*=I[how1];
				ans%=MOD;
			} 
		}
		if(fakefir!=1)
		{
			tothow1++;
		}
		//cout<<"Done2"<<endl;
		for(auto i:Div)
		{
			if(i==1) continue;
			//if(!is_prime[i]) continue;
			int how2=0;
			if(fakesec%i==0)
			{
				while(fakesec%i==0)
				{
					fakesec/=i;
					how2++;
				}
				tothow2+=how2;
				ans*=I[how2];
				ans%=MOD;
			} 
		}
		if(fakesec!=1)
		{
			tothow2++;
		}
		//cout<<"Here1"<<endl;
		ans*=F[tothow1];
		ans%=MOD;
		//cout<<"Here2"<<endl;
		ans*=F[tothow2];
		ans%=MOD;
		//cout<<"Here3"<<endl;
		printf("%lld\n",ans);
	}
}		