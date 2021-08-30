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
const int MOD = 1e9+7,MAX = 5e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		vi D(n+1),K(n+1);
		for(int i=0;i<n;i++)
		{
			D[i+1] = D[i];
			K[i+1] = K[i];
			if(s[i]=='D')
			{
				D[i+1]++;
			}
			else
			{
				K[i+1]++;
			}
		}

		map<pii,int> M;
		M[{D[1],K[1]}] = 1;
		vi dp(n+1);
		dp[1] = 1;
		for(int i=2;i<=n;i++)
		{
			int g = __gcd(D[i],K[i]);
			int d = D[i]/g;
			int k = K[i]/g;

			if(M.find({d,k})==M.end())
			{
				dp[i]=1;
				M[{d,k}] = i;
			}
			else
			{
				dp[i] = dp[M[{d,k}]] + 1;
				M[{d,k}] = i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<dp[i]<<" ";
		}
		cout<<endl;
		

	}
}	