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

const int MOD = 1e9+7,MAX = 2e5+5;
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
/*

	First complete all the "Wow", Then all "Ok". Then rest can be same.

	//Manage Corner Cases//

*/

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	vi t(n);
	t[0]=1;
	int last=1;
	if(b==0)
	{
		if(n==1) {prin(t);return 0;}
		if(a==n-1) {cout<<-1<<endl;return 0;}
		t[1]=1;
		for(int i=2;i<=a+1;i++) t[i]=t[i-1]+1;
		for(int i=a+2;i<n;i++) t[i]=t[i-1];
		prin(t);
		return 0;
	}
	for(int i=1;i<=b;i++)
	{
		t[i]=last+1;
		last+=t[i];
	}
	for(int i=b+1;i<=a+b;i++)
	{
		t[i]=t[i-1]+1;
	}
	for(int i=a+b+1;i<n;i++)
	{
		t[i]=t[i-1];
	}
	prin(t);
}		