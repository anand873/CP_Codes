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
	fastio
	test()
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		vl WH;
		vl E,O;
		E.push_back(0);
		O.push_back(0);
		string ss;
		ll val=1;
		for(int i=0;i<n;i++)
		{
			if(s[i]!='*')
			{
				ss.push_back(s[i]);
				WH.push_back(val);
				val=1;
			}
			else val++;
		}
		WH.push_back(val);
		for(int i=0;i<WH.size()-1;i++)
		{
			if(i%2) {E.push_back(WH[i]);O.push_back(0);}
			else {O.push_back(WH[i]);E.push_back(0);}
		}
		for(int i=1;i<=WH.size()-1;i++)
		{
			E[i]+=E[i-1];
			O[i]+=O[i-1];
		}

		int l=ss.length();
		vl dp(l+1);
		int curr=0;
		vector<int> CO;
		for(int i=0;i<l;i++)
		{
			if(ss[i]=='(')
			{
				CO.push_back(i);
			}
			else
			{
				if(!CO.size())
				{
					if(i%2) dp[i+1]=E[i+1];
					else dp[i+1]=O[i+1];
				}
				else
				{
					if(i%2)
					{
						dp[i+1]=E[i+1]-E[CO.back()+1];
					}
					else
					{
						dp[i+1]=O[i+1]-O[CO.back()+1];
					}
					CO.pop_back();
				}
			}
		}

		for(int i=1;i<=l;i++)
		{
			dp[i]+=dp[i-1];
			dp[i]%=MOD;
			if(i>1)
			{
				dp[i-1]*=WH[i-1];
				dp[i-1]%=MOD;
			}
		}
		dp[l]*=WH[l];
		dp[l]%=MOD;
		for(int i=1;i<=l;i++)
		{
			dp[i]+=dp[i-1];
			dp[i]%=MOD;
		}

		ll ans=dp[l];
		ans*=powN(n,MOD-2);
		ans%=MOD;
		ans*=powN(n+1,MOD-2);
		ans%=MOD;
		ans*=2;
		ans%=MOD;
		cout<<ans<<endl;
	}
}
