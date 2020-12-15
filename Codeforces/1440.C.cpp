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
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n,m;
		cin>>n>>m;
		// n = rng()%20+2,m=rng()%20+2;
		vector<string> V(n);
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=0;j<m;j++)
		// 	{
		// 		V[i].push_back('0' + rng()%2);
		// 	}
		// }
		// vector<string> VV = V;
		take(V,0,n);
		vector<vector<pair<int,int>>> Moves;
		if(m%2)
		{
			for(int i=0;i<n;i++)
			{
				if(V[i][m-1]=='0') continue;
				if(i+1<n) Moves.push_back({{i,m-1},{i+1,m-2},{i,m-2}});
				else
				{
					Moves.push_back({{i,m-1},{i-1,m-2},{i,m-2}});
				}
				V[i][m-1] = '0' + 1 - (V[i][m-1]-'0');
				V[i][m-2] = '0' + 1 - (V[i][m-2]-'0');
				if(i+1<n) V[i+1][m-2] = '0' + 1 - (V[i+1][m-2]-'0');
				else
				{
					V[i-1][m-2] = '0' + 1 - (V[i-1][m-2]-'0');
				}
			}
		}
		if(n%2)
		{
			for(int j=0;j<m;j++)
			{
				if(V[n-1][j]=='0') continue;
				if(j+1<m-1) Moves.push_back({{n-1,j},{n-2,j},{n-2,j+1}});
				else Moves.push_back({{n-1,j},{n-2,j},{n-2,j-1}});
				V[n-1][j] = '0' + 1 - (V[n-1][j]-'0');
				if(j+1<m-1) V[n-2][j+1] = '0' + 1 - (V[n-2][j+1]-'0');
				else V[n-2][j-1] = '0' + 1 - (V[n-2][j-1]-'0');
				V[n-2][j] = '0' + 1 - (V[n-2][j]-'0');
			}
		}
		// for(auto v:V)
		// {
		// 	cout<<v<<endl;
		// }
		// cout<<endl;
		for(int i=0;i<n-1;i+=2)
		{
			for(int j=0;j<m-1;j+=2)
			{
				if(V[i][j]=='0'&&V[i+1][j]=='0'&&V[i][j+1]=='0'&&V[i+1][j+1]=='0')
				{
					continue;
				} // Ones
				else if(V[i][j]=='1'&&V[i+1][j]=='0'&&V[i][j+1]=='0'&&V[i+1][j+1]=='0')
				{
					Moves.push_back({{i,j},{i+1,j},{i,j+1}});
					Moves.push_back({{i,j+1},{i,j},{i+1,j+1}});
					Moves.push_back({{i,j},{i+1,j},{i+1,j+1}});
				}
				else if(V[i][j]=='0'&&V[i+1][j]=='1'&&V[i][j+1]=='0'&&V[i+1][j+1]=='0')
				{
					Moves.push_back({{i,j},{i+1,j},{i+1,j+1}});
					Moves.push_back({{i,j+1},{i,j},{i+1,j}});
					Moves.push_back({{i,j+1},{i+1,j},{i+1,j+1}});
				}
				else if(V[i][j]=='0'&&V[i+1][j]=='0'&&V[i][j+1]=='1'&&V[i+1][j+1]=='0')
				{
					Moves.push_back({{i,j+1},{i,j},{i+1,j+1}});
					Moves.push_back({{i,j+1},{i,j},{i+1,j}});
					Moves.push_back({{i,j+1},{i+1,j},{i+1,j+1}});
				}
				else if(V[i][j]=='0'&&V[i+1][j]=='0'&&V[i][j+1]=='0'&&V[i+1][j+1]=='1')
				{
					Moves.push_back({{i+1,j+1},{i+1,j},{i,j+1}});
					Moves.push_back({{i,j+1},{i,j},{i+1,j+1}});
					Moves.push_back({{i,j},{i+1,j},{i+1,j+1}});
				} // Twos
				else if(V[i][j]=='1'&&V[i+1][j]=='1'&&V[i][j+1]=='0'&&V[i+1][j+1]=='0')
				{
					Moves.push_back({{i,j},{i,j+1},{i+1,j+1}});
					Moves.push_back({{i+1,j+1},{i+1,j},{i,j+1}});
				}
				else if(V[i][j]=='1'&&V[i+1][j]=='0'&&V[i][j+1]=='1'&&V[i+1][j+1]=='0')
				{
					Moves.push_back({{i,j},{i+1,j},{i+1,j+1}});
					Moves.push_back({{i+1,j+1},{i+1,j},{i,j+1}});
				}
				else if(V[i][j]=='0'&&V[i+1][j]=='1'&&V[i][j+1]=='0'&&V[i+1][j+1]=='1')
				{
					Moves.push_back({{i,j},{i,j+1},{i+1,j+1}});
					Moves.push_back({{i,j},{i+1,j},{i,j+1}});
				}
				else if(V[i][j]=='0'&&V[i+1][j]=='0'&&V[i][j+1]=='1'&&V[i+1][j+1]=='1')
				{
					Moves.push_back({{i,j},{i+1,j},{i+1,j+1}});
					Moves.push_back({{i,j},{i+1,j},{i,j+1}});
				}
				else if(V[i][j]=='1'&&V[i+1][j]=='0'&&V[i][j+1]=='0'&&V[i+1][j+1]=='1')
				{
					Moves.push_back({{i,j},{i,j+1},{i+1,j}});
					Moves.push_back({{i+1,j+1},{i+1,j},{i,j+1}});
				}
				else if(V[i][j]=='0'&&V[i+1][j]=='1'&&V[i][j+1]=='1'&&V[i+1][j+1]=='0')
				{
					Moves.push_back({{i,j},{i,j+1},{i+1,j+1}});
					Moves.push_back({{i+1,j+1},{i+1,j},{i,j}});
				} //Two
				else if(V[i][j]=='1'&&V[i][j+1]=='1'&&V[i+1][j]=='1'&&V[i+1][j+1]=='1')
				{
					Moves.push_back({{i,j},{i,j+1},{i+1,j}});
					Moves.push_back({{i+1,j+1},{i+1,j},{i,j+1}});
					Moves.push_back({{i,j+1},{i,j},{i+1,j+1}});
					Moves.push_back({{i,j},{i+1,j},{i+1,j+1}});
				}
				else
				{
					vpii X;
					for(int x=i;x<i+2;x++)
					{
						for(int y=j;y<j+2;y++)
						{
							if(V[x][y]=='1') X.push_back({x,y});
						}
					}
					Moves.push_back(X);
				}
				V[i][j]='0';
				V[i+1][j]='0';
				V[i][j+1]='0';
				V[i+1][j+1]='0';
				// for(auto v:V)
				// {
				// 	cout<<v<<endl;
				// }
				// cout<<endl;
			}
			
		}
		cout<<Moves.size()<<endl;
		// if(Moves.size()>n*m)
		// {
		// 	cout<<n<<" "<<m<<" "<<Moves.size()<<endl;
		// 	for(int i=0;i<n;i++)
		// 	{
		// 		cout<<VV[i]<<endl;
		// 	}
		// 	break;
		// }
		for(auto mo:Moves)
		{
			for(auto c:mo)
			{
				cout<<c.first+1<<" "<<c.second+1<<" ";
			}
			cout<<endl;
		}

	}
}	