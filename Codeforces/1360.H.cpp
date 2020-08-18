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
		int n,m;
		cin>>n>>m;
		set<ll> X;
		vector<string> V(n);
		for(int i=0;i<n;i++)
		{
			ll x=0;
			cin>>V[i];
			reverse(all(V[i]));
			for(int j=0;j<m;j++)
			{
				x+=(1ll<<j)*(V[i][j]-'0');
			}
			X.insert(x);
		}
		// sort(all(X));
		ll low=0,high=(1ll<<m)-1;
		ll k=high+1-n;
		ll ans=-1;
		while(low<=high)
		{
			ll mid=low+(high-low)/2;
			int cnt=0;
			for(auto x:X)
			{
				if(x<mid) cnt++;
			}
			if(mid-cnt<(k-1)/2)
			{
				low=mid+1;
			}
			else if(mid-cnt>(k-1)/2)
			{
				high=mid-1;
			}
			else
			{
				while(X.count(mid)) mid++;
				ans=mid;
				break;
			}
		}
		string s; 
		for(int i=0;i<m;i++)
		{
			s+='0'+((ans>>i)&1);
		}
		reverse(all(s));
		cout<<s<<endl;
	}
}		