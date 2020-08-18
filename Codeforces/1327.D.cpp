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

const int MOD = 1e9+7,MAX = 2e5+5;
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
	vector<set<int>> F(MAX);
	for(int i=1;i<MAX;i++)
	{
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				F[i].insert(j);
				F[i].insert(i/j);
			}
		}
	}
	test()
	{
		int n;
		cin>>n;
		vi C(n+1),P(n+1);
		take(P,1,n);
		take(C,1,n);
		int mi=MOD;
		vector<bool> Vis(n+1);
		vvi CC(n+1);
		for(int i=1;i<=n;i++)
		{
			if(Vis[i]) continue;
			Vis[i]=true;
			int num=i;
			int k=1;
			CC[i].push_back(i);
			while(i!=P[num])
			{
				Vis[P[num]]=true;
				CC[i].push_back(P[num]);
				num=P[num];
			}
		}
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			//prin(CC[i]);
			if(CC[i].size()==0) continue;
			else
			{
				for(auto jump:F[CC[i].size()])
				{
					for(int st=0;st<jump;st++)
					{
						bool allsame=true;
						for(int j=st;j<CC[i].size();j+=jump)
						{
							if(C[CC[i][j]]!=C[CC[i][st]]) allsame=false;
						}
						if(allsame) ans=min(ans,jump);
					}
					
				}
			}
		}
		cout<<ans<<endl;
	}
}		