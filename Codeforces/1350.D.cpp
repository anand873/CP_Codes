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
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
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
}
//////////////////Sieve////////////////////

int main()
{
	test()
	{
		int n,k;
		cin>>n>>k;
		vl A(n);
		take(A,0,n);
		bool khai=false;
		for(int i=0;i<n;i++)
		{
			if(A[i]==k) {khai=true;break;}
		}
		if(!khai) cout<<"no"<<endl;
		else
		{
			if(n==1) {cout<<"yes"<<endl;continue;}
			bool kbig=false;
			for(int i=0;i<n;i++)
			{
				if(A[i]>=k) A[i]=1;
				else A[i]=0;
			}
			bool med=false;
			for(int i=0;i<n-1;i++)
			{
				if(A[i]==1&&A[i+1]==1) {med=true;break;}
			}
			if(med) cout<<"yes"<<endl;
			else
			{
				for(int i=0;i<n-2;i++)
				{
					int x=A[i]+A[i+1]+A[i+2];
					if(x>1) {med=true;break;}
				}
				if(med) cout<<"yes"<<endl;
				else cout<<"no"<<endl;
			}
		}

	}
}		