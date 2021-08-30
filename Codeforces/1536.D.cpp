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
const int MOD = 1e9,MAX = 5e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		vi B(n);
		take(B,0,n);
		bool can = true;
		deque<int> ML,MR;
		int med = B[0];
		for(int i=1;i<n;i++)
		{
			if(B[i]==B[i-1])
			{
				ML.push_back(-MOD);
				MR.push_back(MOD);
			}
			else if(B[i] < B[i-1])
			{
				ML.push_back(-MOD);
				ML.push_back(-MOD);
				if(ML.front()==-MOD || ML.front()==B[i])
				{
					ML.pop_front();
					MR.push_front(med);
					med = B[i];
				}
				else if(ML.front() < B[i])
				{
					ML.pop_back();
					MR.push_front(med);
					med = B[i];
				}
				else
				{
					can = false;
					break;
				}
			}
			else
			{
				MR.push_back(MOD);
				MR.push_back(MOD);
				if(MR.front()==MOD || MR.front()==B[i])
				{
					MR.pop_front();
					ML.push_front(med);
					med = B[i];
				}
				else if(MR.front() > B[i])
				{
					MR.pop_back();
					ML.push_front(med);
					med = B[i];
				}
				else
				{
					can = false;
					break;
				}
			}
		}
		
		if(!can) cout<<"NO\n";
		else cout<<"YES\n";

	}
}	