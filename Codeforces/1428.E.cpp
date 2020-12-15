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

int mid;
bool cmp(int x,int y)
{
	return (x%mid)<(y%mid);
}

int main()
{
	int n,k;
	cin>>n>>k;
	vi A(n);
	take(A,0,n);
	sort(all(A));
	int low=1,high=A[n-1];
	ll ans=INF;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		int how=0;
		sort(all(A),cmp);
		int norm = 0;
		int change = 0;
		for(int i=0;i<n;i++)
		{
			norm += A[i]/mid;
			change += (A[i]%mid!=0);
		}
		if(norm+change<k)
		{
			high = mid-1;
			continue;
		}
		// cerr<<mid<<endl;
		int howmanytoadd = (norm+change)-k;
		vi Sz;
		// prinv(A);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<A[i]/mid;j++)
			{
				Sz.push_back(mid);
			}
			if(howmanytoadd&&A[i]%mid)
			{
				Sz.pop_back();
				Sz.push_back(mid + A[i]%mid);
				howmanytoadd--;
			}
			else if(A[i]%mid)
			{
				Sz.push_back(A[i]%mid);
			}
		}
		sort(all(Sz));
		// prinv(Sz);
		vi NewSz;
		int i=0;
		while(i+1<Sz.size())
		{
			if(howmanytoadd)
			{
				NewSz.push_back(Sz[i]+Sz[i+1]);
				i+=2;
				howmanytoadd--;
			}
			else break;
		}
		// prinv(NewSz);
		if(howmanytoadd)
		{
			high = mid-1;
			continue;
		}
		
		for(;i<Sz.size();i++)
		{
			NewSz.push_back(Sz[i]);
		}
		// prinv(NewSz);
		ll sum=0;
		for(auto s:NewSz)
		{
			sum += (ll)s*s;
		}
		ans = min(ans,sum);
		low = mid+1;
	}
	cout<<ans<<endl;
}	