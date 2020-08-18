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
	test()
	{
		int n0,n1,n2;
		cin>>n0>>n1>>n2;
		string s;
		if(n0!=0&&n1==0&&n2==0)
		{
			for(int i=0;i<=n0;i++) s+='0';
			cout<<s<<endl;
		}
		else if(n1!=0&&n0==0&&n2==0)
		{
			for(int i=0;i<=n1;i++)
			{
				if(i%2) s+='0';
				else s+='1';
			}
			cout<<s<<endl;
		}
		else if(n2!=0&&n1==0&&n0==0)
		{
			for(int i=0;i<=n2;i++) s+='1';
			cout<<s<<endl;
		}
		else if(n0==0)
		{
			for(int i=0;i<n2;i++)
			{
				s+='1';
			}
			for(int i=0;i<=n1;i++)
			{
				if(i%2) s+='0';
				else s+='1';
			}
			cout<<s<<endl;
		}
		else if(n2==0)
		{
			for(int i=0;i<n0;i++)
			{
				s+='0';
			}
			for(int i=0;i<=n1;i++)
			{
				if(i%2) s+='1';
				else s+='0';
			}
			cout<<s<<endl;
		}
		else
		{
			for(int i=0;i<n0;i++)
			{
				s+='0';
			}
			for(int i=0;i<=n1;i++)
			{
				if(i%2) s+='1';
				else s+='0';
			}
			if(s.back()=='0')
			{
				s[s.length()-1]='1';
				for(int i=0;i<n2-1;i++) s+='1';
				s+='0';
				cout<<s<<endl;
			}
			else
			{
				for(int i=0;i<n2;i++) s+='1';
				cout<<s<<endl;
			}
		}
	}
}		