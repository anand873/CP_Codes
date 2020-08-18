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
#define test(t) int t;cin>>t;while(t--)
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl

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
	test(T)
	{
		string s;
		cin>>s;
		string t;
		cin>>t;
		vvi F(s.length()+5,vi(26));
		for(int i=s.length()-1;i>=0;i--)
		{
			for(int j=0;j<26;j++)
			{
				F[i+1][j]=F[i+2][j];
			}
			F[i+1][s[i]-'a']=i+1;
		}
		int last=1,ans=1;
		int f=0;
		for(int i=0;i<t.length();i++)
		{
			if(last>s.length())
			{
				ans++;
				last=1;
			}
			if(F[last][t[i]-'a']!=0)
				last = F[last][t[i]-'a']+1;
			else
			{
				last = 1;
				ans++;
				if(F[last][t[i]-'a']!=0)
					last = F[last][t[i]-'a']+1;
				else {f=1;break;}
			}
		}
		if(f) cout<<-1<<endl;
		else cout<<ans<<endl;

	}
}