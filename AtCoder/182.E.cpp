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

vi xd = {1,-1,0,0};
vi yd = {0,0,1,-1};

bool is_ok(int x,int y, int xl,int yl)
{
	return x<=xl&&x>=1&&y<=yl&&y>=1;
}

int main()
{
	int h,w,n,m;
	cin>>h>>w>>n>>m;
	vvi A(h+2,vi(w+2));
	queue<pii> Q;
	vector<pii> P;
	vvi D(h+1,vi(w+1));
	for(int i=0;i<n;i++)
	{
		int a,b;

		// a = i+1;
		// b = i+1;
		cin>>a>>b;
		A[a][b]=1;
	}
	for(int i=0;i<m;i++)
	{
		int c,d;
		cin>>c>>d;
		A[c][d]=-1;
	}

	vvi X;
	X = A;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			X[i][j]+=X[i][j-1];
			X[i][j]=max(0,min(X[i][j],1));
			if(X[i][j]>0)
			{
				D[i][j]++;
			}
		}
	}
	X = A;
	for(int i=1;i<=h;i++)
	{
		for(int j=w;j>=1;j--)
		{
			X[i][j]+=X[i][j+1];
			X[i][j]=max(0,min(X[i][j],1));
			if(X[i][j]>0)
			{
				D[i][j]++;
			}
		}
	}
	X = A;
	for(int j=1;j<=w;j++)
	{
		for(int i=h;i>=1;i--)
		{
			X[i][j]+=X[i+1][j];
			X[i][j]=max(0,min(X[i][j],1));
			if(X[i][j]>0)
			{
				D[i][j]++;
			}
		}
	}
	X = A;
	for(int j=1;j<=w;j++)
	{
		for(int i=1;i<=h;i++)
		{
			X[i][j]+=X[i-1][j];
			X[i][j]=max(0,min(X[i][j],1));
			if(X[i][j]>0)
			{
				D[i][j]++;
			}
		}
	}
	int ans = 0;
	for(int j=1;j<=w;j++)
	{
		for(int i=1;i<=h;i++)
		{
			if(D[i][j]>0) ans++;
		}
	}
	cout<<ans<<endl;

}		