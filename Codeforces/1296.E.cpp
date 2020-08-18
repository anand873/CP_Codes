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
#define test(t) int t;cin>>t;while(t--)
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl

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
	int n;
	cin>>n;
	string s;
	cin>>s;
	vi A(n);
	set<int> F;
	bool f=true;
	for(int i=0;i<n;i++)
	{
		if(F.count(i)==0) {A[i]=0;F.insert(i);}
		for(int j=i+1;j<n;j++)
		{
			if(s[j]<s[i])
			{
				if(F.count(j)==0)
				{
					A[j]=1^A[i];
					F.insert(j);
				}
				else
				{
					if(A[i]^A[j]==1) continue;
					else {f=false;break;}
				}
			}
			if(!f) break;
		}

	}
	if(f)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++) cout<<A[i];
		cout<<endl;
	}
	else cout<<"NO"<<endl;

}		