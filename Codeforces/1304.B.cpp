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
	int n,m;
	cin>>n>>m;
	set<string> S;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		S.insert(s);
	}
	vector<string> St;
	vector<string> En;
	vector<string> EQ;
	int eq=0;
	set<string> DD;
	for(auto s:S)
	{
		if(DD.count(s)) continue;
		string ss=s;
		reverse(all(ss));
		if(S.count(ss))
		{
			if(ss==s&&eq==0)
			{
				eq++;
				EQ.push_back(s);
			}
			else if(ss==s&&eq!=0) continue;
			else
			{
				DD.insert(s);
				DD.insert(ss);
				St.push_back(s);
				En.push_back(ss);
			}
		}
	}
	cout<<m*(St.size()+En.size()+eq)<<endl;
	for(int i=0;i<St.size();i++) cout<<St[i];
	if(eq) cout<<EQ[0];
	for(int i=En.size()-1;i>=0;i--) cout<<En[i];
	cout<<endl;
}		