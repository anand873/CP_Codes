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

vi S(2*MAX),In(2*MAX);
vector<vector<int>> G(2*MAX);
int n;

bool cmp(int a,int b)
{
	return In[a]<In[b];
}

int main()
{
	cin>>n;
	In.resize(n+1);
	S.resize(n+1);
	G.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	take(S,1,n);
	for(int i=1;i<=n;i++)
	{
		In[S[i]]=i;
	}

	for(int i=1;i<=n;i++)
	{
		sort(G[i].begin(),G[i].end(),cmp);
	}

	vector<bool> vis(n+1);
	vector<int> BFS;
	BFS.push_back(0);
	queue<int> Q;
	Q.push(1);
	vis[1]=true;
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		BFS.push_back(v);
		for(auto u:G[v])
		{
			if(vis[u]) continue;
			vis[u]=true;
			Q.push(u);
		}
	}
	//prin(BFS);
	//prin(S);
	for(int i=1;i<=n;i++)
	{
		if(BFS[i]!=S[i])
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}		