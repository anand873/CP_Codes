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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	test()
	{
		ll n;
		ll l,r;
		cin>>n>>l>>r;
		ll st=n-1;
		for(ll k=1;k<=n;k++)
		{
			if((n*2-k-1)*k>=l)
			{
				//cout<<(n*2-k-1)*k<<endl;
				st=k-1;
				break;
			}
		}
		ll ex=(2*n-st-1)*(st);
		l-=ex;
		r-=ex;
		st++;
		//what(st);
		//what(ex);
		vector<int> V={0};
		ll some=st+1;
		ll tot=0;
		for(int i=1;i<=r;i++)
		{
			if(st==n) {V.push_back(1);break;}
			if(i%2) V.push_back(st);
			else {V.push_back(some);some++;}
			if(i==tot+2*(n-st)) {tot+=2*(n-st);st++;some=st+1;}
		}
		for(int i=l;i<=r;i++)
		{
			printf("%d ",V[i]);
		}
		cout<<endl;
	}
}		