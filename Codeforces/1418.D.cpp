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

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
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
	fastio
	int n,q;
	cin>>n>>q;
	vector<int> S(n);
	set<int> P;
	for(int i=0;i<n;i++)
	{
		cin>>S[i];
		P.insert(S[i]);
	}
	sort(all(S));

	multiset<int> D;
	for(int i=1;i<n;i++)
	{
		D.insert(S[i]-S[i-1]);
	}

	auto add = [&](int x)
	{
		auto aage = P.upper_bound(x);
		if(aage!=P.end())
		{
			D.insert(*aage - x);
		}
		if(aage!=P.begin())
		{
			D.insert(x - *prev(aage));
		}
		if(aage!=P.begin()&&aage!=P.end())
		{
			D.erase(D.find(*aage - *prev(aage)));
		}
		P.insert(x);
	};

	auto remove = [&](int x)
	{
		auto aage = P.find(x);
		assert(aage!=P.end());
		if(next(aage)!=P.end())
		{
			D.erase(D.find(*next(aage) - x));
		}
		if(aage!=P.begin())
		{
			D.erase(D.find(x - *prev(aage)));
		}
		if(aage!=P.begin()&&next(aage)!=P.end())
		{
			D.insert(*next(aage) - *prev(aage));
		}
		P.erase(x);
	};
	if(D.empty()) cout<<0<<"\n";
	else cout<<*P.rbegin()-*P.begin() - *D.rbegin()<<"\n";
	while(q--)
	{
		int t,x;
		cin>>t>>x;
		if(t==0)
		{
			remove(x);
		}
		else
		{
			add(x);
		}
		if(D.empty()) cout<<0<<"\n";
		else cout<<*P.rbegin()-*P.begin() - *D.rbegin()<<"\n";
	}
	
}	