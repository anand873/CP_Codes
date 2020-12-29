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
		int n;
		cin>>n;
		vi A(n);
		take(A,0,n);
		int curr = 1;
		vpii V;
		for(int i=1;i<n;i++)
		{
			if(A[i]==A[i-1])
			{
				curr++;
			}
			else
			{
				V.push_back({A[i-1],curr});
				curr=1;
			}
		}
		int ans = 0;
		V.push_back({A[n-1],curr});
		while(V.size())
		{
			// prinp(V.back());
			if(V.back().second%2==0) V.pop_back();
			else
			{
				if(V.size()>=2&&V[V.size()-2].second%2==0) {ans+=1;V.pop_back();}
				else
				{
					if(V.size()>=3&&V[V.size()-3].second%2&&V[V.size()-3].first==V.back().first&&V[V.size()-2].second==1)
					{
						ans++;
						V.pop_back();
						V.pop_back();
						V.pop_back();
					}
					else
					{
						ans++;
						V.pop_back();
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}	