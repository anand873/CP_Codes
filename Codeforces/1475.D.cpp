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
		int n,m;
		cin>>n>>m;
		vi A(n+1);
		take(A,1,n);
		vi B(n+1);
		take(B,1,n);
		ll check = 0;
		for(int i=1;i<=n;i++)
		{
			check += A[i];
		}
		if(check<m)
		{
			cout<<-1<<endl;
			continue;
		}

		
		vl Tw,On;
		for(int i=1;i<=n;i++)
		{
			if(B[i]==1) On.push_back(A[i]);
			else Tw.push_back(A[i]);
		}
		sort(all(Tw));
		Tw.push_back(0);
		reverse(all(Tw));
		sort(all(On));
		On.push_back(0);
		reverse(all(On));

		for(int i=1;i<Tw.size();i++) Tw[i] += Tw[i-1];
		for(int i=1;i<On.size();i++) On[i] += On[i-1];
		int ans = MOD;
		for(int i=0;i<Tw.size();i++)
		{
			ll memory = Tw[i];
			ll extra = m-memory;
			if(extra<=0) ans = min(ans,2*i);
			else
			{
				int low = 0,high = On.size()-1;
				while(low<=high)
				{
					int mid = low + (high-low)/2;
					if(On[mid]>=extra)
					{
						high = mid-1;
						ans = min(ans, 2*i + mid);
					}
					else
					{
						low = mid+1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}	