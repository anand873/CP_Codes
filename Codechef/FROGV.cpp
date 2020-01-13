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
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl;

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
	int n,k,p;
	cin>>n>>k>>p;
	vector<int> A(n);
	map<int,set<int>> M;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		if(M.find(A[i])!=M.end())
		{
			M[A[i]].insert(i);
		}
		else
		{
			set<int> S;
			S.insert(i);
			M.insert({A[i],S});
		}
	}
	
	vector<int> dp(n);
	auto i=M.begin();
	for(auto x:(*i).second)
	{
		dp[x]=0;
	}
	auto j=i;
	j++;
	int kk=0;
	while(j!=M.end())
	{
		if((*i).first+k>=(*j).first)
		{
			for(auto x:(*j).second)
			{
				dp[x]=kk;
			}
		}
		else
		{
			kk++;
			for(auto x:(*j).second)
			{
				dp[x]=kk;
			}
		}
		i++;
		j++;
	}
	while(p--)
	{
		int a,b;
		cin>>a>>b;
		if(dp[a-1]==dp[b-1]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

	}
}