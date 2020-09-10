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
	vi A(n);
	take(A,0,n);
	map<int,int> D;
	sort(all(A));
	for(int i=1;i<n;i++)
	{
		D[A[i]-A[i-1]]++;
	}
	if(D.size()==0)
	{
		cout<<-1<<endl;
	}
	else if(D.size()>2)
	{
		cout<<0<<endl;
	}
	else if(D.size()==1)
	{
		if(A.size()!=2||(A[1]-A[0])%2)
		{
			cout<<2<<endl;
			cout<<2*A[0]-A[1]<<" "<<2*A[n-1]-A[n-2]<<endl;
		}
		else
		{
			cout<<3<<endl;
			cout<<2*A[0]-A[1]<<" "<<(A[1]+A[0])/2<<" "<<2*A[n-1]-A[n-2]<<endl;
		}

	}
	else
	{
		int d1 = D.begin()->first;
		int d2 = D.rbegin()->first;

		if(D[d2]>1 || d2!=2*d1) cout<<0<<endl;
		else
		{
			cout<<1<<endl;
			for(int i=1;i<n;i++)
			{
				if(A[i]-A[i-1]==d2)
				{
					cout<<A[i-1]+d1<<endl;
					break;
				}
			}	
		}
	}
}	