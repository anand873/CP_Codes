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

int main()
{	
	test()
	{
		string s;
		cin>>s;
		vector<int> KEY(405,-1);
		KEY[100]=s[0]-'a';
		int f=1;
		int curr=100;
		int mincurr=100;
		int maxcurr=100;
		set<int> D;
		for(int i=0;i<26;i++) D.insert(i);
		D.erase(s[0]-'a');
		for(int i=1;i<s.length();i++)
		{
			if(KEY[curr+1]==s[i]-'a') {curr++;mincurr=min(curr,mincurr);maxcurr=max(curr,maxcurr);}
			else if(KEY[curr-1]==s[i]-'a') {curr--;mincurr=min(curr,mincurr);maxcurr=max(curr,maxcurr);}
			else if(KEY[curr+1]==-1&&D.count(s[i]-'a')) {D.erase(s[i]-'a');KEY[curr+1]=s[i]-'a';curr++;mincurr=min(curr,mincurr);maxcurr=max(curr,maxcurr);}
			else if(KEY[curr-1]==-1&&D.count(s[i]-'a')) {D.erase(s[i]-'a');KEY[curr-1]=s[i]-'a';curr--;mincurr=min(curr,mincurr);maxcurr=max(curr,maxcurr);}
			else
			{
				f=0;break;
			}
		}
		if(f==0) cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for(int i=mincurr;i<=maxcurr;i++)
				cout<<(char)(KEY[i]+'a');
			for(auto x:D) cout<<(char)(x+'a');
			cout<<endl;
		}

	}
}		