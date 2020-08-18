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

void bfs(vvi &A,int src,int dest,vi &pred,vi &dist)
{
	vi que;
	vector<bool> vis(dest+1);
	for(int i=1;i<=dest;i++)
	{
		dist[i]=MOD;
		pred[i]=-1;
	}
	vis[src]=true;
	dist[src]=0;
	que.push_back(src);

	while(que.size())
	{
		int u=que.back();
		que.pop_back();
		for(auto x:A[u])
		{
			if(!vis[x])
			{
				vis[x]=true;
				dist[x]=dist[u]+1;
				pred[x]=u;
				que.push_back(x);

				if(x==dest)
					return;
			}
		}
	}
}

pair<vi,vi> bfss(vvi &A,int s,int d)
{
	vi pred(d+1),dist(d+1);
	bfs(A,s,d,pred,dist);
	vi path;
	int crawl = d;
	path.push_back(crawl);
	while(pred[crawl]!=-1)
	{
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}
	return {path,dist};
}

int main()
{	
	int n,m,k;
	cin>>n>>m>>k;
	set<int> S;
	for(int i=0;i<k;i++)
	{
		int x;
		cin>>x;
		S.insert(x);
	}
	vvi A(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	pair<vi,vi> DING;
	DING=bfss(A,1,n);

	vi Path=DING.first;
	vi dist=DING.second;
	reverse(all(Path));
	vector<pii> SP;
	for(int i=0;i<Path.size();i++)
	{
		if(S.count(Path[i]))
		{
			SP.push_back({Path[i],dist[Path[i]]});
		}
	}
	if(k==SP.size())
	{
		int mindis=MOD;
		for(int i=1;i<SP.size();i++)
		{	
			mindis=min(mindis,SP[i].second-SP[i-1].second-1);
		}
		cout<<dist[n]-mindis<<endl;
		
	}
	else if(k>=SP.size()+2)
	{
		cout<<dist[n]<<endl;
	}
	else
	{
		pii LAST=SP[SP.size()-1];
		
	}

	
}