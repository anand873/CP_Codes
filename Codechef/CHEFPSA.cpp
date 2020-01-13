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
#define take(V,f,n) for(int i=f;i<f+n;i++) scanf("%lld",&V[i])
 
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
 
vector<ll> FAC(MAX);
vector<ll> INV(MAX);
vector<ll> P2(MAX);

ll C(ll n, ll r)
{
	return (((FAC[n]*INV[r])%MOD)*INV[n-r])%MOD;
}
 
int main()
{
	//fastio
	FAC[0]=FAC[1]=1ll;
	for(ll i=2;i<MAX;i++)
	{
		FAC[i]=(i*FAC[i-1])%MOD;
	}
	for(int i=0;i<MAX;i++)
	{
		INV[i]=powN(FAC[i],MOD-2,MOD);
	}
	for(ll i=0;i<MAX;i++)
	{
		P2[i]=powN(2ll,i,MOD);
	}	
	test(t)
	{
		ll n;
		scanf("%lld",&n);
		vl A(2*n);
		set<ll> S;
		ll curr=n-1;
		map<ll,ll> M;
		take(A,0,2*n);
		ll sum=0;
		ll ans=1;
		for(int i=0;i<2*n;i++) sum+=A[i];
		ll tot=sum/(n+1);
		
		if(sum%(n+1)) {ans=0;goto en;}

		for(auto x:A)
		{
			if(M.find(x)==M.end()) M.insert({x,1ll});
			else M[x]++;
		}
		if(M.find(tot)==M.end()) {ans=0;goto en;}
		else
		{
			if(M[tot]<2) {ans=0;goto en;}
			else
			{ 
				M[tot]-=2;
				if(M[tot]==0) M.erase(tot);
			}
		}
		for(auto m:M)
		{
			if(S.count(m.first)) continue;
			if(2ll*m.first==tot)
			{
				if(m.second%2) {ans=0;break;}
				m.second/=2;
				ans=(ans*C(curr,m.second))%MOD;
				S.insert(m.first);
				curr-=m.second;
			}
			else if(M.find(tot-m.first)==M.end()||m.second!=M[tot-m.first])
			{
				ans=0;break;
			}
			else if(m.second==M[tot-m.first])
			{
				ans=(ans*C(curr,m.second))%MOD;
				ans=(ans*P2[m.second])%MOD;
				S.insert(m.first);
				S.insert(tot-m.first);
				curr-=m.second;
			}
		}
	en:	printf("%lld\n",ans);
	}
}