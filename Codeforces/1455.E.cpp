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

#define x first
#define y second

ll dis(pii X, pii Y)
{
	return abs(X.x-Y.x)+abs(X.y-Y.y);
}

ll cost(int len, vpii P)
{
	ll val = INF;
	for(int j=0;j<4;j++)
	{	
		vpii PP;
		for(int i=0;i<4;i++)
		{
			if(i==j) continue;
			PP.push_back(P[i]);
		}
		// Up;
		vpii TOP = {{P[j].x+len,P[j].y},{P[j].x,P[j].y+len},{P[j].x+len,P[j].y+len}};
		vi Ord = {1,2,3};
		do
		{
			ll valtemp = 0;
			for(int i=1;i<=3;i++)
			{
				valtemp += dis(TOP[Ord[i-1]-1],PP[i-1]);
			}
			val = min(valtemp,val);
		}while(next_permutation(all(Ord)));

		//Down
		vpii DOP = {{P[j].x+len,P[j].y},{P[j].x,P[j].y-len},{P[j].x+len,P[j].y-len}};
		Ord = {1,2,3};
		do
		{
			ll valtemp = 0;
			for(int i=1;i<=3;i++)
			{
				valtemp += dis(DOP[Ord[i-1]-1],PP[i-1]);
			}
			val = min(valtemp,val);
		}while(next_permutation(all(Ord)));

		//BUp
		DOP = {{P[j].x-len,P[j].y},{P[j].x,P[j].y+len},{P[j].x-len,P[j].y+len}};
		Ord = {1,2,3};
		do
		{
			ll valtemp = 0;
			for(int i=1;i<=3;i++)
			{
				valtemp += dis(DOP[Ord[i-1]-1],PP[i-1]);
			}
			val = min(valtemp,val);
		}while(next_permutation(all(Ord)));

		//BDown
		DOP = {{P[j].x-len,P[j].y},{P[j].x,P[j].y-len},{P[j].x-len,P[j].y-len}};
		Ord = {1,2,3};
		do
		{
			ll valtemp = 0;
			for(int i=1;i<=3;i++)
			{
				valtemp += dis(DOP[Ord[i-1]-1],PP[i-1]);
			}
			val = min(valtemp,val);
		}while(next_permutation(all(Ord)));
	}
	return val;
}

int main()
{
	test()
	{
		vpii P(4);
		for(int i=0;i<4;i++)
		{
			cin>>P[i].x >>P[i].y;
		}
		ll ans = -1;
		sort(all(P));
		int low = 1,high = MOD;
		while(low<=high)
		{
			int mid = low+(high-low)/2;

			int back = cost(mid-1,P);
			int curr = cost(mid,P); 
			cout<<mid<<" "<<curr<<endl;
			if(curr<=back)
			{
				ans = curr;
				low = mid+1;
			}
			else
			{
				ans = back;			
				high = mid-1;
			}
		}
		cout<<ans<<endl;
	}
}	