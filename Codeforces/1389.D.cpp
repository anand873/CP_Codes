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
		ll n,I;
		cin>>n>>I;
		ll l1,r1;
		cin>>l1>>r1;
		ll l2,r2;
		cin>>l2>>r2;

		ll low = 0,high = INF;

		ll ans = 0;
		ll curr = max(0ll,min(r1,r2)-max(l1,l2));
		// what(curr);
		I-=curr*n;
		ll rem = max(0ll,I);
		for(int i=0;i<n;i++)
		{
			if(max(r2,r1)-min(l2,l1)-curr<=rem)
			{
				rem -= max(r2,r1)-min(l2,l1)-curr;
				ans += max(l1,l2)-min(l1,l2)+max(r1,r2)-min(r1,r2);
				// cerr<<"Full "<<rem<<endl;
			}
			else
			{
				ans += min(2*rem,max(0ll,max(l1,l2)-min(r1,r2))+rem);
				rem = 0;
				break;
			}
		}
		if(rem) ans+=2*rem;
		cout<<max(0ll,ans)<<endl;


	}	
}	