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
		int n,k;
		cin>>n>>k;
		vi CT(n+1,MOD);
		vi A(k+1);
		take(A,1,k);
		vi T(k+1);
		take(T,1,k);
		set<pii> Temp;
		for(int i=1;i<=k;i++)
		{
			CT[A[i]] = T[i];
			Temp.insert({T[i],i});
		}
		for(auto temp:Temp)
		{
			int ai = A[temp.second];
			int ti = temp.first;
			for(int i=ai-1;i>=1;i--)
			{
				int del = ai - i;
				if(CT[i] > ti + del)
				{
					CT[i] = ti + del;
				}
				else break;
			}
			for(int i = ai+1;i<=n;i++)
			{
				int del = i - ai;
				if(CT[i] > ti + del)
				{
					CT[i] = ti + del;
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<CT[i]<<" ";
		}
		cout<<endl;
	}
}	