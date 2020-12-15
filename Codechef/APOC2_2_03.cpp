//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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
		ll x,y;
		cin>>x>>y;
		queue<pair<pll,string>> Q;
		Q.push({{x,y},""});
		bool done = false;
		while(!Q.empty()&&!done)
		{
			auto curr = Q.front();
			Q.pop();
			ll x_this = curr.first.first;
			ll y_this = curr.first.second;
			string s_this = curr.second;
			if(!x_this&&!y_this)
			{
				cout<<s_this<<endl;
				done=true;
			}
			if(abs(x_this)%2&&abs(y_this)%2==0)
			{
				Q.push({{(x_this+1)/2,y_this/2},s_this+'W'});
				Q.push({{(x_this-1)/2,y_this/2},s_this+'E'});
			}
			else if(abs(x_this)%2==0&&abs(y_this)%2)
			{
				Q.push({{x_this/2,(y_this+1)/2},s_this+'S'});
				Q.push({{x_this/2,(y_this-1)/2},s_this+'N'});
			}
		}
		if(!done) cout<<"IMPOSSIBLE"<<endl;
	}
}	