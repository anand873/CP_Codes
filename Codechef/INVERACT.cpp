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
const int MOD = 1e9+7,MAX = 1e6;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		vi A(n+1);
		ll inv = -1;
		while(low<=high)
		{
			int mid = low + (high-low)/2;
			cout<<"? "<<1<<" "<<mid<<endl;
			int left;
			cin>>left;
			cout<<"? "<<2<<" "<<mid<<endl;
			int right;
			cin>>right;
			if(left<right)
			{
				low = mid+1;
			}
			else if(right<left)
			{
				high = mid-1;
			}
			else
			{
				A[1] = mid;
				break;
			}
		}


		for(int i=2;i<=n;i++)
		{
			int low = 1,high = MAX;
			while(low<=high)
			{
				int mid = low + (high-low)/2;
				cout<<"? "<<i<<" "<<mid<<endl;
				int what;
				cin>>what;

				int whatshouldbe=0;
				for(int j = 1;j<i;j++)
				{
					if(A[j]>mid) whatshouldbe++;
				}

				if(what<inv)
				{

				}
			}
			
		}
		cout<<"!";
		for(int i=1;i<=n;i++) cout<<" "<<A[i];
		cout<<endl;
	}
}	