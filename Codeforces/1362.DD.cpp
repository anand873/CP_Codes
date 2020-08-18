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
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 998244353,MAX = 1e6+5;
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
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	int n,m;
	cin>>n>>m;
	vector<set<int>> G(n+1);

	for(int i=0;i<m;i++)
	{
		int u,v;
		// cin>>u>>v;
		u = i+1;
		v = i+2;
		G[u].insert(v);
		G[v].insert(u);
	}
	vector<set<int>> H(n+1);
	vi T(n+1);
	// take(T,1,n);
	for(int i=1;i<=n;i++)
	{
		if(i%2) T[i]=2;
		else T[i]=1;

		H[T[i]].insert(i);
	}
	
	int curr=1;
	vi A;
	bool can=true;
	vi Cnt(n+1);
	// vector<bool> vis(n+1);
	while(curr<=n)
	{
		for(auto x:H[curr])
		{
			if(Cnt[x]==curr-1)
			{
				A.push_back(x);
				// vis[x]=true;
				for(auto y:G[x])
				{
					G[y].erase(x);
					Cnt[y] = min(curr,Cnt[y]+1);
				}
			}
			else can=false;
		}
		curr++;
	}
	if(can)
	{
		prin(A);
	}
	else cout<<-1<<endl;

}		