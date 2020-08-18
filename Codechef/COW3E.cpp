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

int main()
{
	int n,m,u,q;
	cin>>n>>m>>u>>q;
	vvl A(n+2,vl(m+2));
	vvl B(n+2,vl(m+2));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>B[i+1][j+1];
		}
	}
	
	for(int i=0;i<u;i++)
	{
		int k,r1,r2,c1,c2;
		cin>>k>>r1>>c1>>r2>>c2;
		A[r1+1][c1+1]+=k;
		A[r1+1][c2+2]-=k;
		A[r2+2][c1+1]-=k;
		A[r2+2][c2+2]+=k;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			A[i][j]+=A[i][j-1];
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=2;i<=n;i++)
		{
			A[i][j]+=A[i-1][j];
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			A[i][j]+=B[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			A[i][j]+=A[i][j-1];
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=2;i<=n;i++)
		{
			A[i][j]+=A[i-1][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		cout<<A[r2+1][c2+1]-A[r1][c2+1]-A[r2+1][c1]+A[r1][c1]<<endl;
	}
}		