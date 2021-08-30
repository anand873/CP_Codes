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
#define test() int q;cin>>q;while(q--)
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9,MAX = 5e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n,m;
		cin>>n>>m;
		vi P(n+1);
		take(P,1,n);

		vi WE(n);
		for(int i=1;i<=n;i++)
		{
			WE[(n + i - P[i]) % n]++; 
		}
		vi A;

		for(int k=0;k<n;k++)
		{
			if(n - WE[k] <= 2*m)
			{
				vi X;
				X.push_back(0);
				for(int num = n-k+1;num<=n;num++) X.push_back(num);

				for(int num=1;num<=n-k;num++) X.push_back(num);

				vi Idx(n+1);
				for(int i=1;i<=n;i++)
				{
					Idx[X[i]] = i;
				}

				int swaps = 0;
				for(int i=1;i<=n;i++)
				{
					if(X[i]==P[i]) continue;
					else
					{
						swap(X[i],X[Idx[P[i]]]);
						Idx[X[Idx[P[i]]]] = Idx[P[i]];
						swaps++;
					}
				}
				if(swaps<=m) A.push_back(k);
			}
		}
		cout<<A.size()<<" ";
		prinv(A);

	}
}	