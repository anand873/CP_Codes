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

ll INF = 1e18;

int main()
{	
	ll x0,y0,ax,ay,bx,by;
	cin>>x0>>y0>>ax>>ay>>bx>>by;
	ll xs,ys,t;
	cin>>xs>>ys>>t;
	map<pll,ll> M;
	M[{x0,y0}]=0;
	ll lx=x0,ly=y0;
	vector<ll> V;
	V.push_back(0ll);
	for(int i=1;;i++)
	{
		ll x=ax*lx+bx;
		ll y=ay*ly+by;
		if(x-lx+y-ly+M[{lx,ly}]>t) break;
		else
		{
			V.push_back(x-lx+y-ly);
			M[{x,y}]=x-lx+y-ly+M[{lx,ly}];
		}
		lx=x;
		ly=y;
	}
	for(int i=V.size()-2;i>=0;i--) V[i]+=V[i+1];
	lx=x0;
	ly=y0;
	map<pll,ll> N;
	N[{x0,y0}]=V[0];
	
	for(int i=1;i<V.size();i++)
	{	
		ll x=ax*lx+bx;
		ll y=ay*ly+by;
		N[{x,y}]=V[i];
		lx=x;
		ly=y;
	}
	ll ans=0;
	for(auto m:M)
	{
		//cout<<m.first.first<<" "<<m.first.second<<endl;
		if(abs(m.first.first-xs)+abs(m.first.second-ys)+m.second<=t)
		{
			ans++;
		}
	}
	ll ding=0;
	for(auto m:N)
	{
		//cout<<m.first.first<<" "<<m.first.second<<endl;
		if(abs(m.first.first-xs)+abs(m.first.second-ys)+m.second<=t)
		{
			ding++;
		}
	}
	cout<<max(ans,ding)<<endl;
}