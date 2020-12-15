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
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	set<pii> S;
	map<int,int> DI;
	for(int i=1;i<n;i++)
	{
		S.insert({A[i]+A[i-1],i-1});
		DI[i-1]=A[i]+A[i-1];
	}
	set<int> Index;
	for(int i=0;i<n-1;i++)
	{
		Index.insert(i);
	}
	
	while(S.size()>1)
	{
		if(S.size()%2)
		{
			auto big = S.rbegin();

			int idx = big->second;
			if(idx==*Index.begin())
			{

			}
			else
			{
				auto This = Index.lower_bound(idx);
				auto back=This;
				back--;
				auto next=This;
				next++;
				int idxback = *back;
				if(next!=Index.end())
				{
					int idxnext = *next;
					Index.erase(idxnext);
					Index.erase(idxback);
					S.erase({DI[idxback],idxback});
					S.erase({DI[idxnext],idxnext});
					S.insert({})
				}
			}
		}
	}

}	