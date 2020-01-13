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
 
void RoundRobin(vector<vector<pii>> &RR)
{
	int n=RR.size()-1;
	vector<int> PERM(n+1);
	for(int i=1;i<=n;i++) PERM[i]=i;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n/2;j++)
		{
			//cout<<PERM[j]<<" "<<PERM[n-j+1]<<endl;
			int x=PERM[j];
			int y=PERM[n-j+1];
			if(x>y) swap(x,y);
			RR[i].push_back({x,y});
		}
		reverse(PERM.begin()+2,PERM.end());
		reverse(PERM.begin()+3,PERM.end());
	}
}

int main()
{	
	test(t)
	{
		int n;
		cin>>n;
		if(n==1) cout<<"Hooray\n1\n";
		else if(n%2) cout<<"Boo\n";
		else
		{
			cout<<"Hooray\n";
			vvi V(n,vi(n));
			for(int i=0;i<n;i++) V[i][i]=1;
			vector<vector<pii>> RR(n+1);
			RoundRobin(RR);
			for(int i=1;i<n;i++)
			{
				for(auto pp:RR[i])
				{
					V[pp.first-1][pp.second-1]=2*i;
				}
			}

			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++) V[j][i]=V[i][j]+1;
				for(int j=0;j<n;j++) printf("%d ",V[i][j]);
				printf("\n");
			}
		}
	}
}