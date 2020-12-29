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
		string s;
		cin>>s;
		int n = s.length();
		vi A(26);
		for(auto c:s)
		{
			A[c-'a']++;
		}
		multiset<int> S;
		for(int i=0;i<26;i++)
		{
			if(A[i]) S.insert(A[i]);
		}
		int ans = 0;
		// prinv(S);
		while(S.size()>1)
		{
			auto it = S.begin();
			auto itt = S.rbegin();
			int x = *it;
			int y = *itt;
			S.erase(S.find(x));
			S.erase(S.find(y));
			if(y>=2&&x>=1)
			{
				ans++;
				y-=2;
				x-=1;
				if(x) S.insert(x);
				if(y) S.insert(y);
			}
		}
		if(S.size()==1)
		{
			int x = *S.begin();
			ans += x/3;
		}
		cout<<ans<<endl;
	}
}	