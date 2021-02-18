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
	vi A(n+2,-1);
	A[0] = MOD;
	A[n+1] = MOD;
	int low = 1,high = n;
	int ans = -1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		int val=mid,val_back=mid-1,val_front = mid+1;
		if(A[val]==-1)
		{
			cout<<"? "<<val<<endl;
			cin>>A[val];
		}
		if(A[val_back]==-1)
		{
			cout<<"? "<<val_back<<endl;
			cin>>A[val_back];
		}
		if(A[val_front]==-1)
		{
			cout<<"? "<<val_front<<endl;
			cin>>A[val_front];
		}
		if(A[val]<min(A[val_front],A[val_back]))
		{
			ans = val;
			break;
		}
		else
		{
			if(A[val_back-1]==-1)
			{
				cout<<"? "<<val_back-1<<endl;
				cin>>A[val_back-1];
			}
			if(A[val_back] < min(A[val],A[val_back-1]))
			{
				ans = val_back;
				break;
			}
			else
			{
				if(A[val_back] < A[val]) high = val - 1;
				else low = val+1;
			}
		}
	}
	cout<<"! "<<ans<<endl;

}	