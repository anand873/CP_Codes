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

int main()
{
	int n;
	cin>>n;
	vector<string> V(n);
	take(V,0,n);
	int p=53;
	string ans;
	ans+=V[0];
	vl hash;
	hash.push_back(0);
	ll p_pow=1;
	for(auto c:V[0])
	{
		hash.push_back((hash.back()+(c-'A'+1)*p_pow)%MOD);
		p_pow=(p_pow*p)%MOD;
	}
	int last=hash.size()-1;
	for(int i=1;i<n;i++)
	{
		int len=1;
		bool chechhere=true;
		vl newhashvec={0};
		for(auto c:V[i])
		{
			newhash=(newhash+(c-'A'+1)*p_pow)%MOD;
			p_pow=(p_pow*p)%MOD;
			newhashvec.push_back(newhash);
		}
		for(int j=V[i+1].size();j>0;j--)
		{
			int len=V[i+1].size()-j+1;
			if(newhashvec.back()-newhashvec[j-1]!=(hash[last]-hash[last-len])*powN(p,len))
			{
				break;
			}
		}
		
	}
	prin(hash);
	cout<<ans<<endl;
	

}		