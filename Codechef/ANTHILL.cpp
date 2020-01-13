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

int main()
{	
	int n,m,a,r;
	cin>>n>>m>>a>>r;
	set<pii> Ed;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		//cout<<u<<" "<<v;
		Ed.insert({u,v});
	}
	//for(auto ed:Ed) cout<<ed.first<<" "<<ed.second<<endl;
	vector<pii> V;
	vector<int> An;
	while(Ed.size()>=2)
	{
		auto x=Ed.begin();
		pii X=*x;
		x++;
		pii Y=*x;
		if(X.first==Y.first)
		{
			if(Ed.count({X.second,Y.second}))
			{
				An.push_back(2);
				V.push_back({X.first,X.second});
				V.push_back({Y.first,Y.second});
				Ed.erase(X);
				Ed.erase(Y);
				Ed.erase({X.second,Y.second});
				//printf("1 2 %d %d %d %d\n",X.first,X.second,Y.first,Y.second);
			}
			else
			{
				An.push_back(1);
				An.push_back(1);
				V.push_back({X.first,X.second});
				V.push_back({Y.first,Y.second});
				Ed.erase(X);
				Ed.erase(Y);
				//printf("1 1 %d %d\n1 1 %d %d\n",X.first,X.second,Y.first,Y.second);
			}
			
		}
		else
		{
			An.push_back(1);
			V.push_back({X.first,X.second});
			//printf("1 1 %d %d\n",X.first,X.second);
			Ed.erase(X);
		}
	}
	if(Ed.size())
	{
		pii X=*Ed.begin();
		An.push_back(1);
		V.push_back({X.first,X.second});
		//printf("1 1 %d %d\n",X.first,X.second);
	}
	printf("%d\n",An.size());
	int done=0;
	for(auto x:An)
	{
		printf("1 %d",x);
		for(int i=0;i<x;i++)
		{
			printf(" %d %d",V[done+i].first,V[done+i].second);
		}
		printf("\n");
		done+=x;
	}
}