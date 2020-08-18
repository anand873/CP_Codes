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
set<int> S;
vi X(MAX);
bool check(int i)
{
	int fir=X[i];
	int sec=X[i+1];
	if(fir>sec) swap(fir,sec);
	for(auto in:S)
	{
		int fir1=X[in];
		int sec1=X[in+1];
		if(fir1>sec1) swap(fir1,sec1);

		if(fir<fir1&&sec<sec1&&sec>fir1) return false;
		if(fir>fir1&&sec>sec1&&sec1>fir) return false;

	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	int maxreach=0;
	X.resize(n);
	take(X,0,n);
	bool ans=true;
	for(int i=0;i<n-1;i++)
	{
		if(check(i)) S.insert(i);
		else {ans=false;break;}
	}
	if(!ans) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}		