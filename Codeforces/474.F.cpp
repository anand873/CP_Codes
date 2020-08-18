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

vi S(MAX);
vi H(4*MAX);
int n;
void make_tree(int i)
{
	if(i>=2*n) return;
	if(i>=n)
	{
		H[i]=S[i-n];
		return;
	}
	make_tree(2*i);
	make_tree(2*i+1);
	H[i]=__gcd(H[2*i],H[2*i+1]);
}


int gcd(int l, int r)
{
	l+=n;
	r+=n;
	int g=0;
	while(l<=r)
	{
		if(l%2)
		{
			g=__gcd(g,H[l++]);
		}
		if(r%2==0)
		{
			g=__gcd(g,H[r--]);
		}
		l/=2;
		r/=2;
	}
	return g;
}

int main()
{
	fastio;
	cin>>n;
	S.resize(n);
	take(S,0,n);
	H.resize(n+1);
	int t;
	cin>>t;
	vector<pii> N;
	for(int i=0;i<n;i++)
	{
		N.push_back({S[i],i});
	}
	sort(all(N));
	make_tree(1);
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		l--;r--;
		int g=gcd(l,r);

		pii X = {g,l};
		auto from = lower_bound(all(N),X);
		pii Y = {g,r+1};
		auto to = lower_bound(all(N),Y);
		int how=to-from;
		cout<<r-l+1-how<<endl;
	}
}		