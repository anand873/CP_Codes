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
		
		set<int> S;
		set<int> Sd;
		for(int i=1;i<=2*n;i++)
		{
			S.insert(i);
		}
		int ans = 0;
		vpii Ed;
		for(int i=0;i<k;i++)
		{
			int a,b;
			cin>>a>>b;
			if(a>b) swap(a,b);
			if(!Ed.empty())
			{
				set<int> S1,S2;
				S2 = Sd;
				for(int i=a+1;i<b;i++)
				{
					if(S2.count(i)) S1.insert(i);
					S2.erase(i);
				}
				for(auto ed:Ed)
				{
					if((S1.count(ed.first) && S2.count(ed.second)) || (S2.count(ed.first) && S1.count(ed.second))) ans++;
				}
			}
			Ed.push_back({a,b});
			Sd.insert(a);
			Sd.insert(b);
			S.erase(a);
			S.erase(b);
		}
		vector<int> V;
		for(auto s:S) V.push_back(s);

		for(int i=0;i<n-k;i++)
		{
			int a = V[i];
			int b = V[i+n-k];
			set<int> S1,S2;
			S2 = Sd;

			for(int i=a+1;i<b;i++)
			{
				if(S2.count(i)) S1.insert(i);
				S2.erase(i);
			}

			for(auto ed:Ed)
			{
				if((S1.count(ed.first) && S2.count(ed.second)) || (S2.count(ed.first) && S1.count(ed.second))) ans++;
			}
			Ed.push_back({a,b});
			Sd.insert(a);
			Sd.insert(b);
		}
		cout<<ans<<endl;
	}
}	