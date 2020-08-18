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
	test()
	{
		int n,m,k;
		ll c;
		cin>>n>>m>>c>>k;
		vector<string> V(n);
		take(V,0,n);
		vvi S(n+1,vi(m+1));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(V[i][j]=='#') S[i+1][j+1]=1;
			}
		}

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				S[i][j]+=S[i][j-1];
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=2;j<=n;j++)
			{
				S[j][i]+=S[j-1][i];
			}
		}

		// for(int i=0;i<=n;i++)
		// {
		// 	for(int j=0;j<=m;j++)
		// 	{
		// 		cout<<S[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		ll cost=1e15+5;
		bool ekbhi=false;
		int low=1,high=max(n,m);
		while(low<=high)
		{
			int mid=low+(high-low)/2;
			bool hai=false;
			//what(mid);
			for(int i=mid;i<=n;i++)
			{
				for(int j=mid;j<=m;j++)
				{
					//cout<<S[min(n,i+mid-1)][min(m,j+mid-1)]+S[i-mid][j-mid]-S[i-mid][min(m,j+mid-1)]-S[min(n,i+mid-1)][j-mid]<<endl;
					if(S[min(n,i+mid-1)][min(m,j+mid-1)]+S[i-mid][j-mid]-S[i-mid][min(m,j+mid-1)]-S[min(n,i+mid-1)][j-mid]>=k)
					{
						cost=min(cost,c*mid);
						hai=true;
						break;
					}
				}
				if(hai) break;
			}
			//what(hai);
			if(hai) {high=mid-1;ekbhi=true;}
			else low=mid+1;
		}
		if(ekbhi) cout<<cost<<endl;
		else cout<<-1<<endl;
	}
}		