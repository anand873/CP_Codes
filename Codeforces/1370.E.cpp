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

const int MOD = 1e9+7,MAX = 1e6+5;
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
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	int zero=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') zero++;
		if(t[i]=='0') zero--;
	}
	if(zero) cout<<-1<<endl;
	else
	{
		vector<int> In;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				In.push_back(i);
			}
		}
		if(In.size()==0)
		{
			cout<<0<<endl;
		}
		else
		{
			int ans=0;
			int curr=1;
			vi Inn;
			for(int i=0;i<In.size();i++)
			{
				Inn.push_back(In[i]);
			}
			for(int i=0;i<In.size();i++)
			{
				Inn.push_back(In[i]);
			}
			for(int i=1;i<Inn.size();i++)
			{
				if(s[Inn[i]]==s[Inn[i-1]]) curr++;
				else
				{
					ans=max(ans,curr);
					curr=1;
				}
			}
			ans=max(ans,curr);
			cout<<ans<<endl;
		}
	}

}		