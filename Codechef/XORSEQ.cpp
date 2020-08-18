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

const int MOD = 1e9+7,MAX = 5e6+5;
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

ll calxor(ll st,ll en)
{
	st--;
	ll x1,x2;
	if(st%4==0) x1=st;
	else if(st%4==1) x1=1;
	else if(st%4==2) x1=st+1;
	else x1=0;

	if(en%4==0) x2=en;
	else if(en%4==1) x2=1;
	else if(en%4==2) x2=en+1;
	else x2=0;

	return x1^x2;	
}

int main()
{
	ll n;
	cin>>n;
	int q;
	cin>>q;
	map<ll,ll> M;
	M[1]=n;
	set<ll> Oned;
	while(q--)
	{
		ll c,x;
		cin>>c>>x;
		if(c==1)
		{
			if(Oned.count(x)) continue;
			Oned.insert(x);
			auto it=M.upper_bound(x);
			it--;
			int st=(*it).first;
			int en=(*it).second;

			if(x==st)
			{
				M.erase(st);
				M[x+1]=en;
			}
			else if(x==en)
			{
				M[st]=en-1;
			}
			else
			{
				M[st]=x-1;
				M[x+1]=en;
			}
			
		}
		else
		{
			if(Oned.count(x))
			{
				auto it=M.upper_bound(x);
				if(it==M.end()) {cout<<0<<endl;continue;}

				int st=(*it).first;
				int en=(*it).second;
				cout<<calxor(st,en)<<endl;
			}
			else
			{
				auto it=M.upper_bound(x);
				it--;
				int en=(*it).second;
				cout<<calxor(x,en)<<endl;
			}
			
		}
	}
}		