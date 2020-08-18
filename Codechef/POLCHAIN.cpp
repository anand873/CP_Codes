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
	int n;
	cin>>n;
	vector<vpii> C(n+1);
	vpii X(n+1,{101,-101}),Y(n+1,{101,-101});
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		for(int j=0;j<m;j++)
		{
			int x,y;
			cin>>x>>y;
			C[i].push_back({x,y});
			
			X[i].first=min(X[i].first,C[i][j].first);
			X[i].second=max(X[i].second,C[i][j].first);
			Y[i].first=min(Y[i].first,C[i][j].second);
			Y[i].second=max(Y[i].second,C[i][j].second);
		}
	}
	if(n==2)
	{
		if(X[1].second-X[1].first>=X[2].second-X[2].first&&Y[1].second-Y[1].first>=Y[2].second-Y[2].first)
		{
			int x11=X[1].first,x12=X[1].second,x21=X[2].first,x22=X[2].second;
			int y11=Y[1].first,y12=Y[1].second,y21=Y[2].first,y22=Y[2].second;
			int ans=abs(x11-x21)+abs(y11-y21);
			ans=min(ans,abs(x11-x21)+abs(y12-y22));
			ans=min(ans,abs(x12-x22)+abs(y11-y21));
			ans=min(ans,abs(x12-x22)+abs(y12-y22));
			printf("%.10lf\n",(double)ans);
		}
		else if(X[1].second-X[1].first<=X[2].second-X[2].first&&Y[1].second-Y[1].first<=Y[2].second-Y[2].first)
		{
			int x11=X[1].first,x12=X[1].second,x21=X[2].first,x22=X[2].second;
			int y11=Y[1].first,y12=Y[1].second,y21=Y[2].first,y22=Y[2].second;
			int ans=abs(x11-x21)+abs(y11-y21);
			ans=min(ans,abs(x11-x21)+abs(y12-y22));
			ans=min(ans,abs(x12-x22)+abs(y11-y21));
			ans=min(ans,abs(x12-x22)+abs(y12-y22));
			printf("%.10lf\n",(double)ans);
		}
		else cout<<-1<<endl;
		
	}
}		