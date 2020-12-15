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
		vi A(n+1);
		take(A,1,n);
		map<int,int> M;
		int sbse_jyada = 0;
		for(int i=1;i<=n;i++)
		{
			M[A[i]]++;
			sbse_jyada = max(sbse_jyada,M[A[i]]);
		}
		if(sbse_jyada>(n+1)/2) cout<<-1<<endl;
		else
		{
			map<int,int> M_bad;
			for(int i=1;i<n;i++)
			{
				if(A[i]==A[i+1]) M_bad[A[i]]++;
			}
			if(M_bad.size()==0) cout<<0<<endl;
			else if(M_bad.size()==1)
			{
				int what = M_bad.begin()->first;
				if(M_bad[what]==1)
				{
					cout<<1 + (A[1]==what && A[n]==what)<<endl;
				}
				else if(M_bad[what]==2)
				{
					cout<<2 + (A[1]==what) + (A[n]==what)<<endl;
				}
				else
				{
					cout<<2*(M_bad[what]-2) + 2 + (A[1]==what) + (A[n]==what)<<endl;
				}
			}
			else
			{
				int good = 0;
				vector<pii> V;
				for(auto m:M_bad)
				{
					V.push_back({m.second,m.first});
				}
				sort(all(V));
				for(int i=0;i<(int)V.size()-1;i++)
				{
					good+= V[i].first;
				}
				if(good>=V.back().first)
				{
					cout<<good + V.back().first<<endl;
				}
				else
				{
					int ans = 0;
					ans += 2*good;
					int what = V.back().second;
					M_bad[what] -= good;

					if(M_bad[what]==1)
					{
						cout<<ans + 1 + (A[1]==what && A[n]==what)<<endl;
					}
					else if(M_bad[what]==2)
					{
						cout<<ans + 2 + (A[1]==what) + (A[n]==what)<<endl;
					}
					else
					{
						cout<<ans + 2*(M_bad[what]-2) + 2 + (A[1]==what) + (A[n]==what)<<endl;
					}
				}
			}

		}
	}	
}	