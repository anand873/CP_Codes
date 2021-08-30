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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

int main()
{
	int n,p;
	cin>>n>>m>>p;
	vl A(n);
	map<ll,vi> M;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char x;
			cin>>x;
			A[i] += (1LL<<j)*(x-'0');
		}
		if(A[i]&1) M[1].push_back(i);
		else M[0].push_back(i);
	}
	
	vi O;
	for(int i=0;i<n;i++) O.push_back(i);
	random_shuffle(all(O),rng);

	for(int i=0;i<min(200,n);i++)
	{
		int friend = A[O[i]];
	}
}	