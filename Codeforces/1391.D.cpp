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
	int n,m;
	cin>>n>>m;
	vector<string> V(n);
	take(V,0,n);
	if(n>=4&&m>=4)
	{
		cout<<-1<<endl;
	}
	else
	{
		if(n==1||m==1) cout<<0<<endl;
		else
		{
			if(n==2)
			{
				string ns;
				for(int j=0;j<m;j++)
				{
					if(V[0][j]==V[1][j]) ns+='0';
				}
				int ans0 = 0,ans1=0;
				for(int j=0;j<m;j++)
				{
					if(ns[j]!=('0'+j%2)) ans0++;
					if(ns[j]!=('0'+(j+1)%2)) ans1++;
				}
				cout<<min(ans1,ans0)<<endl;
			}
			else if(m==2)
			{
				string ns;
				for(int j=0;j<n;j++)
				{
					if(V[j][0]==V[j][1]) ns+='0';
				}
				int ans0 = 0,ans1=0;
				for(int j=0;j<n;j++)
				{
					if(ns[j]!=('0'+j%2)) ans0++;
					if(ns[j]!=('0'+(j+1)%2)) ans1++;
				}
				cout<<min(ans1,ans0)<<endl;
			}
			else if(n==3)
			{
				vvi dp(m,vi(8,MOD));
				int init = 0;
				for(int i=0;i<3;i++)
				{
					init += (V[i][0]=='1')*(1<<i);
				}
				for(int i=0;i<8;i++)
				{
					dp[0][i] = i^init;
				}
				for(int i=0;i<m-1;i++)
				{
					init = 0;
					for(int j=0;j<3;j++)
					{
						init += (V[j][i]=='1')*(1<<j);
					}
					dp[i+1][2] = min(dp[i+1][2],dp[i][0]+init^2);
					dp[i+1][5] = min(dp[i+1][5],dp[i][0]+init^5);

					dp[i+1][4] = min(dp[i+1][4],dp[i][1]+init^4);
					dp[i+1][3] = min(dp[i+1][3],dp[i][1]+init^3);

					dp[i+1][0] = min(dp[i+1][0],dp[i][2]+init^0);
					dp[i+1][7] = min(dp[i+1][7],dp[i][2]+init^7);

					dp[i+1][1] = min(dp[i+1][1],dp[i][3]+init^1);
					dp[i+1][6] = min(dp[i+1][6],dp[i][3]+init^6);

					dp[i+1][1] = min(dp[i+1][1],dp[i][4]+init^1);
					dp[i+1][6] = min(dp[i+1][6],dp[i][4]+init^6);

					dp[i+1][7] = min(dp[i+1][7],dp[i][5]+init^7);
					dp[i+1][0] = min(dp[i+1][0],dp[i][5]+init^0);

					dp[i+1][4] = min(dp[i+1][4],dp[i][6]+init^4);
					dp[i+1][3] = min(dp[i+1][3],dp[i][6]+init^3);

					dp[i+1][5] = min(dp[i+1][5],dp[i][7]+init^5);
					dp[i+1][2] = min(dp[i+1][2],dp[i][7]+init^2);
				}
				prinv(dp[m-1]);
				int ans = MOD;
				for(int i=0;i<8;i++)
				{
					ans = min(ans,dp[m-1][i]);
				}
				cout<<ans<<endl;
			}
			else
			{
				vvi dp(n,vi(8,MOD));
				int init = 0;
				for(int i=0;i<3;i++)
				{
					init += (V[0][i]=='1')*(1<<i);
				}
				for(int i=0;i<8;i++)
				{
					dp[0][i] = i^init;
				}
				for(int i=0;i<n-1;i++)
				{
					init = 0;
					for(int j=0;j<3;j++)
					{
						init += (V[j][i]=='1')*(1<<j);
					}
					dp[i+1][2] = min(dp[i+1][2],dp[i][0]+init^2);
					dp[i+1][5] = min(dp[i+1][5],dp[i][0]+init^5);

					dp[i+1][4] = min(dp[i+1][4],dp[i][1]+init^4);
					dp[i+1][3] = min(dp[i+1][3],dp[i][1]+init^3);

					dp[i+1][0] = min(dp[i+1][0],dp[i][2]+init^0);
					dp[i+1][7] = min(dp[i+1][7],dp[i][2]+init^7);

					dp[i+1][1] = min(dp[i+1][1],dp[i][3]+init^1);
					dp[i+1][6] = min(dp[i+1][6],dp[i][3]+init^6);

					dp[i+1][1] = min(dp[i+1][1],dp[i][4]+init^1);
					dp[i+1][6] = min(dp[i+1][6],dp[i][4]+init^6);

					dp[i+1][7] = min(dp[i+1][7],dp[i][5]+init^7);
					dp[i+1][0] = min(dp[i+1][0],dp[i][5]+init^0);

					dp[i+1][4] = min(dp[i+1][4],dp[i][6]+init^4);
					dp[i+1][3] = min(dp[i+1][3],dp[i][6]+init^3);

					dp[i+1][5] = min(dp[i+1][5],dp[i][7]+init^5);
					dp[i+1][2] = min(dp[i+1][2],dp[i][7]+init^2);
				}

				int ans = MOD;
				for(int i=0;i<8;i++)
				{
					ans = min(ans,dp[n-1][i]);
				}
				cout<<ans<<endl;
			}
		}
	}

}	