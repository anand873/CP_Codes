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

const int MOD = 1e9+7,MAX = 1005;
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

vector<bool> visited(MAX);
vvi A(MAX);
int ma=0;
int curma;
void dfs(int p,int dis)
{
	if(visited[p]) return;
	else
	{
		visited[p]=true;
		if(dis>=ma)
		{
			curma=p;
			ma=dis;
		}
		for(auto q:A[p])
		{
			dfs(q,dis+1);
		}
	}
}

void dfss(int s,int e)
{
	if(visited[s]) return;
	else
	{
		if(s==e) return;
		
		
		else
		{
			visited[s]=true;
			for(auto n:A[s])
			{
				dfss(n,e);
			}
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
		cin>>x>>y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) visited[i]=false;
	int last=curma;
	ma=0;
	dfs(curma,0);
	cout<<"? "<<last<<" "<<curma<<endl;
	int w;
	cin>>w;
	while(curma!=w&&last!=w)
	{
		for(int i=1;i<=n;i++) visited[i]=false;
		dfss(last,w);
		dfss(curma,w);
		ma=0;
		dfs(w,0);
		cout<<"? "<<w<<" "<<curma<<endl;
		last=w;
		cin>>w;
	}
	cout<<"! "<<w<<endl;
}		