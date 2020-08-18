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

const int MOD = 998244353,MAX = 5e5+5;
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

	int n,m;
	cin>>n>>m;
	vl A(n);
	take(A,0,n);
	vl B(m);
	take(B,0,m);

	map<ll,int> L;
	map<ll,int> F;

	for(int i=0;i<n;i++)
	{
		L[A[i]]=i;
		if(F.find(A[i])==F.end()) F[A[i]]=i;
	}

	ll ans=1;
	ll mi=2*MOD;

	if(L.find(B[0])==L.end())
	{
		cout<<0<<endl;
		// cout<<"1"<<endl;
		return 0;
	}
	for(int i=0;i<=L[B[0]];i++)
	{
		mi = min(mi,A[i]);
	}

	if(mi==B[0])
	{
		int curr=L[B[0]];
		for(int i=1;i<m;i++)
		{
			if(L.find(B[i])==L.end())
			{
				cout<<0<<endl;
				// cout<<"2"<<endl;
				return 0;
			}
			int maxr=L[B[i-1]];
			int maxl=L[B[i]];
			if(maxl<curr)
			{
				cout<<0<<endl;
				// cout<<"3"<<endl;
				return 0;
			}
			while(maxr<L[B[i]]&&A[maxr]>=B[i-1]) maxr++;
			maxr--;
			while(maxl>L[B[i-1]]&&A[maxl]>=B[i]) maxl--;
			maxl++;

			if(maxr<maxl-1)
			{
				cout<<0<<endl;
				// cout<<"4"<<endl;
				return 0;
			}
			else
			{
				// cout<<maxr<<" "<<maxl<<endl;
				ans*=(maxr-maxl+2);
				ans%=MOD;
			}
		}
		mi=2*MOD;
		for(int i=L[B[m-1]];i<n;i++)
		{
			mi=min(mi,A[i]);
		}
		if(mi==B[m-1])
		{
			cout<<ans<<endl;
			// cout<<"5"<<endl;
			return 0;
		}
		else
		{
			cout<<0<<endl;
			// cout<<"6"<<endl;
			return 0;
		}

	}
	else
	{
		cout<<0<<endl;
		// cout<<"7"<<endl;
		return 0;
	}
	


}		