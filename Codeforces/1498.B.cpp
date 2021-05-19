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
		int n,w;
		cin>>n>>w;
		vi W(n);
		take(W,0,n);
		map<int,int> M;
		for(int i=0;i<n;i++) M[W[i]]++;

		int row = 1;
		int left = w;
		while(1)
		{
			auto it = M.upper_bound(left);

			if(it==M.begin())
			{
				row++;
				left = w;
			}
			else
			{
				it--;
				int val = it->first;
				M[val]--;
				if(M[val]==0) M.erase(val);
				left -= val;
			}
			if(M.empty()) break;
		} 
		cout<<row<<endl;
	}
}	