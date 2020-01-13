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
#define test(t) int t;cin>>t;while(t--)
#define forn(i,a,b) for(int i=a;i<b;i++)
#define rforn(i,b,a) for(int i=b-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
 
const int MOD = 1e9+7,MAX = 1e6+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p,ll mod)
{
	if(p==0) return 1;
	ll z=powN(a,p/2,mod);
	z=(z*z)%mod;
	if(p%2) z=(z*a)%mod;
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
	test(t)
	{
		int n,m;
		cin>>n>>m;
		vvi A(n+1,vi (m+1));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) scanf("%d",&A[i][j]);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int temp=min({i,j,n-i+1,m-j+1})-1;
				int ansr=1;
				for(int k=1;k<=temp;k++)
				{
					if(A[i-k][j]==A[i+k][j]) ansr++;
					else break;
				}
				int ansc=1;
				for(int k=1;k<=temp;k++)
				{
					if(A[i][j-k]==A[i][j+k]) ansc++;
					else break;
				}
				ans+=min(ansr,ansc);
			}
		}
		cout<<ans<<endl;
	}
}