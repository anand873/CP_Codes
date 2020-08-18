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
}
//////////////////Sieve////////////////////

bool loop=false;
vi vis(MAX);
vvi A(MAX);
set<int> S;
void dfs(int u)
{
	if(loop) return;
	vis[u]=true;
	S.insert(u);
	for(auto v:A[u])
	{
		if(S.count(v)) loop=true;
		else if(!vis[v]) dfs(v);		
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	A.resize(n+1);
	vi Out(n+1),In(n+1);
	vis.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int j,k;
		cin>>j>>k;
		A[j].push_back(k);
		Out[j]++;
		In[k]++;
	}
	string s;
	for(int i=1;i<=n;i++)
	{
		S.clear();
		if(!vis[i]) dfs(i);
	}
	if(loop) cout<<-1<<endl;
	else
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(In[i]==0) {s+="A";cnt++;}
			else s+="E";
		}
		cout<<cnt<<endl;
		cout<<s<<endl;
	}



}		