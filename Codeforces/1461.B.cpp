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

void testcase()
{
	int n,m;
	cin>>n>>m;
	vector<string> C(n);
	take(C,0,n);

	vvi dpL(n,vi(m));
	vvi dpR(n,vi(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(C[i][j]=='*')
			{
				int k=j;
				while(k>=0&&C[i][k]=='*') {dpL[i][j]++;k--;}
				k=j;
				while(k<m&&C[i][k]=='*') {dpR[i][j]++;k++;}
			}
		}
	}
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(C[i][j]=='*')
			{
				int h=0;
				for(int row=i;row<n;row++)
				{
					// cout<<dpL[row][j]<<" "<<dpR[row][j]<<endl;
					if(min(dpL[row][j],dpR[row][j])>=row-i+1) h++;
					else break;
				}
				ans += h;
			}
		}
	}
	cout<<ans<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		testcase();
	}
}	