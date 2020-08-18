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

const int MOD = 1e9+7,MAX = 1e6+5;
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
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	test()
	{
		int n,m;
		cin>>n>>m;
		vector<string> V(n);
		take(V,0,n);

		queue<pii> Q;
		Q.push({n-1,m-1});
		int howg=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(V[i][j]=='G') howg++;
			}
		}
		vector<vector<bool>> vis(n,vector<bool>(m));
		vis[n-1][m-1]=true;
		while(!Q.empty())
		{
			pii X = Q.front();
			Q.pop();
			int x=X.first,y=X.second;

			if(x-1>=0&&!vis[x-1][y])
			{
				if(V[x-1][y]=='.'||V[x-1][y]=='.')
				{
					vis[x-1][y]=true;
					Q.push({x-1,y});
				}
				if(V[x-1][y]=='B')
				{
					// what(V[x-1][y]);
					V[x][y]='#';
				}
			}
			if(x+1<n&&!vis[x+1][y])
			{
				if(V[x+1][y]=='.'||V[x+1][y]=='.')
				{
					vis[x+1][y]=true;
					Q.push({x+1,y});
				}
				if(V[x+1][y]=='B')
				{
					// what(V[x+1][y]);
					V[x][y]='#';
				}
			}
			if(y+1<m&&!vis[x][y+1])
			{
				if(V[x][y+1]=='.'||V[x][y+1]=='.')
				{
					vis[x][y+1]=true;
					Q.push({x,y+1});
				}
				if(V[x][y+1]=='B')
				{
					// what(V[x][y+1]);
					V[x][y]='#';
				}
			}
			if(y-1>=0&&!vis[x][y-1])
			{
				if(V[x][y-1]=='.'||V[x][y-1]=='.')
				{
					vis[x][y-1]=true;
					Q.push({x,y-1});
				}
				if(V[x][y-1]=='B')
				{
					// what(V[x][y-1]);
					V[x][y]='#';
				}
			}
		}

		// for(int i=0;i<n;i++) cout<<V[i]<<endl;

		Q.push({n-1,m-1});
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				vis[i][j]=false;
			}
		}
		bool bad=false;
		vis[n-1][m-1]=true;
		if(V[n-1][m-1]=='#')
		{
			if(howg) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
			continue;
		}
		while(!Q.empty())
		{
			pii X = Q.front();
			Q.pop();
			int x=X.first,y=X.second;

			if(x-1>=0&&!vis[x-1][y])
			{
				if(V[x-1][y]=='.'||V[x-1][y]=='.')
				{
					vis[x-1][y]=true;
					Q.push({x-1,y});
				}
				if(V[x-1][y]=='B')
				{
					bad=true;
					break;
				}
				if(V[x-1][y]=='G') howg--;
			}
			if(x+1<n&&!vis[x+1][y])
			{
				if(V[x+1][y]=='.'&&V[x+1][y]=='.')
				{
					vis[x+1][y]=true;
					Q.push({x+1,y});
				}
				if(V[x+1][y]=='B')
				{
					bad=true;
					break;
				}
				if(V[x+1][y]=='G') howg--;
			}
			if(y+1<m&&!vis[x][y+1])
			{
				if(V[x][y+1]=='.'||V[x][y+1]=='.')
				{
					vis[x][y+1]=true;
					Q.push({x,y+1});
				}
				if(V[x][y+1]=='B')
				{
					bad=true;
					break;
				}
				if(V[x][y+1]=='G') howg--;
			}
			if(y-1>=0&&!vis[x][y-1])
			{
				if(V[x][y-1]=='.'||V[x][y-1]=='G')
				{
					vis[x][y-1]=true;
					Q.push({x,y-1});
				}
				if(V[x][y-1]=='B')
				{
					bad=true;
					break;
				}
				if(V[x][y-1]=='G') howg--;
			}
		}
		// cout<<bad<<" "<<howg<<endl;
		if(!bad&&howg==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

	}
}		