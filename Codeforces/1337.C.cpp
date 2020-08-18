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

const int MOD = 1e9+7,MAX = 2e5+5;
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
vpll HC(MAX);
vi In(MAX);
vi vis(MAX);

void dfs(int u,int h)
{	
	vis[u]=true;
	HC[u-1].first=h;
	for(auto v:A[u])
	{
		if(vis[v]) continue;
		dfs(v,h+1);
		HC[u-1].second+=1+HC[v-1].second;
	}
}

bool cmp(pii a, pii b)
{
	return a.first-a.second>b.first-b.second;
}

int main()
{
	int n,k;
	cin>>n>>k;
	A.resize(n+1);
	//In.resize(n+1);
	HC.resize(n);
	vis.resize(n+1);

	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	dfs(1,0);
	ll sum=0;
	sort(all(HC),cmp);
	//for(int i=0;i<n;i++) cout<<HC[i].first<<" "<<HC[i].second<<endl;
	for(int i=0;i<k;i++)
	{
		sum+=HC[i].first-HC[i].second;
	}
	cout<<sum<<endl;
}		