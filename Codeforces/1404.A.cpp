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
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		bool can=true;
		vi vis(n);
		for(int i=0;i<n;i++)
		{
			if(vis[i]) continue;
			set<char> S;
			for(int j=i;j<n;j+=k)
			{
				vis[j]=true;
				if(s[j]!='?') S.insert(s[j]);
			}
			if(S.size()==2)
			{
				can=false;
				break;
			}
			else if(S.size()==1)
			{
				char x = *(S.begin());
				for(int j=i;j<n;j+=k) s[j]=x;
			}
		}
		if(!can) {cout<<"NO"<<endl;continue;}
		vvi dp(n+1,vi(3));
		for(int i=0;i<n;i++)
		{
			dp[i+1] = dp[i];
			if(s[i]=='0') dp[i+1][0]++;
			else if(s[i]=='1') dp[i+1][1]++;
			else dp[i+1][2]++;  
		}
		for(int i=0;i+k<=n;i++)
		{
			int a2 = dp[i+k][2]-dp[i][2];
			int a1 = dp[i+k][1]-dp[i][1];
			int a0 = dp[i+k][0]-dp[i][0];
 
			if((a1-a0+a2)%2==0&&a1-a0+a2>=0&&a2-a1+a0>=0)
			{
				continue;
			}
			else
			{
				can=false;
			}
 		}
 		if(can) cout<<"YES"<<endl;
 		else cout<<"NO"<<endl;


	}
}	