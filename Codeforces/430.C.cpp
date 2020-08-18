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

vvi A(MAX);
vector<bool> visited(MAX);
vi I(MAX);
vi G(MAX);
set<int> S;
void dfs(int i,int dis,int odd,int even)
{
	if(!visited[i])
	{
		visited[i]=true;
		if((((dis%2)?odd:even)-(I[i]==G[i]))%2)
		{
			for(auto x:A[i])
			{
				dfs(x,dis+1,odd,even);
			}
		}
		else
		{
			if(dis%2) odd++;
			else even++;
			S.insert(i);
			for(auto x:A[i])
			{
				dfs(x,dis+1,odd,even);
			}
		}
	}
}

int main()
{	
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	take(I,1,n);
	take(G,1,n);
	dfs(1,0,0,0);
	cout<<S.size()<<endl;
	for(auto s:S)
		cout<<s<<endl;
}