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
	fastio
	test()
	{
		int n;
		cin>>n;
		vl A(n+1);
		take(A,1,n);
		vvi Ans;

		for(int i=3;i<=n;i+=2)
		{
			if(A[i-2] <= A[i-1] && A[i-1] <= A[i]) continue;
			else if(A[i-2]<=A[i-1] && A[i-1]>=A[i])
			{
				Ans.push_back({2,i,A[i-1]-A[i]});
				int k = A[i-1]-A[i];
				for(int j=i;j<=n;j++) A[j]+=k;
			}
			else if(A[i-2]>A[i-1] && A[i-1]>=A[i])
			{
				int k = (1<<30) - 1;
				int mp = 29;
				while(mp>=0 && ((A[i-2]>>mp) & 1) == ((A[i-1]>>mp)&1)) {k^=(1<<mp);mp--;}

				Ans.push_back({4,i-1,k});
				for(int j=i;j<=n;j++) A[j]^=k;
			}
			else if(A[i-2]>A[i-1] && A[i-1]<=A[i])
			{
				Ans.push_back({2,i-1,A[i-2]-A[i-1]});
				int k = A[i-2]-A[i-1];
				for(int j=i-1;j<=n;j++) A[j]+=k;
			}
		}
		if(n%2==0)
		{
			if(A[n] < A[n-1])
			{
				Ans.push_back({2,n,A[n-1]-A[n]});
				A[n] = A[n-1];
			}
		}

		// prinv(A);
		assert(Ans.size() <= A.size()/2);
		cout<<Ans.size()<<"\n";
		for(auto a:Ans)
		{
			for(auto aa:a)
			{
				cout<<aa<<" ";
			}
			cout<<"\n";
		}
	}
}	