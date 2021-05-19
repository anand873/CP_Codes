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
		int n,m;
		cin>>n>>m;
		vi Y(n);
		take(Y,0,n);
		vpii YY(n);
		for(int i=0;i<n;i++)
		{
			YY[i] = {Y[i],i};
		}
		sort(all(YY));
		vi X(n),Idx(n);
		for(int i=0;i<n;i++)
		{
			X[i] = YY[i].first;
			Idx[YY[i].second]=i;
		}
		vector<char> s(n);
		for(int i=0;i<n;i++)
		{
			cin>>s[Idx[i]];
		}
		vi Ans(n,-1);
		vector<pii> So;
		vector<pii> Se;
		for(int i=0;i<n;i++)
		{
			// for(auto x:So) cout<<x.second<<" ";
			// cout<<endl;
			// for(auto x:Se) cout<<x.second<<" ";
			// cout<<endl;
			if(s[i]=='R')
			{
				if(X[i]%2) So.push_back({i,X[i]});
				else Se.push_back({i,X[i]});
			}
			else
			{
				if(X[i]%2)
				{
					if(So.empty())
					{
						So.push_back({i,-X[i]});
					}
					else
					{
						ll tim = (X[i]-So.back().second)/2;
						Ans[So.back().first] = tim;
						Ans[i] = tim;
						So.pop_back();
					}
				}
				else
				{
					if(Se.empty())
					{
						Se.push_back({i,-X[i]});
					}
					else
					{
						ll tim = (X[i]-Se.back().second)/2;
						Ans[Se.back().first] = tim;
						Ans[i] = tim;
						Se.pop_back();
					}
				}
			}
		}

		for(int i=So.size()-2;i>=0;i-=2)
		{
			int fir = So[i].second;
			int sec = So[i+1].second;

			int tim = (2*m-sec - fir)/2;
			Ans[So[i].first]=tim;
			Ans[So[i+1].first] = tim;
		}

		for(int i=Se.size()-2;i>=0;i-=2)
		{
			int fir = Se[i].second;
			int sec = Se[i+1].second;

			int tim = (2*m-sec - fir)/2;
			Ans[Se[i].first]=tim;
			Ans[Se[i+1].first] = tim;
		}
		vi Xa(n);
		for(int i=0;i<n;i++)
		{
			Xa[YY[i].second] = Ans[i];
		}
		prinv(Xa);
	}
}	