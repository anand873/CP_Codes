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

string find(vi N,int len)
{
	int outcnt=9*(len-1);
	if(N[0]>0) N[0]--;
	int carr=0;
	int i;
	for(i=0;i<len;i++)
	{
		N[i]=N[i]*9+carr;
		carr=N[i]/10;
		N[i]=N[i]%10;
	}
	while(carr)
	{
		//cout<<1<<endl;
		N[i]=carr%10;
		carr/=10;
		i++;
	}
	len=i;
	i=0;
	carr=9;
	while(carr!=0)
	{
		//cout<<2<<endl;
		len=max(i+1,len);
		if(i==0)
		{
			N[i]+=carr;
			carr=N[i]/10+1;
			N[i]%=10;
		}
		else
		{
			N[i]+=carr;
			carr=N[i]/10;
			N[i]%=10;
		}
		i++;
	}
	carr=0;
	i=0;
	while(outcnt||carr)
	{
		//cout<<3<<endl;
		N[i]+=(carr+outcnt%10);
		carr=N[i]/10;
		N[i]=N[i]%10;
		i++;
		outcnt/=10;
	}
	string s="";
	for(int i=0;i<len;i++) s+='0'+ N[i];
	reverse(all(s));
	return s;

}

int main()
{	
	test()
	{
		string s;
		cin>>s;
		vi N(2*MAX);
		for(int i=0;i<s.length();i++)
		{
			N[i]=s[i]-'0';
		}
		cout<<find(N,s.length())<<endl;
	}
}		