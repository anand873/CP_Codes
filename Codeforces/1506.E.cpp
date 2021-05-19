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
		vi Q(n+1);
		take(Q,1,n);
		vi MI(n+1),MA(n+1);
		MI[1] = Q[1];
		set<int> S;
		for(int i=1;i<=n;i++) S.insert(i);
		for(int i=1;i<=n;i++)
		{
			if(S.count(Q[i])) S.erase(Q[i]);
		}
		for(int i=2;i<=n;i++)
		{
			if(Q[i]==Q[i-1])
			{
				MI[i] = *S.begin();
				S.erase(MI[i]);
			}
			else
			{
				MI[i] = Q[i];
			}
		}

		for(int i=1;i<=n;i++) S.insert(i);
		for(int i=1;i<=n;i++)
		{
			if(S.count(Q[i])) S.erase(Q[i]);
		}
		MA[1] = Q[1];
		for(int i=2;i<=n;i++)
		{
			if(Q[i]==Q[i-1])
			{
				auto it = S.upper_bound(Q[i]);
				it--;
				MA[i] = *it;
				S.erase(MA[i]);
			}
			else
			{
				MA[i] = Q[i];
			}
		}
		for(int i=1;i<=n;i++) cout<<MI[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++) cout<<MA[i]<<" ";
		cout<<endl;
	}
}	