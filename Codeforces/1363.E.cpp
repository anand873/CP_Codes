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

vvi V;
vi G1,G0;
vi vis;
vl A;
vi B,C;
const long long INF =  1e18+5;
void dfs(int u)
{
	vis[u]=true;
	if(B[u]!=C[u])
	{
		if(B[u]==1) G1[u]=1;
		else G0[u]=1;
	}
	for(auto v:V[u])
	{
		if(!vis[v])
		{
			dfs(v);
			G1[u]+=G1[v];
			G0[u]+=G0[v];
		}
	}
}

ll Dothing(int u)
{
	ll x=A[u]*(B[u]!=C[u]);
	vis[u]=true;
	for(auto v:V[u])
	{
		if(!vis[v])
		{
			if(G0[v]==G1[v])
			{
				x+=Dothing(v);
			}
			else x+=max(INF,Dothing(v));
		}
	}
	if(G1[u]==G0[u])
		return min(A[u]*(G1[u]+G0[u]),x);
	else return INF;
}

int main()
{
	int n;
	cin>>n;
	A.resize(n+1);
	B.resize(n+1);
	C.resize(n+1);
	G1.resize(n+1);
	G0.resize(n+1);
	V.resize(n+1);
	vis.resize(n+1);
	int b1=0,c1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i]>>B[i]>>C[i];
		b1+=B[i];
		c1+=C[i];
	}
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		V[u].push_back(v);
		V[v].push_back(u);
	}

	if(b1!=c1)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		dfs(1);
		vis.clear();
		ll ans = Dothing(1);
		cout<<ans<<endl;
	}
}		