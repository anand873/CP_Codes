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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAX = 1e6+5;
const ll INF = 1e18+5;
int MOD = 1e9+7;
/////////////////FastExp///////////////////
ll powN(ll a,ll p,int bit)
{
	if(p==0) return 1;
	ll z=powN(a,p/2,bit);
	z=(z*z)%bit;
	if(p%2) z=(z*a)%bit;
	return z;
}
/////////////////FastExp///////////////////
///////////////////PnC/////////////////////
// vl Fac(MAX),Inv(MAX);
// void CalcFac()
// {
// 	Fac[0]=Inv[0]=1;
// 	for(int i=1;i<MAX;i++)
// 	{
// 		Fac[i]=(Fac[i-1]*i)%MOD;
// 		Inv[i]=powN(Fac[i],MOD-2);
// 	}
// }

// ll NCR(int n,int r)
// {
// 	if(r>n) return 0;
// 	return (((Fac[n]*Inv[r])%MOD)*Inv[n-r])%MOD;
// }
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

int main()
{
	int n;
	cin>>n;
	string X;
	cin>>X;
	int bit=0;
	for(auto x:X) bit+=(x=='1');
	int bit2=bit-1;

	if(bit==0)
	{
		for(int i=0;i<n;i++)
		{
			cout<<1<<endl;
		}
		return 0;
	}
	else if(bit==1)
	{
		if(X[n-1]=='1')
		{
			for(int i=0;i<n;i++)
			{
				if(X[i]=='0')
				{
					cout<<2<<endl;
				}
				else cout<<0<<endl;
			}
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(i==n-1)
				{
					cout<<2<<endl;
				}
				else if(X[i]=='0')
				{
					cout<<1<<endl;
				}
				else cout<<0<<endl;
			}
		}
		return 0;
	}


	bit++;
	int curr=1,curr2=1;
	int NAO=0,MNAO=0;
	for(int i=n-1;i>=0;i--)
	{
		if(X[i]=='1')
		{
			NAO+=curr%bit;
			NAO%=bit;

			MNAO+=curr2%bit2;
			MNAO%=bit2;
		}
		curr*=2;
		curr%=bit;

		curr2*=2;
		curr2%=bit2;
	}
	// cout<<NAO<<endl;
	// cout<<MNAO<<endl;
	for(int i=0;i<n;i++)
	{
		int FN;
		if(X[i]=='0')
		{
			FN = NAO;
			int ex = powN(2ll,(ll)n-i-1,bit);
			FN+=ex;
			FN%=bit;
		}
		else
		{
			FN = MNAO;
			int ex = powN(2ll,(ll)n-i-1,bit2);
			FN-=ex;
			FN%=bit2;
			if(FN<0) FN+=bit2;
		}

		int step = 1;
		while(FN)
		{
			int bitcnt = __builtin_popcount(FN);
			FN%=bitcnt;
			step++;
		}
		cout<<step<<endl;
	}
}	