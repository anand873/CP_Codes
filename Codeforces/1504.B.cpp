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
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		vi bal(n);
		bal[0] = a[0] - '0';
		for(int i=1;i<n;i++)
		{
			bal[i] = bal[i-1] + (a[i]-'0');
		}
		int par = 0;
		bool can = true;
		for(int i=n-1;i>=0;i--)
		{
			if((par && a[i]!=b[i]) || (!par && a[i]==b[i])) continue;
			else
			{
				if(bal[i]*2 == i+1) par^=1;
				else {can = false;break;}
			}
		}
		if(can) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}	