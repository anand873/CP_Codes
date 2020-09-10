//Author: AnandRaj doubleux
#include <bits/extc++.h>
using namespace std;

template <typename K, typename V, typename Comp = std::less<K>>
using order_statistic_map = __gnu_pbds::tree<
	K, V, Comp,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

template <typename K, typename Comp = std::less<K>>
using order_statistic_set = order_statistic_map<K, __gnu_pbds::null_type, Comp>;

// Supports
//  auto iterator = order_statistic_set().find_by_order(int); // (0-indexed)
//  int num_strictly_smaller = order_statistic_set().order_of_key(key);

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
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	unordered_map<int,int> Mf,Mb;
	vi dpf(n),dpb(n);

	for(int i=0;i<n;i++)
	{
		dpb[i] = ++Mb[A[i]];
	}
	for(int j=n-1;j>=0;j--)
	{
		dpf[j] = ++Mf[A[j]];
	}
	order_statistic_set<pair<int,int>> S;
	S.insert({dpf[n-1],n-1});
	ll ans = 0;
	for(int i=n-2;i>=0;i--)
	{
		ans += S.order_of_key({dpb[i],i});
		S.insert({dpf[i],i});
	}
	cout<<ans<<endl;

}	