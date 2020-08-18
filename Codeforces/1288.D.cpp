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

int n,m;
vvl A(3*MAX,vl(10));
int ans1,ans2;

bool ok(ll x)
{
	vl Temp(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			Temp[i]+=(A[i][j]>=x)*(1<<(m-1-j));
	}
	//cout<<x<<endl;
	//for(auto t:Temp) cout<<t<<" ";
	//cout<<endl;
	map<ll,ll> M;
	for(int i=0;i<n;i++)
	{
		M[Temp[i]]=i+1;
	}
	for(auto mmm:M)
	{
		for(auto mm:M)
		{
			if((mmm.first|mm.first)==(1<<m)-1) {ans1=mmm.second;ans2=mm.second;return true;}
		}
	}
	return false;

}

int main()
{	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) cin>>A[i][j];
	}
	ll low=0;
	ll high=1e9+5;
	while(low<=high)
	{
		//cout<<high<<" "<<low<<endl;
		ll mid=low+(high-low)/2;
		if(ok(mid))
		{
			low=mid+1;
		}
		else high=mid-1;
	}	
	cout<<ans1<<" "<<ans2<<endl;
}