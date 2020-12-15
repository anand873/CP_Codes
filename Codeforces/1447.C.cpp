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

void test_case()
{
	int n;
	ll w;
	cin>>n>>w;
	vector<pair<ll,int>> W(n);
	for(int i=0;i<n;i++)
	{
		cin>>W[i].first;
		W[i].second=i+1;
	}
	sort(all(W));
	set<int> S;
	ll sum = 0;
	for(int i=0;i<n;i++)
	{
		if(sum>=(w+1)/2&&sum<=w) break;
		else if(sum<(w+1)/2&&W[i].first>w)
		{
			cout<<-1<<endl;
			return;
		}
		else if(sum<(w+1)/2&&W[i].first>=(w+1)/2)
		{
			cout<<1<<endl;
			cout<<W[i].second<<endl;
			return;
		}
		else
		{
			sum+=W[i].first;
			S.insert(W[i].second);
		}
	}
	if(sum<(w+1)/2)
	{
		cout<<-1<<endl;
		return;
	}
	cout<<S.size()<<endl;
	prinv(S);
	return;
}

int main()
{
	test()
	{
		test_case();
	}
}	