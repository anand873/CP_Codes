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
	int a,b,k;
	cin>>a>>b>>k;
	vector<int> X(a+b), Y(a+b);
	X[0] = 1;
	Y[0] = 1;
	// prinv(X);
	// prinv(Y);
	int ex = max(0,b - 1 - k);
	for(int i=1;i<=ex;i++) X[i] = 1;
	for(int i=0;i<min(k,b-1);i++)
	{
		X[a+b-1-i] = 1;
	}
	vector<int> K(a+b);
	for(int i=0;i<k;i++) K[a+b-1-i] = 1;
	int car = 0;
	for(int i=a+b-1;i>0;i--)
	{
		Y[i] = X[i]+K[i]+car;
		car = Y[i]/2;
		Y[i] %= 2;
	}
	bool can = true;
	int sumb=0;
	for(auto x:X) sumb += x;
	if(sumb!=b) can = false;
	for(auto x:Y) sumb -= x;
	if(sumb!=0) can = false;

	if(!can) cout<<"No"<<endl;
	else
	{
		cout<<"Yes"<<endl;
		for(auto y:Y) cout<<y;
		cout<<endl;
		for(auto x:X) cout<<x;
		cout<<endl;
	}

}	