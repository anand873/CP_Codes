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

vvi A(MAX);
vector<bool> vis(MAX);
vector<int> height(MAX);

void dfs(int u)
{
	vis[u]=true;
	for(auto v:A[u])
}

int main()
{
	int n;
	cin>>n;
	int mi=0,ma=0;
	In.resize(n+1);
	vis.resize(n+1);
	A.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
		In[u]++;
		In[v]++;
	}
	set<int> L;
	for(int i=1;i<=n;i++)
	{
		if(In[i]==1) L.insert(i);
	}
	while(L.size()>2)
	{
		set<int> TR;
		for(auto l:L)
		{
			if(In[l]!=1) continue;
			vis[l]=true;
			In[l]--;
			TR.insert(l);
			for(auto v:A[l])
			{
				if(vis[v]) continue;
				In[v]--;
			}
		}
		for(auto tr:TR) L.erase(tr);
	}
	if(L.size()==1)
	{
		dfs(*(L.begin()));
	}
	else if(L.size()==2)
	{

	}


}		