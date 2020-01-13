//Author: AnandRaj anand873
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
#define test(t) int t;cin>>t;while(t--)
#define forn(i,a,b) for(int i=a;i<b;i++)
#define rforn(i,b,a) for(int i=b-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
 
const ll MOD = 1e9+7,MAX = 1e5+5;
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
	fastio
	int n,q;
	cin>>n>>q;
	vl A(n+2);
	take(A,1,n);
	if(A[1]>A[2]) A[0]=-MOD;
	else A[0]=MOD;
	if(A[n]>A[n-1]) A[n+1]=-MOD;
	else A[n+1]=MOD;
	set<int> PE;
	vi dd(n+2);
	for(int i=1;i<=n;i++)
	{
		if(A[i]>A[i-1]&&A[i]>A[i+1]) {dd[i+1]=dd[i]+1;PE.insert(i);}
		else if(A[i]<A[i-1]&&A[i]<A[i+1]) {dd[i+1]=dd[i]+1;PE.insert(i);}
		else dd[i+1]=dd[i];
	}
	//prin(dd);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int lp,rp;
		lp=dd[l];
		rp=dd[r+1];
		int tot=rp-lp;
		if(PE.count(l)==0) tot++;
		if(PE.count(r)==0) tot++;
		if(tot%2) printf("YES\n");
		else printf("NO\n");
	}
}