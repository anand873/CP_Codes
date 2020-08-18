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
#define test() int t;cin>>t;while(t--)
#define forn(f,n) for(int i=f;i<f+n;i++)
#define rforn(l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i];
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 3e5+5;
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
	int n,m;
	cin>>n>>m;
	vvi P(n+1),C(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		P[v].push_back(u);
		C[u].push_back(v);
	}
	int k;
	cin>>k;
	vi PP(k);
	take(PP,0,k);
	vi SP(n+1,MAX);
	int done=0;
	set<int> S;
	S.insert(PP[k-1]);
	done=0;
	SP[PP[k-1]]=0;
	while(done<n)
	{
		set<int> TA;
		for(auto in:S)
		{
			for(auto p:P[in])
			{
				SP[p]=min(SP[p],SP[in]+1);
				TA.insert(p);
			}
			
			done++;
		}
		S.clear();
		for(auto ta:TA) S.insert(ta);
	}
	int mi=0,ma=0;
	int len=1;
	for(int i=k-2;i>=0;i--)
	{
		if(SP[PP[i]]<len) {mi++;ma++;}
		else
		{
			int ding=0;
			for(auto c:C[PP[i]])
			{
				if(SP[c]==len-1) ding++;
			}
			if(ding>1) ma++;
		}
		len++;
	}
	cout<<mi<<" "<<ma<<endl;
}		