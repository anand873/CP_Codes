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
#define test() int t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
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
vector<bool> is_prime(MAX, true);
vector<int> MinDiv(MAX);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
    		MinDiv[i]=i;
        	for (j = i * i; j <= MAX; j += i)
            {
				is_prime[j] = false;
				MinDiv[j]=i;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	int n,m;
	cin>>n>>m;
	vl D(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		D[u]+=w;
		D[v]-=w;
	}
	sort(1+all(D));
	int st=1,en=n;
	ll ans=0;
	while(st<en)
	{
		if(abs(D[st])<abs(D[en]))
		{
			ans+=abs(D[st]);
			D[en]-=abs(D[st]);
			D[st]=0;
			st++;
		}
		else if(abs(D[st])>abs(D[en]))
		{
			ans+=abs(D[en]);
			D[st]+=abs(D[en]);
			D[en]=0;
			en--;
		}
		else
		{
			ans+=abs(D[en]);
			D[en]=0;
			D[st]=0;
			en--;
			st++;
		}
	}
	cout<<ans<<endl;
}		