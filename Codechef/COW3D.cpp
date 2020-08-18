//Author: AnandRaj anand873
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
#define test() int _;cin>>_;while(_--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int _=f;_<f+n;_++) cin>>V[_]
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
vector<int> D(MAX);
vector<int> timeIn(MAX),timeOut(MAX);
int x=1;
void dfs(int u, int p)
{
	timeIn[u]=x++;
	for(auto v:A[u])
	{
		if(v==p) continue;
		D[v]=D[u]+1;
		dfs(v,u);
	}
	timeOut[u]=x++;
}

bool cmp(int a,int b)
{
	return D[a]<D[b];
}



int main()
{
	int n,Q;
	cin>>n>>Q;
	A.resize(n+1);
	D.resize(n+1);
	timeOut.resize(n+1);
	timeIn.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	dfs(1,0);

	while(Q--)
	{
		int k;
		cin>>k;
		vi X(k);
		take(X,0,k);
		sort(all(X),cmp);

		int fir=X[0];
		bool yes=true;
		for(int i=1;i<k;i++)
		{
			if(timeIn[fir]>timeIn[X[i]]||timeOut[fir]<timeOut[X[i]]) yes=false;
		}
		if(yes) cout<<fir<<endl;
		else cout<<-1<<endl;
	}
}		