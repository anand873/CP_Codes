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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	test()
	{
		int n;
		cin>>n;
		vi A(n);
		take(A,0,n);
		vvi In(205);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			In[A[i]].push_back(i);
		}
		for(int i=1;i<205;i++)
		{
			ans=max(ans,(int)In[i].size());
		}
		vvi BS(n+1,vi(205));//,FS(n+1,vi(205));
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<205;j++)
			{
				BS[i+1][j]=BS[i][j];
			}
			BS[i+1][A[i]]++;
		}
		for(int i=1;i<205;i++)
		{
			if(In[i].size()<2) continue;
			int fi=0;
			int la=In[i].size()-1;
			int how=1;
			while(fi<la)
			{
				int ma=0;
				for(int k=1;k<205;k++)
				{
					ma=max(ma,BS[In[i][la]][k]-BS[In[i][fi]+1][k]);
				}
				//cout<<i<<" "<<In[i][fi]<<" "<<In[i][la]<<" "<<ma<<endl;
				ans=max(ans,2*how+ma);
				fi++;
				la--;
				how++;
			}

		}
		cout<<ans<<endl;





		// FS[n][A[n-1]]++;
		// for(int i=n-1;i>0;i--)
		// {
		// 	for(int j=1;j<205;j++)
		// 	{
		// 		FS[i][j]=FS[i+1][j];
		// 	}
		// 	FS[i][A[i-1]]++;
		// }
		// for(int i=1;i<=n;i++)
		// {
		// 	for(int j=1;j<=3;j++)
		// 	{
		// 		cout<<BS[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// int ans=1;
		// for(int i=1;i<=n;i++)
		// {
		// 	for(int j=i+1;j<=n;j++)
		// 	{
		// 		int ma=0;
		// 		for(int k=1;k<205;k++)
		// 		{
		// 			ma=max(ma,BS[j-1][k]-BS[i][k]);
		// 		}
		// 		//if(i==2&&j==7) cout<<ma<<endl;
		// 		for(int k=1;k<205;k++)
		// 		{
		// 			ans=max(ans,2*min(BS[i][k],FS[j][k])+ma);
		// 		}
		// 		//if(i==2&&j==7) cout<<ans<<endl;
		// 	}
		// }
		// cout<<ans<<endl;



	}
}		