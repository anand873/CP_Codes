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
const ll INF = 5e18+5;

int main()
{
	test()
	{
		ll x,y;
		cin>>x>>y;
		vl Dis(6);
		take(Dis,0,6);
		for(int i=0;i<6;i++)
		{
			Dis[i] = min(Dis[i],Dis[(i+5)%6]+Dis[(i+1)%6]);
		}


		ll ans = INF;
		ll temp = 0;
		// x,x -> x,y
		if(x<0)
		{
			temp += Dis[3]*(-x);
			if(y<x)
			{
				temp += Dis[4]*(x-y);
			}
			else
			{
				temp += Dis[1]*(y-x);
			}
			ans = min(ans,temp);
		}
		else
		{
			temp += Dis[0]*x; 
			if(y<x)
			{
				temp += Dis[4]*(x-y);
			}
			else
			{
				temp += Dis[1]*(y-x);
			}
			ans = min(ans,temp);
		}
		temp = 0;
		// y,y -> x,y
		if(y<0)
		{
			temp += Dis[3]*(-y);
			if(x<y)
			{
				temp += Dis[2]*(y-x);
			}
			else
			{
				temp += Dis[5]*(x-y);
			}
			ans = min(ans,temp);
		}
		else
		{
			temp += Dis[0]*y; 
			if(x<y)
			{
				temp += Dis[2]*(y-x);
			}
			else
			{
				temp += Dis[5]*(x-y);
			}
			ans = min(ans,temp);
		}
		temp = 0;
		//0,y -> x,y

		if(y<0)
		{
			temp += Dis[4]*(-y);
			if(x<0)
			{
				temp += Dis[2]*(-x);
			}
			else
			{
				temp += Dis[5]*(x);
			}
			ans = min(ans,temp);
		}
		else
		{
			temp += Dis[1]*y; 
			if(x<0)
			{
				temp += Dis[2]*(-x);
			}
			else
			{
				temp += Dis[5]*(x);
			}
			ans = min(ans,temp);
		}
		temp = 0;
		//x,0 -> x,y

		if(x<0)
		{
			temp += Dis[2]*(-x);
			if(y<0)
			{
				temp += Dis[4]*(-y);
			}
			else
			{
				temp += Dis[1]*(y);
			}
			ans = min(ans,temp);
		}
		else
		{
			temp += Dis[5]*x; 
			if(y<0)
			{
				temp += Dis[4]*(-y);
			}
			else
			{
				temp += Dis[1]*(y);
			}
			ans = min(ans,temp);
		}

		ll deltayx = y-x;
		ll deltaxy = x-y;
		temp = 0;
		
		// 0,delyx -> x,y
		if(deltayx<0)
		{
			temp += Dis[4]*(-deltayx);
			if(x<0)
			{
				temp += Dis[3]*(-x);
			}
			else
			{
				temp += Dis[0]*x;
			}
			ans = min(ans,temp);
		}
		else
		{
			temp += Dis[1]*(deltayx);
			if(x<0)
			{
				temp += Dis[3]*(-x);
			}
			else
			{
				temp += Dis[0]*x;
			}
			ans = min(ans,temp);
		}
		temp = 0;

		// delxy,0 -> x,y
		if(deltaxy<0)
		{
			temp += Dis[2]*(-deltaxy);
			if(y<0)
			{
				temp += Dis[3]*(-y);
			}
			else
			{
				temp += Dis[0]*y;
			}
			ans = min(ans,temp);
		}
		else
		{
			temp += Dis[5]*(deltaxy);
			if(y<0)
			{
				temp += Dis[3]*(-y);
			}
			else
			{
				temp += Dis[0]*y;
			}
			ans = min(ans,temp);
		}
		cout<<ans<<endl;
	}
}	