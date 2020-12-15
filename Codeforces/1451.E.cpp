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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

int main()
{
	int n;
	cin>>n;
	vi A(n+1);
	int x12,x23,x13;
	cout<<"XOR 1 2"<<endl;
	cin>>x12;
	cout<<"XOR 2 3"<<endl;
	cin>>x23;
	x13 = x12^x23;
	int a12,a23,a13;
	cout<<"AND 1 2"<<endl;
	cin>>a12;
	cout<<"AND 1 3"<<endl;
	cin>>a13;
	cout<<"AND 2 3"<<endl;
	cin>>a23;

	int s12,s23,s13;
	s12 = x12 + 2*a12;
	s23 = x23 + 2*a23;
	s13 = x13 + 2*a13;
	A[1] = (s12 - s23 + s13)/2;
	A[2] = (s23 - s13 + s12)/2;
	A[3] = (s13 - s12 + s23)/2;
	for(int i=4;i<=n;i++)
	{
		cout<<"XOR 3 "<<i<<endl;
		int x;
		cin>>x;
		A[i] = x^A[3];
	}
	cout<<"!";
	for(int i=1;i<=n;i++) cout<<" "<<A[i];
	cout<<endl;
}	