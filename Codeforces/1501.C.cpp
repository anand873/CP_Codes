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
const int MOD = 1e9+7,MAX = 5e6+5;
const ll INF = 1e18+5;

const int SQ = 2250;

int main()
{
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	map<int,int> M1,M2;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int sum = A[i] + A[j];
			if(M1.find(sum) == M1.end())
			{
				M1[sum]=i;
				M2[sum]=j;
			}
			else
			{
				if(M1[sum]==i) continue;
				if(M2[sum]!= i && M2[sum]!=j)
				{
					cout<<"YES"<<endl;
					cout<<M1[sum]+1<<" "<<M2[sum]+1<<" "<<i+1<<" "<<j+1<<endl;
					return 0;
				}
			}
			
		}
	}
	cout<<"NO"<<endl;
}	