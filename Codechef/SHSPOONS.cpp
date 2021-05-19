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
		vl A(n);
		take(A,0,n);
		set<pair<ll,int>> S;
		map<int,ll> M;
		for(int i=0;i<n;i++)
		{
			M[i+1] = A[i];
			S.insert({A[i],-(i+1)});
		}
		bool can = true;
		vector<pair<pii,ll>> Ans;
		while(S.size()>1)
		{
			ll how = M[1];
			auto it = S.find({how,-1});

			if(it==S.begin())
			{
				auto aage = it;
				aage++;
				aage++;
				if(aage==S.end())
				{
					can = false;
					break;
				}
				else
				{
					it++;
					ll from = -(it->second);
					ll to = -(aage->second);
					S.erase({M[to],-to});
					M[to] += (M[from]-M[1]);
					S.insert({M[to],-to});

					S.erase({M[from],-from});
					S.insert({M[1],-from});
					Ans.push_back({{from,to},M[from]-M[1]});
					M[from] = M[1];
				}

			}
			else
			{
				it--;
				ll which = -(it->second);
				ll howmuch = M[which];
				M[which] = 0;
				S.erase({M[1],-1});
				M[1] += howmuch;
				S.insert({M[1],-1});
				S.erase({howmuch,-which});
				Ans.push_back({{which,1},howmuch});
			}
		}
		if(!can) cout<<-1<<endl;
		else
		{
			cout<<Ans.size()<<endl;
			for(auto ans:Ans)
			{
				cout<<ans.first.first<<" "<<ans.first.second<<" "<<ans.second<<endl;
			}
		}
	}
}	