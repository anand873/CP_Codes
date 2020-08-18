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

int lps(string s)
{
	int n=s.length();
	vi lp(n+5);
	lp[0]=0;
	int len=0;
	int i=1;
	while(i<n)
	{
		if(s[i]==s[len])
		{
			len++;
			lp[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lp[len-1];
			}
			else
			{
				lp[i]=0;
				i++;
			}
		}
	}
	
	int res=lp[n-1];
	return (res>n/2)?n/2:res;
}

int main()
{
	test()
	{
		string s;
		cin>>s;
		int n=s.length();
		string s1,s2;
		int st=0,en=n-1;
		for(int i=0;i<n/2;i++)
		{
			if(s[i]==s[n-1-i])
			{
				st++;
				en--;
				s1.push_back(s[i]);
				s2.push_back(s[n-1-i]);
			}
			else
			{
				st=i;
				en=n-1-i;
				break;
			}
		}
		int ans1=0;
		int ans2=0;
		string ss1=s.substr(st,en-st+1);
		string ss2=ss1;
		reverse(all(ss2));
		//what(ss1);
		//what(ss2);
		string ss3=ss1+'#'+ss2;
		//what(ss3);
		ans1=lps(ss3);
		string ss4=ss2+'#'+ss1;
		//what(ss4);
		ans2=lps(ss4);
		if(ans1>ans2)
		{
			string S=ss3.substr(0,ans1);
			reverse(all(s2));
			cout<<s1<<S<<s2<<endl;
		}
		else
		{
			string S=ss4.substr(0,ans2);
			reverse(all(s2));
			cout<<s1<<S<<s2<<endl;
		}
	}
}		