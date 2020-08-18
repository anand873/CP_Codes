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
#define take(V,f,n) for(int i=f;i<f+n;i++) scanf("%lld",&V[i])
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

int ans1=0,ans2=0;

void fun(string s,string t)
{
	if(s=="8<"&&t=="[]") ans1++;
	if(s=="8<"&&t=="()") ans2++;
	if(s=="[]"&&t=="()") ans1++;
	if(s=="[]"&&t=="8<") ans2++;
	if(s=="()"&&t=="8<") ans1++;
	if(s=="()"&&t=="[]") ans2++;
}
int main()
{	
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i+=2)
	{
		string s=s1.substr(i,2);
		string t=s2.substr(i,2);
		fun(s,t);
	}
	if(ans1>ans2) cout<<"TEAM 1 WINS"<<endl;
	else if(ans1==ans2) cout<<"TIE"<<endl;
	else cout<<"TEAM 2 WINS"<<endl;
}		