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
const int MOD = 1e9+7,MAX = 1e4+5;
const ll INF = 1e18+5;


int main()
{
	fastio
	test()
	{
		int n;
		cin>>n;
		vpii A(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>A[i].first;
			A[i].second = i;
		}
		sort(all(A));
		int low=1,high=n;
		int ans = 0;
		while(low<=high)
		{
			int mid = low + (high-low)/2;
			ll sum = 0;
			for(int i=1;i<=mid;i++) sum += A[i].first;
			bool can = true;
			for(int i=mid+1;i<=n;i++)
			{
				if(A[i].first>sum) {can = false;break;}
				else
				{
					sum += A[i].first;
				}
			}
			if(can)
			{
				ans = n - mid +1;
				high = mid-1;
			}
			else low = mid+1;
		}
		cout<<ans<<"\n";
		vector<int> Ans;
		for(int i=n - ans + 1;i<=n;i++) Ans.push_back(A[i].second);
		sort(all(Ans));
		for(auto a:Ans) cout<<a<<" ";
		cout<<"\n";
	}
}	