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
ll powN(ll a,ll p,ll mod)
{
	if(p==0) return 1;
	ll z=powN(a,p/2,mod);
	z=(z*z)%mod;
	if(p%2) z=(z*a)%mod;
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
	int w,h,r;
	cin>>w>>h>>r;
	vvi A(35,vi(35));
	for(int i=0;i<r;i++)
	{
		int x,y;
		cin>>x>>y;
		A[y/24024][x/24024]++;
	}
	int q=0;
	vector<pii> Vr;
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<30;j++)
		{
			if(A[i][j]==0)
			{
				q+=29-j;
				Vr.push_back({i,29-j});
			}
		}
	}
	cout<<30<<" "<<30<<" "<<q<<endl;
	for(auto vr:Vr)
	{
		for(int i=0;i<vr.second;i++)
			cout<<"1 "<<vr.first<<endl;
	}
}		