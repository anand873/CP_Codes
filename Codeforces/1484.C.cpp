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
		vi C(m);
		vi H(n+1);
		vvi F(m);
		for(int i=0;i<m;i++)
		{
			int k;
			cin>>k;
			for(int j=0;j<k;j++)
			{
				int f;
				cin>>f;
				F[i].push_back(f);
			}
			C[i] = F[i][0];
			H[F[i][0]]++;
		}
		int maxi = 0;
		for(int i=1;i<=n;i++)
		{
			if(H[i] > H[maxi]) maxi = i;
		}

		if(H[maxi] <= (m+1)/2)
		{
			// cout<<maxi<<" "<<H[maxi]<<endl;
			cout<<"YES"<<endl;
			prinv(C);
		}
		else
		{
			for(int i=0;i<m;i++)
			{
				if(F[i].size() > 1 && F[i][0] == maxi && H[maxi] > (m+1)/2)
				{
					C[i] = F[i][1];
					H[maxi]--;
				}
			}
			if(H[maxi] <= (m+1)/2)
			{
				// cout<<maxi<<" "<<H[maxi]<<endl;
				cout<<"YES"<<endl;
				prinv(C);
			}
			else cout<<"NO"<<endl;
		}

	}
}	