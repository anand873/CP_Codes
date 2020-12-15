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
		vi A(n),B(n),C(n);
		take(A,0,n);
		take(B,0,n);
		take(C,0,n);
		vi D;
		D.push_back(min({A[0],B[0],C[0]}));
		for(int i=1;i<n;i++)
		{
			int mn = min({A[i],B[i],C[i]});
			int mx = max({A[i],B[i],C[i]});

			if(mn!=D.back()) D.push_back(mn);
			else D.push_back(mx);

			if(i==n-1)
			{
				if(D[0]==D[n-1])
				{
					if(D[0]!=A[n-1]&&D[n-2]!=A[n-1]) D[n-1]=A[n-1];
					else if(D[0]!=B[n-1]&&D[n-2]!=B[n-1]) D[n-1]=B[n-1];
					else D[n-1]=C[n-1];
				}
			}
		}
		prinv(D);

	}
}	