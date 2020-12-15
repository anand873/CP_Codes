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
		int n;
		cin>>n;
		vector<string> V(n);
		take(V,0,n);
		int total = 0;
		vi cntx(3),cnto(3);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(V[i][j]=='X')
				{
					cntx[(i+j)%3]++;
					total++;
				}
				else if(V[i][j]=='O')
				{
					cnto[(i+j)%3]++;
					total++;
				}
			}
		}
		bool done = false;
		for(int x=0;x<3;x++)
		{
			for(int o=0;o<3;o++)
			{
				if(x==o) continue;
				if(cntx[x]+cnto[o]<=total/3)
				{
					// cout<<cntx[x]<<" "<<cnto[o]<<" "<<total<<endl;
					for(int i=0;i<n;i++)
					{
						for(int j=0;j<n;j++)
						{
							if(V[i][j]=='X'&&(i+j)%3==x) V[i][j]='O';
							else if(V[i][j]=='O'&&(i+j)%3==o) V[i][j]='X';
						}
					}
					done=true;
				}
				if(done) break;
			}
			if(done) break;
		}
		for(int i=0;i<n;i++)
		{
			cout<<V[i]<<endl;
		}

	}	
}	