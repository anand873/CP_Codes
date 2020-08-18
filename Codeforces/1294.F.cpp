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
vvi A(2*MAX);
vector<bool> visited(2*MAX);
int door,door2;
int ma=0;
void dfs(int i,int dis)
{
	if(!visited[i])
	{
		visited[i]=true;
		for(auto x:A[i])
		{
			dfs(x,dis+1);
		}
		if(A[i].size()==1)
		{
			if(dis>=ma)
			{
				ma=dis;
				door=i;
			}
		}
	}
}

void dfss(int i,int dis)
{
	if(!visited[i])
	{
		visited[i]=true;
		if(dis>ma) 
		{
			ma=dis;
			door2=i;
		}
		for(auto x:A[i])
		{
			dfss(x,dis+1);
		}
		
	}
}

vector<int> ding(3);
void dfsss(int i,int j,int dis,int fi)
{
	if(!visited[i])
	{
		if(i==j)
		{
			ding[fi]=dis;
			return;
		}
		visited[i]=true;
		for(auto x:A[i])
		{
			dfsss(x,j,dis+1,fi);
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
	ma=0;
	dfss(door,0);
	for(int i=1;i<=n;i++) visited[i]=false;
	set<int> PO={door,door2};
	while(1)
	{
		set<int> toadd;
		for(auto ss:PO)
		{
			visited[ss]=true;
			for(auto x:A[ss])
			{
				if(!visited[x])
				{
					toadd.insert(x);
				}
			}
		}
		if(toadd.size()==0) break;
		PO.clear();
		for(auto ta:toadd) PO.insert(ta);
	}
	int x = *PO.begin();
	for(int i=1;i<=n;i++) visited[i]=false;
	dfsss(door,x,0,0);
	for(int i=1;i<=n;i++) visited[i]=false;
	dfsss(door2,x,0,1);
	for(int i=1;i<=n;i++) visited[i]=false;
	dfsss(door,door2,0,2);
	cout<<(ding[0]+ding[1]-ding[2])/2+ding[2]<<endl;
	cout<<door<<" "<<door2<<" "<<x<<endl;
}