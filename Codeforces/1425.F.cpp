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
	vi A(n);

	cout<<"? 1 "<<n<<endl;	// Total Sum

	int totsum;
	int sum;
	cin>>sum;
	totsum = sum;
	
	for(int i=0;i<n-2;i++)
	{
		cout<<"? 1 "<<n-1-i<<endl;	// Prefix Sum upto N-1-i
		int sumx;
		cin>>sumx;
		A[n-i-1] = sum - sumx;
		sum = sumx;
	}


	cout<<"? 2 "<<n<<endl;	// Suffix Sum from 2 to N
	int xsum;
	cin>>xsum;
	A[0] = totsum - xsum;	// First number is Total - Suffix from 2-N
	A[1] = sum - A[0];		// Second number is Q(1,2) - First
	
	cout<<"! ";
	prinv(A);
	exit(0);
}