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
int MOD = 1e9+7,MAX = 4e3+5;
const ll INF = 1e18+5;

int main()
{
	fastio
	vi F(MAX,1);

	for(int i=3;i<MAX;i+=2)
	{
		for(int j=i;j<MAX;j+=2*i)
		{
			F[j]++;
		}
	}

	for(int i=1;i<MAX;i+=2)
	{
		F[i] = (i+3)/2 - F[i];
	}
	cout<<F[21]<<endl;
	vl Ans(1e3+5,-1);

	for(int i=1;i<4e3+2;i+=2)
	{
		for(int j=i;j<4e3+5;j+=2*i)
		{
			if(j%4==1) Ans[(j-1)/4] += (ll)F[j/i]*i;
		}
	}
	test()
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cout<<Ans[i]<<" ";
		}
		cout<<"\n";
	}
}