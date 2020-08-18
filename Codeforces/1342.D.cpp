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

const int MOD = 998244353,MAX = 1e5+5;
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
/*

	Classic Binary Search.
	Find the Minimum number of Tests satisfying conditions.

	Greedy is to arrange in this way.

	If M is 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4. and Mid = 3.
	Then one easy way is: 

Test (1) (2) (3) (4)
	-----------------
	| 1 | 2 | 2 | 3 | 
	| 1 | 2 | 3 | 4 |
	| 1 | 2 | 3 | 4 |
*/

int main()
{
	int n,k;
	cin>>n>>k;
	vi M(n);
	take(M,0,n);
	vi Hash(k+1);
	for(auto m:M) Hash[m]++;

	vector<vector<int>> ANS(k+1);
	for(int i=0;i<n;i++)
	{
		ANS[M[i]].push_back(i+1);
	}
	vi C(k+1);
	take(C,1,k);
	//prin(C);
	int fin=-1;
	int low=(n+C[1]-1)/C[1],high=n;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		int tot=0;
		bool ans=true;
		for(int i=k;i>=1;i--)
		{
			tot+=Hash[i];
			if((tot+mid-1)/mid>C[i]) ans=false;
		}
		if(ans) {high=mid-1;fin=mid;}
		else low=mid+1;
	}


	vector<vector<int>> V(fin);
	int tot=0;
	sort(all(M));
	for(int i=0;i<n;i++)
	{
		V[i%fin].push_back(M[i]);
	}

	printf("%d\n",fin);
	for(int i=0;i<fin;i++)
	{
		printf("%d", (int)V[i].size());
		for(int j=0;j<V[i].size();j++) printf(" %d",V[i][j]);
		printf("\n");
	}
}		