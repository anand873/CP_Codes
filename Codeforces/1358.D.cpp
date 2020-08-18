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
	fastio
	ll n,x;
	cin>>n>>x;
	vl D(n+1);
	for(int i=1;i<=n;i++) cin>>D[i];
	//prin(D);
	vl PS(2*n+1);
	for(int i=1;i<=n;i++)
	{
		PS[i]=PS[i-1]+D[i];
	}
	for(int i=1;i<=n;i++)
	{
		PS[n+i]=PS[n+i-1]+D[i];
	}
	//prin(PS);
	
	// Start on 1st of Month
	vl CS(2*n+1);
	for(int i=1;i<=n;i++)
	{
		CS[i]=CS[n+i]=D[i]*(D[i]+1)/2;
	}
	for(int i=1;i<=2*n;i++)
	{
		CS[i]+=CS[i-1];
	}
	//prin(CS);
	ll best=0;
	for(int i=1;i<=n;i++)
	{
		int low=i-1,high=2*n;
		int ans=0;
		while(low<=high)
		{
			int mid=low+(high-low)/2;
			//cout<<mid<<": "<<PS[mid]-PS[i-1]<<endl;
			if(PS[mid]-PS[i-1]>x)
			{
				high=mid-1;
			}
			else 
			{
				ans=mid;
				low=mid+1;
			}
		}
		ll candi=CS[ans]-CS[i-1]+(x-PS[ans]+PS[i-1])*(x-PS[ans]+1+PS[i-1])/2;
		//cout<<ans<<": "<<candi<<endl;
		best=max(best,candi);
	}

	//End on 1st of Month

	// prin(PS);
	// prin(CS);
	for(int i=n+1;i<=2*n;i++)
	{
		int low=1,high=i;
		int ans=0;
		while(low<=high)
		{
			int mid=low+(high-low)/2;
			// cout<<mid<<": "<<PS[i]-PS[mid-1]<<endl;
			
			if(PS[i]-PS[mid-1]>=x)
			{
				ans=mid;
				low=mid+1;;
			}
			else 
			{
				high=mid-1;
			}
		}
		//cout<<ans<<": ";

		ll candi=CS[i]-CS[ans-1]-(PS[i]-PS[ans-1]-x)*(PS[i]+1-PS[ans-1]-x)/2;
		//cout<<candi<<endl;
		best=max(best,candi);
	}
	cout<<best<<endl;
}		