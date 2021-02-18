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
		vector<vector<char>> V(n+1,vector<char>(n+1));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>V[i][j];
			}
		}
		vpii da, db, ab;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(V[i][j]=='a'&&V[j][i]=='a') da.push_back({i,j});
				else if(V[i][j]=='b'&&V[j][i]=='b') db.push_back({i,j});
				else ab.push_back({i,j});
			}
		}
		if(da.size()>0)
		{
			cout<<"YES"<<endl;
			cout<<da[0].first<<" ";
			for(int i=0;i<m;i++)
			{
				if(i%2) cout<<da[0].first<<" ";
				else cout<<da[0].second<<" ";
			}
			cout<<endl;
		}
		else if(db.size()>0)
		{
			cout<<"YES"<<endl;
			cout<<db[0].first<<" ";
			for(int i=0;i<m;i++)
			{
				if(i%2) cout<<db[0].first<<" ";
				else cout<<db[0].second<<" ";
			}
			cout<<endl;
		}
		else
		{
			if(n==2)
			{
				if(m==1)
				{
					cout<<"YES"<<endl;
					cout<<"1 2"<<endl;
				}
				else if(m==3)
				{
					cout<<"YES"<<endl;
					cout<<"1 2 1 2"<<endl;
				}
				else cout<<"NO"<<endl;
			}
			else
			{
				cout<<"YES"<<endl;
				vector<char> M(4);
				M[1] = V[1][2];
				M[2] = V[2][3];
				M[3] = V[3][1];
				if(M[1]==M[2]&&M[2]==M[3])
				{
					cout<<3<<" ";
					for(int i=0;i<m;i++)
					{
						cout<<i%3 + 1<<" ";
					}
				}
				else if(M[1]==M[2])
				{
					if(m%2==0)
					{
						int x = m/2;
						vector<int> X;
						X.push_back(2);
						for(int i=0;i<x;i++)
						{
							X.push_back(((3-i)%3 +3)%3 + 1);
						}
						reverse(all(X));
						for(int i=0;i<x;i++)
						{
							X.push_back((2+i)%3 + 1);
						}
						prinv(X);
					}
					else
					{
						int x = (m+1)/2;
						vector<int> X;
						for(int i=0;i<x;i++)
						{
							X.push_back(((2-i)%3 +3)%3 + 1);
						}
						reverse(all(X));
						for(int i=0;i<x;i++)
						{
							X.push_back(i%3 + 1);
						}
						prinv(X);
					}
				}
				else if(M[2]==M[3])
				{
					if(m%2==0)
					{
						int x = m/2;
						vector<int> X;
						X.push_back(3);
						for(int i=0;i<x;i++)
						{
							X.push_back(((1-i)%3 +3)%3 + 1);
						}
						reverse(all(X));
						for(int i=0;i<x;i++)
						{
							X.push_back((3+i)%3 + 1);
						}
						prinv(X);
					}
					else
					{
						int x = (m+1)/2;
						vector<int> X;
						for(int i=0;i<x;i++)
						{
							X.push_back(((0-i)%3 +3)%3 + 1);
						}
						reverse(all(X));
						for(int i=0;i<x;i++)
						{
							X.push_back((i+1)%3 + 1);
						}
						prinv(X);
					}
				}
				else if(M[1]==M[3])
				{
					if(m%2==0)
					{
						int x = m/2;
						vector<int> X;
						X.push_back(1);
						for(int i=0;i<x;i++)
						{
							X.push_back(((1-i)%3 +3)%3 + 1);
						}
						reverse(all(X));
						for(int i=0;i<x;i++)
						{
							X.push_back((1+i)%3 + 1);
						}
						prinv(X);
					}
					else
					{
						int x = (m+1)/2;
						vector<int> X;
						for(int i=0;i<x;i++)
						{
							X.push_back(((1-i)%3 +3)%3 + 1);
						}
						reverse(all(X));
						for(int i=0;i<x;i++)
						{
							X.push_back((i+2)%3 + 1);
						}
						prinv(X);
					}
				}
			}
		}

	}
}	