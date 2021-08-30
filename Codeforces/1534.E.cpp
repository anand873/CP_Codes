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
	int n,k;
	cin>>n>>k;
	if((n%k)%2)
	{
		cout<<-1<<endl;
	}
	else
	{
		int xx = 0;
		int howt = n / k;
		for(int i=0;i<howt;i++)
		{
			cout<<"? ";
			for(int j=i*k+1;j<=i*k+k;j++)
			{
				cout<<j<<" ";
			}
			cout<<endl;

			int x;
			cin>>x;
			xx^=x;
		}
		

		int rem = n % k;
		if(rem==0)
		{
			cout<<"! "<<xx<<endl;
			return 0;
		}
		
		cout<<"? ";
		for(int i=1;i<=k-rem/2;i++)
		{
			cout<<i<<" ";
		}
		for(int j=howt*k+1;j<=howt*k+rem/2;j++)
		{
			cout<<j<<" ";
		}
		cout<<endl;
		int x;
		cin>>x;
		xx ^= x;

		cout<<"? ";
		for(int i=1;i<=k-rem/2;i++)
		{
			cout<<i<<" ";
		}
		for(int j=howt*k+1+rem/2;j<=howt*k+rem;j++)
		{
			cout<<j<<" ";
		}
		cout<<endl;
		cin>>x;
		xx ^= x;


		cout<<"! "<<xx<<endl;
	}
}	