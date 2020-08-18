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
#define test() int t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

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
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	int n;
	cin>>n;
	vi A(n);
	map<int,int> In;
	vi N = {4,8,15,16,23,42};
	map<int,int> O;
	for(auto x:N) O[x]=0;
	for(int i=0;i<6;i++) In[N[i]]=i;

	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		if(A[i]!=4&&O[N[In[A[i]]-1]]>0)
		{
			// cout<<"Sub: "<<N[In[A[i]]-1]<<endl;
			// cout<<"Add: "<<A[i]<<endl;
			O[N[In[A[i]]-1]]--;
			O[A[i]]++;
		}
		else if(A[i]==4)
		{
			O[A[i]]++;
		}
		// for(auto m:O) cout<<m.first<<": "<<m.second<<endl;
		// cout<<endl;
	}
	cout<<n - 6*O[42]<<endl;
	
}		