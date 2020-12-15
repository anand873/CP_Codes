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
	ll x1,x2,y1,y2;
	cin>>x1>>y1;
	cin>>x2>>y2;

	x2-=x1;
	x1-=x1;

	y2-=y1;
	y1-=y1;

	x1+=2;
	y1+=2;
	x2+=2;
	y2+=2;

	ll longcol = (x2+1)/2 - x1/2;
	ll shortcol = x2/2 - (x1-1)/2;

	ll longme = (y2+1)/2 - y1/2;
	ll shortme = y2/2 - (y1-1)/2;

	cout<<longme*longcol + shortme*shortcol<<endl;
}	