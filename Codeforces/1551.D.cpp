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
#define test() int q;cin>>q;while(q--)
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9,MAX = 3e5+5;
const ll INF = 1e18+5;

int main()
{
	fastio
	test()
	{
		int n,m,k;
		cin>>n>>m>>k;
		int tot = n*m;

		if(n%2==0)
		{
			if(k%2==0 && (k <= n*(m/2)))
			{
				cout<<"YES\n";
				vvi M(n,vi(m,-1));
				int rem = k;
				int curr = 0;
				for(int i=0;i<m;i+=2)
				{
					int how = min(n,rem);
					for(int j=0;j<how;j++)
					{
						M[j][i] = curr;
						M[j][i+1] = curr;

						curr = 1-curr;
					}
					rem = max(0,rem - n);
					curr = 1-curr;
				}
				curr = 2;
				for(int i=0;i<m;i++)
				{
					for(int j=0;j<n;j+=2)
					{
						if(M[j][i]==-1)
						{
							M[j][i] = curr;
							M[j+1][i] = curr;
						}
						curr = 5 - curr;
					}
					if((n/2)%2==0) curr = 5 - curr;
				}

				for(int i=0;i<n;i++)
				{
					for(int j=0;j<m;j++)
					{
						cout<<(char)('a'+M[i][j]);
					}
					cout<<"\n";
				}
			}
			else cout<<"NO\n";
		}
		else
		{
			if(k%2 == (m/2)%2 && (k>=(m/2)))
			{
				cout<<"YES\n";
				vvi M(n,vi(m,-1));
				int curr = 0;
				for(int i=0;i<m;i+=2)
				{
					M[0][i] = M[0][i+1] = curr;
					curr = 1-curr;
				}
				if((m/2) % 2==0) curr = 1-curr;
				k -= m/2;

				int rem = k;

				for(int i=0;i<m;i+=2)
				{
					int how = min(n-1,rem);
					for(int j=0;j<how;j++)
					{
						M[j+1][i] = curr;
						M[j+1][i+1] = curr;

						curr = 1-curr;
					}
					rem = max(0,rem - n+1);
					curr = 1-curr;
				}

				curr = 2;
				for(int i=0;i<m;i++)
				{
					for(int j=1;j<n;j+=2)
					{
						if(M[j][i]==-1)
						{
							M[j][i] = curr;
							M[j+1][i] = curr;
						}
						curr = 5 - curr;
					}
					if(((n-1)/2)%2==0) curr = 5 - curr;
				}

				for(int i=0;i<n;i++)
				{
					for(int j=0;j<m;j++)
					{
						cout<<(char)('a'+M[i][j]);
					}
					cout<<"\n";
				}

			}
			else cout<<"NO\n";
		}

	}
}	