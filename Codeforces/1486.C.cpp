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

map<pii,int> M;

int find_left(int u, int sec)
{
	int ans;
	int low = u, high = sec-1;
	while(low<=high)
	{
		int mid = low + (high - low) / 2;
		if(M.find({mid,sec})==M.end())
		{
			cout<<"? "<<mid<<" "<<sec<<endl;
			cin>>M[{mid,sec}];
		}
		if(M[{mid,sec}]==sec)
		{
			ans = mid;
			low = mid+1;
		}
		else high = mid-1;
	}
	return ans;
}

int find_right(int sec, int v)
{
	int ans;
	int low = sec+1, high = v;
	while(low<=high)
	{
		int mid = low + (high - low) / 2;
		if(M.find({sec,mid})==M.end())
		{
			cout<<"? "<<sec<<" "<<mid<<endl;
			cin>>M[{sec,mid}];
		}
		if(M[{sec,mid}]==sec)
		{
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<"? "<<1<<" "<<n<<endl;
	int sec;
	cin>>sec;
	M[{1,n}] = sec;
	int ans;
	if(n==2)
	{
		ans = 3 - sec;
	}
	else
	{
		if(sec==1)
		{
			ans = find_right(sec,n);
		}
		else if(sec==n)
		{
			ans = find_left(1,sec);
		}
		else if(M.find({1,sec})==M.end())
		{
			cout<<"? "<<1<<" "<<sec<<endl;
			cin>>M[{1,sec}];
		}
		if(M[{1,sec}]==M[{1,n}])
		{
			ans = find_left(1,sec);
		}
		else
		{
			ans = find_right(sec,n);
		}
	}
	cout<<"! "<<ans<<endl;
}	