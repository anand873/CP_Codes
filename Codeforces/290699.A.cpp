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
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

//////////////////Sieve////////////////////
vector<bool> is_prime(MAX, true);
vi MinDiv(MAX);
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

vvi A;
vi vis;
vi SC,V;

void dfs(int u)
{
	vis[u]=true;
	if(is_prime[V[u]]) SC[u]=1;
	for(auto v:A[u])
	{
		if(!vis[v])
		{
			dfs(v);
			SC[u] += SC[v];
		}
	}
}

int main()
{
	Sieve();
	fastio
	int n;
	cin>>n;
	int m;
	cin>>m;

	A.resize(n+1);
	vi X(m),Y(m);
	take(X,0,m);
	cin>>m;
	take(Y,0,m);
	for(int i=0;i<m;i++)
	{
		A[X[i]].push_back(Y[i]);
		A[Y[i]].push_back(X[i]);
	}
	cin>>n;
	vis.resize(n+1);
	SC.resize(n+1);
	V.resize(n+1);
	take(V,1,n);

	dfs(1);

	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int x;
		cin>>x;
		cout<<SC[x]<<endl;
	}

}	