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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

int can(int x, int i, int j)
{
	set<int> S;
	while(S.count(x)==0)
	{
		if(x%__gcd(i,j)==0)
	}
}

int main()
{
	string s;
	cin>>s;
	vvi M(10,vi(10));
	for(int i=0;i<10;i++)
	{
		for(int j=i;j<10;j++)
		{
			int ans=0;
			char last;
			for(int k=0;k<s.length();k++)
			{
				if(k==0&&s[k]!='0') {k--;ans++;last='0';continue;}
				else if(k==0&&s[k]=='0') {last='0';continue;}

				if(last+i==s[k])
				{
					last=s[k];
					continue;
				}
				else if(last+j==s[k])
				{
					last=s[k];
				}
				else 
				{
					if(can((10+s[k]-last)%10,i,j)==-1)
					{
						ans=-1;
						break;
					}	
					else
					{
						ans+=can((10+s[k]-last)%10,i,j);
					}
				}
				M[i][j]=ans;
			}
		}
	}
}		