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

const int MOD = 1e9+7,MAX = 2e6+5;
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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

/*

	A lot of Case work here!!!
				|
				|    .(x1,y1)
				|	/
				|  /
				| /
	---------------------------
				|\
				| \
				|  \
				|   \
				|    .(x2,y2)

	Update Min and Max lines for every point.
	Manage Vertical lines

	**NO F_ing Idea Why atan() is Not Working**

*/

const double pi = 4*atan(1.0);

int main()
{
	int n;
	cin>>n;
	double maxangle=-360,minangle=360;
	for(int i=0;i<n;i++)
	{
		double x,y;
		cin>>x>>y;
		if(x>0)
		{
			minangle=min(minangle,atan(y/x)*180.0/pi);
			maxangle=max(maxangle,atan(y/x)*180.0/pi);
		}
		else if(x<0)
		{
			if(y>=0)
			{
				minangle=min(minangle,(pi+atan(y/x))*180.0/pi);
				maxangle=max(maxangle,(pi+atan(y/x))*180.0/pi);
			}
			else
			{
				minangle=min(minangle,(-pi+atan(y/x))*180.0/pi);
				maxangle=max(maxangle,(-pi+atan(y/x))*180.0/pi);
			}
		}
		else if(x==0)
		{
			if(y>0)
			{
				minangle=min(minangle,90.0);
				maxangle=max(maxangle,90.0);
			}
			else
			{
				minangle=min(minangle,-90.0);
				maxangle=max(maxangle,-90.0);
			}
		}
	}
	double ans=min(360.0,maxangle-minangle);
	printf("%.10lf\n",ans);
}		