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
		vi A(n);
		take(A,0,n);
		vector<vector<int>> VV;
		VV.push_back({0});
		for(int i=1;i<n;i++)
		{
			if(__gcd(A[i],A[i-1])!=1) VV.back().push_back(i);
			else
			{
				VV.push_back({i});
			}
		}
		dequeue<pii> V;
		for(auto v:VV)
		{
			V.push_back({v[0],v.back()});
		}
		vi vis(n);
		vi Ans;
		while(1)
		{
			int sz = Ans.size();
			dequeue<pii> NV;
			NV.push_back(V[0]);
			for(int i=0;i<V.size()-1;i++)
			{
				if(__gcd(A[NV.back().second],A[V[i+1].first])==1)
				{
					Ans.push_back(V[i+1].first);
					vis[V[i+1].first]=1;
					while(vis[V[i+1].first]==1 && V[i+1].first <= V[i+1].second)
					{
						V[i+1].first++;
					}
					if(V[i+1].first<=V[i+1].second)
					{
						if(__gcd(A[NV.back().second],A[V[i+1].first])==1)
						{
							NV.push_back(V[i+1]);
						}
						else
						{
							NV.back().second = V[i+1].second;
						}
					}
				}
			}
			if(__gcd(A[V.back().second],A[NV[0].first])==1)
			{
				Ans.push_back(NV[0].first);
				vis[NV[0].first] = 1;
				while(vis[NV[0].first]==1 && NV[0].first <= NV[0].second)
				{
					NV[0].first++;
				}
				if(NV[0].first <= NV[0].second)
				{
					NV.push_back(V.back());
				}
			}
			if(Ans.size() == sz) break;
			V = NV;
		}
		cout<<Ans.size()<<" ";
		for(int i=0;i<Ans.size();i++) cout<<Ans[i] + 1<<" ";
		cout<<endl;

	}
}	