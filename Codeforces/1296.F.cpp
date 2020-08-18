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

const int MOD = 1e9+7,MAX = 5005;
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

int INF = 1e9+5;
vector<bool> visited(MAX);
vector<int> S;
vvi M(MAX,vi(MAX));
vvi A(MAX);
vi MI(MAX,1);
void dfs(int a,int b,int g)
{
	S.push_back(a);
	if(a==b)
	{
		for(int i=0;i<S.size()-1;i++)
		{
			MI[M[S[i]][S[i+1]]]=max(g,MI[M[S[i]][S[i+1]]]);
		}
		return;
	}
	visited[a]=true;
	int f=0;
	for(auto x:A[a])
	{
		if(!visited[x])
		{
			dfs(x,b,g);
			S.pop_back();
		}
	}
} 

int mi;

void dfss(int a,int b,int g)
{
	S.push_back(a);
	if(a==b)
	{
		mi=MI[M[S[0]][S[1]]];
		for(int i=1;i<S.size()-1;i++)
		{
			mi=min(mi,MI[M[S[i]][S[i+1]]]);
		}
		return;
	}
	visited[a]=true;
	int f=0;
	for(auto x:A[a])
	{
		if(!visited[x])
		{
			dfss(x,b,g);
			S.pop_back();
		}
	}
}

int main()
{	
	
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		A[x].push_back(y);
		A[y].push_back(x);
		M[x][y]=i+1;
		M[y][x]=i+1;
	}
	int m;
	cin>>m;
	vector<vector<int>> V(m,vi(3));
	for(int i=0;i<m;i++)
	{
		int a,b,g;
		cin>>a>>b>>g;
		dfs(a,b,g);
		for(int i=0;i<MAX;i++) visited[i]=false;
		S.clear();
		V[i][0]=a;
		V[i][1]=b;
		V[i][2]=g;
	}

	bool ans=true;

	for(int i=0;i<m;i++)
	{
		int a,b,g;
		a=V[i][0];
		b=V[i][1];
		g=V[i][2];
		dfss(a,b,g);
		for(int i=0;i<MAX;i++) visited[i]=false;
		S.clear();
		if(mi!=g) {ans=false;break;}
	}
	if(!ans) {cout<<-1<<endl;return 0;}
	for(int i=1;i<n;i++)
	{
		printf("%d ",MI[i]);
	}
	cout<<endl;
}		