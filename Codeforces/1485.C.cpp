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
		int x,y;
		cin>>x>>y;
		if(x==1)
		{
			cout<<0<<endl;
			continue;
		}
		int ans = 0;
		int curr = 2;
		while(curr*curr <= x && curr <= y)
		{
			ans += curr*curr/(curr+1);
			curr++;
		}

		vi D;
		for(int i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				if(i>=curr+1 && x/i <=min(x,y+1)) D.push_back(i);
				if(i*i!=x && x/i>=curr+1 && x/i <=min(x,y+1)) D.push_back(x/i);
			}
		}
		sort(all(D));
		reverse(all(D));
		int last = curr+1;
		for(int i=1;i<D.size();i++)
		{
			if(D[i]<last) continue;
			cout<<D[i]<<" "<<max((min({x,y+1,D[i]}) - max(last,D[i-1]+1) + 1),0)<<endl;
			ans += (x / D[i]) * max(0,(min({x,y+1,D[i]}) - max(last,D[i-1]+1) + 1));
		}
		cout<<ans<<endl;
	}

}	