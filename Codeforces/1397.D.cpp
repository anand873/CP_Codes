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

// int Sim(vi A,int last)
// {
// 	bool can=false;
// 	for(int i=0;i<A.size();i++)
// 	{
// 		if(i==last) continue;
// 		if(A[i]!=0) can=true;
// 	}
// 	if(!can)
// 	{
// 		return 1;
// 	}
// 	else
// 	{
// 		int n=A.size();
// 		set<int> W;
// 		for(int i=0;i<n;i++)
// 		{
// 			if(last==i||A[i]==0) continue;
// 			vi X = A;
// 			X[i]-=1;
// 			W.insert(1-Sim(X,i));
// 		}
// 		if(W.size()==1&&*(W.begin())==1) return 1;
// 		else return 0;
// 	}
// }

int main()
{
	test()
	{
		int n;
		cin>>n;
		vi A(n);
		take(A,0,n);
		sort(all(A));
		reverse(all(A));
		int xo=A[0];
		int sum=0;
		for(int i=1;i<n;i++)
		{
			xo^=A[i];
			sum+=A[i];
		}
		if(A[0]>sum||xo%2==1)
		{
			cout<<"T"<<endl;
		}
		else cout<<"HL"<<endl;
		
	}
}	