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
	string s1,s2;
	cin>>s1>>s2;
	if(s1.length()>s2.length()) swap(s1,s2);
	vector<int> L;
	int l1=s1.length();
	int l2=s2.length();
	int g=__gcd(l1,l2);
	for(int i=1;i<=g;i++)
	{
		if(l1%i==0&&l2%i==0)
		{
			L.push_back(i);
		}
	}
	int good=0;
	for(auto l:L)
	{
		bool can=true;
		for(int i=0;i<l;i++)
		{
			if(s1[i]!=s2[i]) can=false;
		}
		if(!can) continue;
		for(int i=l;i<l1;i++) if(s1[i]!=s1[i-l]) can=false;
		for(int i=l;i<l2;i++) if(s2[i]!=s2[i-l]) can=false;
		if(can) good++;
	}
	cout<<good<<endl;
	
}		