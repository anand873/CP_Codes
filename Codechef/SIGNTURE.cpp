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

#define test(t) int t;cin>>t;while(t--)
#define forn(i,n) for(i=0;i<n;i++)
#define rforn(i,n) for(i=n-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
const int MOD = 1e9+7,MAX = 1e5+5;
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
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
ll modInv(ll a)
{
	return powN(a,MOD-2);
}


int main()
{
	test(t)
	{
		int n,m;
		cin>>n>>m;
		vector<string> A(n),B(n);
		vi AA,BB;
		int i;
		for(i=0;i<n;i++) cin>>A[i];
		int j;
		// for(i=0;i<n;i++)
		// {
		// 	for(j=0;j<m;j++)
		// 	{
		// 		AA.push_back(A[i][j]-'0');
		// 	}
		// }
		for(i=0;i<n;i++) cin>>B[i];
		// for(i=0;i<n;i++)
		// {
		// 	for(j=0;j<m;j++)
		// 	{
		// 		BB.push_back(B[i][j]-'0');
		// 	}
		// }
		int ans=10000;
		// for(i=-n*m+1;i<n*m;i++)
		// {	
		// 	int a=0;
		// 	for(j=0;j<n*m;j++)
		// 	{
		// 		if(((i+j<n*m&&i+j>-1)?BB[i+j]:0)!=AA[j]) a++;
		// 	}
		// 	cout<<i<<" "<<a<<endl;
		// 	ans=min(a,ans);
		// }
		int dr=-n,dc=-m;
		for(dr=-n;dr<n;dr++)
		{
			for(dc=-m;dc<m;dc++)
			{
				int a=0;
				for(i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if(A[i][j]!=((i+dr>=0&&i+dr<n&&j+dc>=0&&j+dc<m)?B[i+dr][j+dc]:'0')) a++;
					}
				}
				ans=min(ans,a);
			}
		}
		cout<<ans<<endl;
	}
}