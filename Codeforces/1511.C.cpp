//Author: AnandRaj uux
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

// Order Statistic Tree
/* Special functions: 
		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree< int, null_type, less<int>,
rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
	int n,q;
	cin>>n>>q;
	ordered_set S;
	map<int,set<int>> M;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		S.insert(i+1);
		M[a].insert(i+1);
	}
	int top = 1;
	for(int i=0;i<q;i++)
	{
		int t;
		cin>>t;
		int idx = *M[t].begin();
		M[t].erase(idx);
		int pos = S.order_of_key(idx);
		cout<<pos+1<<" ";
		S.erase(idx);
		S.insert(top-1);
		M[t].insert(top-1);
		top--;
	}
	cout<<endl;
	
}	