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
	test()
	{
		string s;
		cin>>s;
		int m;
		cin>>m;
		vi b(m);
		take(b,0,m);
		string t;
		map<char,int> M;
		for(int i=0;i<s.length();i++) M[s[i]]++;
		for(int i=0;i<m;i++) t+='0';

		vi vis(m);
		while(1)
		{
			set<int> z;
			int zero=0;
			for(int i=0;i<m;i++)
			{
				if(!vis[i]&&b[i]==0)
				{
					z.insert(i);
					vis[i]=true;
					zero++;
				} 
			}

			if(zero==0) break;
			while((*(M.rbegin())).second<zero)
			{
				M.erase((*(M.rbegin())).first);
			}
			char last = (*(M.rbegin())).first;
			M.erase(last);
			for(auto i:z)
			{
				if(b[i]==0)
				{
					t[i]=last;
					for(int j=0;j<m;j++)
					{
						if(!vis[j])
						{
							b[j]-=abs(j-i);
						}
					}
				}
			}
		}
		cout<<t<<endl;
	}
}		