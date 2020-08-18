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
		int n,m;
		cin>>n>>m;
		vpii V(m);
		for(int i=0;i<m;i++)
		{
			cin>>V[i].first>>V[i].second;

		}
		
		ll sum=0;
		vector<bool> vis(m);
		set<pii> Curr;
		for(int i=0;i<m;i++)
		{
			Curr.insert({V[i].first,i});
		}

		int maxbi=0;
		int maxb=0;
		for(int i=0;i<m;i++)
		{
			if(V[i].second>=maxb)
			{
				maxb = V[i].second;
				maxbi = i;
			}
		}
		while(n&&maxb<Curr.rbegin()->first)
		{
			auto it = Curr.rbegin();
			set<pii> TC;
			while(n&&it->first>maxb&&it!=Curr.rend())
			{
				if(!vis[it->second])
				{
					TC.insert(*it);
					vis[it->second]=true;
					sum+=it->first;
					n--;
				}
				else
				{
					sum+=it->first;
					n--;
				}
				it++;
			}
			for(auto tc:TC)
			{
				Curr.erase(tc);
				Curr.insert({V[tc.second].second,tc.second});
			}
		}
		if(n)
		{
			if(vis[maxbi])
			{
				sum += n*maxb;
			}
			else
			{
				auto it = Curr.rbegin();
				while(it->second!=maxbi&&n)
				{
					sum+=it->first;
					n--;
				}
				sum += V[it->second].first + (n-1)*maxb;
			}
			
		}

		cout<<sum<<endl;


	}
}	