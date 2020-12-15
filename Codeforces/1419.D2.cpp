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

bool is_good(vi X)
{
	int n = X.size();
	for(int i=1;i<=n-1;i+=2)
	{
		if(X[i]<X[i-1]&&X[i]<X[i+1]) continue;
		else return false;
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	sort(all(A));
	int low=0,high=(n-1)/2;
	int ans = 0;
	vi Ans;
	while(low<=high)
	{
		int mid = low + (high-low)/2;

		vi S;
		for(int i=0;i<mid;i++)
		{
			S.push_back(A[i]);
		}
		vi B;
		for(int i=0;i<=mid;i++)
		{
			B.push_back(A[n-1-i]);
		}
		reverse(all(B));
		vi X;
		X.push_back(B[0]);
		for(int i=0;i<mid;i++)
		{
			X.push_back(S[i]);
			X.push_back(B[i+1]);
		}
		if(is_good(X))
		{
			ans = mid;
			low = mid+1;
			for(int i=mid;i<n-1-mid;i++) X.push_back(A[i]);
			Ans = X;
		}
		else high = mid-1;
	}
	cout<<ans<<endl;
	prinv(Ans);

}	