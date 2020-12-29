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
	int n;
	cin>>n;
	vi A(n+1);
	cin>>A[1]>>A[n];
	if(n==2)
	{
		cout<<"!"<<A[1]<<A[2]<<endl;
		return 0;
	}
	for(int i=2;i<=n-1;i++)
	{
		cout<<"Q ";
		int l1,l2,l3,l4;
		cout<<i-1<<" "<<i<<" "<<i-1<<" "<<i<<endl;
		cin>>l1;
		cout<<i-1<<" "<<i<<" "<<i<<" "<<i+1<<endl;
		cin>>l2;
		cout<<i<<" "<<i+1<<" "<<i-1<<" "<<i<<endl;
		cin>>l3;
		cout<<i<<" "<<i+1<<" "<<i<<" "<<i+1<<endl;
		cin>>l4;

		if(l1==l3&&l1!=l2)
		{
			A[2] = l1 + A[1];
			A[3] = A[2] - l2; 
		}
		else if(l1==l2&&)
	}
}	