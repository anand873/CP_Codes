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
#define forn(f,n) for(int i=f;i<f+n;i++)
#define rforn(l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i];
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 3e5+5;
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
	int n=s.length();
	vi dpf(n+1),dpb(n+1);
	if(s[0]=='(') dpf[1]=1;
	if(s[n-1]==')') dpb[n]=1;
 	for(int i=2;i<=n;i++)
 	{
 		if(s[i-1]=='(') dpf[i]=1+dpf[i-1];
 		else dpf[i]=dpf[i-1];
 	}
 	for(int i=n-1;i>0;i--)
 	{
 		if(s[i-1]==')') dpb[i]=dpb[i+1]+1;
 		else dpb[i]=dpb[i+1];
 	}
 	vi A;
 	int ma=0;
 	for(int i=1;i<n;i++)
 	{
 		ma=max(ma,min(dpf[i],dpb[i+1]));
 	}
 	if(ma>0)
 	{
 		int op=0;
 		for(int i=0;i<n&&op<ma;i++)
 		{
 			if(s[i]=='(') {A.push_back(i+1);op++;} 
 		}
 		for(int i=n-1;i>=0&&op>0;i--)
 		{
 			if(s[i]==')') {A.push_back(i+1);op--;}
 		}
 	}
 	reverse(A.begin()+ma,A.end());
 	if(A.size()==0)
 	{
 		cout<<0<<endl;
 	}
 	else
 	{
 		cout<<1<<endl;
 		cout<<A.size()<<endl;
 		prin(A);
 	}
}		