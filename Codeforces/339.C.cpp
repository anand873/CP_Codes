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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

const int INF = 1e5;

int main()
{
	string s;
	cin>>s;
	int m;
	cin>>m;
	vvi dp(m+1,vi(11));
	vvi Ans(m+1,vi(11));
	for(int i=0;i<10;i++)
	{
		if(s[i]=='1') dp[1][i+1]=i+1;
		else dp[1][i+1]=INF;
	}
	for(int i=2;i<=m;i++)
	{
		if(i%2)
		{
			//Left
			for(int j=1;j<=10;j++) dp[i][j]=INF;
			for(int last=0;last<10;last++)
			{
				for(int curr=0;curr<10;curr++)
				{
					if(last==curr) continue;
					if(dp[i-1][last+1]+curr+1>0&&s[curr]=='1')
					{
						if(dp[i][curr+1]>dp[i-1][last+1]+curr+1)
						{
							dp[i][curr+1]=dp[i-1][last+1]+curr+1;
							Ans[i][curr+1]=last+1;
						}
					}
				}
			}
		}
		else
		{
			//Right
			for(int j=1;j<=10;j++) dp[i][j]=-INF;
			for(int last=0;last<10;last++)
			{
				for(int curr=0;curr<10;curr++)
				{
					if(last==curr) continue;
					if(dp[i-1][last+1]-curr-1<0&&s[curr]=='1')
					{
						if(dp[i][curr+1]<dp[i-1][last+1]-curr-1)
						{
							dp[i][curr+1]=dp[i-1][last+1]-curr-1;
							Ans[i][curr+1]=last+1;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=10;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	vi A;
	int x;
	bool can=false;
	for(int j=1;j<=10;j++)
	{
		if(m==1||Ans[m][j]!=0) {can=true;x=Ans[m][j];A.push_back(j);break;}
	}
	if(!can) cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int i=m-1;i>0;i--)
		{
			A.push_back(x);
			x=Ans[i][x];
		}
		reverse(all(A));
		prin(A);
	}



}		