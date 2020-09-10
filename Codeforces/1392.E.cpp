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
	vvl A(n,vl(n));
	A[0][0]=0;
	A[n-1][n-1]=0;
	int cnt = 0;
	for(int i=1;i<n;i++)
	{
		A[i][0] = 1;
		for(int j=1;j<=i;j++)
		{
			A[i-j][j] = A[i-j+1][j-1] + (1ll<<cnt);
		}
		cnt++;
	}
	for(int j=1;j<n-1;j++)
	{
		A[n-1][j] = 1;
		for(int i=n-2;i>=j;i--)
		{
			A[i][j+(n-i)-1] = A[i+1][j + (n-i)-2] + (1ll<<cnt);
		}
		cnt++;
	}

	for(int i=0;i<n;i++)
	{
		prinv(A[i]);
	}
	ll tadd = (1ll<<n-1) - 1 - (2*n-3);
	int q;
	cin>>q;
	while(q--)
	{
		ll k;
		cin>>k;
		k += tadd;
		string path;
		for(int i=0;i<2*n-2;i++)
		{
			if((k>>i)&1) path+='D';
			else path+='R';
		}
		int x = 1,y = 1;

		cout<<x<<" "<<y<<endl;
		for(int i=0;i<path.length();i++)
		{
			if(path[i]=='R') y+=1;
			else x+=1;

			cout<<x<<" "<<y<<endl;
		}

	}
}	