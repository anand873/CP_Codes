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
#define test(t) int t;cin>>t;while(t--)
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl

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
	test(t)
	{
		ll n,k,d1,d2;
		cin>>n>>k>>d1>>d2;
		//Case I
		//A>B>C
		ll A,B,C;
		C=0;
		B=d2;
		A=d1+d2;
		bool ans=false;
		if(n-(k+d1+d1+d2)>=0&&(n-(k+d1+d1+d2))%3==0&&(k-(A+B+C))%3==0&&k-(A+B+C)>=0) ans=true;
		//cout<<ans<<endl;
		// Case II
		//A>B<C
		B=0;
		A=d1;
		C=d2;
		if(A>C) swap(A,C);
		if(n-(k+C-A+C)>=0&&(n-(k+C-A+C))%3==0&&(k-(A+B+C))%3==0&&k-(A+B+C)>=0) ans=true;
		//cout<<ans<<endl;
		//Case III
		//A<B<C
		A=0;
		B=d1;
		C=d1+d2;
		if(n-(k+d1+d2+d2)>=0&&(n-(k+d2+d1+d2))%3==0&&(k-(A+B+C))%3==0&&k-(A+B+C)>=0) ans=true;

		//Case IV
		//A<B>C
		B=max(d1,d2);
		A=B-d1;
		C=B-d2;
		if(n-(k+B-A+B-C)>=0&&(n-(k+B-A+B-C))%3==0&&(k-(A+B+C))%3==0&&k-(A+B+C)>=0) ans=true;

		if(ans) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}