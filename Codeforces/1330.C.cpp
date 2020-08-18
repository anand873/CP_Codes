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

int main()
{
	ll n,m;
	cin>>n>>m;
	vl L(m);
	ll stre=0;
	for(int i=0;i<m;i++)
	{
		cin>>L[i];
	}
	vl Ans(m);
	for(int i=0;i<m;i++)
	{
		Ans[i]=i+1;
	}
	bool yes=true;
	ll ex=0;
	for(int i=0;i<m;i++)
	{
		if(i+L[i]>n) {yes=false;break;}
		stre=max(i+L[i],stre);
		if(i!=m-1) ex+=L[i]-1;
	}
	//prin(Ans);
	ll diff=n-stre;
	ll curr=0;
	if(ex>=diff&&yes)
	{
		for(int i=0;i<m;i++)
		{
			Ans[i]+=curr;
			cout<<Ans[i]<<" ";
			if(ex>=diff)
			{
				curr+=min(diff,L[i]-1);
				ex-=min(diff,L[i]-1);
				diff-=min(diff,L[i]-1);
				
			}
		}
		cout<<endl;
	}
	else cout<<-1<<endl;
}		