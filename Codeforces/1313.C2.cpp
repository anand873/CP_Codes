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
#define forn(f,n) for(int i=f;i<f+n;i++)
#define rforn(l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
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
            	is_prime[j] = false;
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{	
	int n;
	cin>>n;
	vl A(n);
	take(A,0,n);
	vl Sum(n+1);
	for(int i=1;i<=n;i++)
	{
		Sum[i]=Sum[i-1]+A[i-1];
	}
	vi Mi;
	vi mib(n),mif(n);
	mib[0]=A[0];
	mif[n-1]=A[n-1];
	for(int i=1;i<n;i++)
	{
		mib[i]=min(mib[i-1],A[i]);
	}
	for(int i=n-2;i>=0;i--)
	{
		mif[i]=min(mif[i+1],A[i]);
	}

	if(A[0]<=A[1]) Mi.push_back(0);
	for(int i=1;i<n-1;i++)
	{
		if(A[i]<=A[i-1]&&A[i]<=A[i+1]) Mi.push_back(i);
	}
	if(A[n-1]<=A[n-2]) Mi.push_back(n-1);

	ll how=0;
	for(int i=0;i<Mi.size()-1;i++)
	{
		ll ding=0;
		ding=Sum[Mi[i+1]+1]-Sum[Mi[i]]+mib[Mi[i]]*(Mi[i]-1)+mif[Mi[i+1]]*(Mi[i+1]-1);
		if(ding>=how)
		{
			how=ding;
			ans=i;
		}
	}
}		