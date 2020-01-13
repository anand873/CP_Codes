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
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
 
const int MOD = 998244353,MAX = 1e6+5;
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
	int n;
	cin>>n;
	vector<pii> M(n);
	vector<bool> A(n);
	for(int i=0;i<n;i++)
	{
		int l;
		cin>>l;
		vector<int> V(l);
		M[i].first=INT_MAX;
		for(int j=0;j<l;j++) 
		{
			cin>>V[j];
			M[i].first=min(M[i].first,V[j]);
			M[i].second=max(M[i].second,V[j]);
		}
		vector<int> MIN(l);
		MIN[0]=V[0];
		for(int j=1;j<l;j++)
		{
			MIN[j]=min(MIN[j-1],V[j]);
		}
		for(int j=1;j<l;j++)
		{
			if(V[j]>MIN[j-1]) {A[i]=true;break;}
		}
	}
	//for(int i=0;i<n;i++) cout<<A[i]<<endl;
	ll tot=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]) tot++;
	}
	ll sum=tot*n;
	//cout<<sum<<endl;
	vector<ll> HOW(MAX);
	for(int i=0;i<n;i++)
	{
		if(A[i]) continue;
		HOW[M[i].second]++;
	}
	for(int i=MAX-2;i>=0;i--) HOW[i]+=HOW[i+1];
	//cout<<endl;
	for(int i=0;i<n;i++)
	{
		if(A[i]) continue;
		sum+=HOW[M[i].first+1];
		sum+=tot;
	}
	cout<<sum<<endl;

}