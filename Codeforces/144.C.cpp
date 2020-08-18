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
	string s;
	cin>>s;
	int lens=s.length();
	string p;
	cin>>p;
	int lenp=p.length();
	if(lenp>lens)
	{
		cout<<0<<endl;
	}
	else
	{
		vi FS(26),FP(26);
		int ex=0;
		for(int i=0;i<lenp;i++)
		{
			if(s[i]=='?') ex++;
			else
			{
				FS[s[i]-'a']++;
			}
			FP[p[i]-'a']++;
		}
		int how=0;
		bool ans=true;
		int fakex=ex;
		for(int i=0;i<26;i++)
		{
			if(FS[i]==FP[i]) continue;
			else
			{
				if(FP[i]>FS[i]&&FP[i]-FS[i]<=fakex)
				{
					fakex-=FP[i]-FS[i];
				}
				else
				{
					ans=false;
					break;
				}
			}
		}
		if(ans) how++;
		for(int i=1;i+lenp-1<lens;i++)
		{
			if(s[i+lenp-1]=='?')
			{
				ex++;
			}
			else
			{
				FS[s[i+lenp-1]-'a']++;
			}
			if(s[i-1]=='?')
			{
				ex--;
			}
			else
			{
				FS[s[i-1]-'a']--;
			}
			fakex=ex;
			ans=true;
			for(int i=0;i<26;i++)
			{
				if(FS[i]==FP[i]) continue;
				else
				{
					if(FP[i]>FS[i]&&FP[i]-FS[i]<=fakex)
					{
						fakex-=FP[i]-FS[i];
					}
					else
					{
						ans=false;
						break;
					}
				}
			}
			if(ans) how++;
		}
		cout<<how<<endl;
	}

}		