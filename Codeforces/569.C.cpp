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

const int MOD = 1e9+7,MAX = 2e6+5;
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
	Easy Problem. Just check every number upto MAX.

	!!!Very Important!!!
	It's the MAXIMUM N upto which the identity is correct
	NOT the MINIMUM N for which it is wrong. 

*/

bool pal(int i)
{
	//**Use String Conversion And Then Check**//

	string s=to_string(i);
	for(int i=0;i<s.size();i++) if(s[i]!=s[s.size()-i-1]) return false;
	return true;
}

int main()
{
	ll p,q;
	cin>>p>>q;
	Sieve();
	int pc=0,rc=0;
	int ans=0;
	for(int i=1;i<MAX;i++)
	{
		if(is_prime[i]) pc++;
		if(pal(i)) rc++;
		if(q*pc<=p*rc) ans=i;
	}
	if(ans) cout<<ans<<endl;
	else cout<<"Palindromic tree is better than splay tree"<<endl;
}		