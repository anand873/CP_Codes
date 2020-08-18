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
	int n,m;
	cin>>n>>m;
	vi A(n+1);
	vi In(n+1);
	vpii HL(n+1);
	for(int i=0;i<n;i++) {In[i+1]=A[i+1]=i+1;HL[i+1]={i+1,i+1};}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		if(In[x]==1) continue;
		else
		{
			HL[x].first=min(HL[x].first,In[x]-1);
			HL[A[In[x]-1]].second=max(HL[A[In[x]-1]].second,In[x]);
			int ind=In[x];
			swap(A[ind],A[ind-1]);
			In[A[In[x]]]++;
			In[x]--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<HL[i].first<<" "<<HL[i].second<<endl;
	}
}		