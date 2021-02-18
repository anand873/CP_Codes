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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n,q;
		cin>>n>>q;
		string s,f;
		cin>>s>>f;
		vi L(q),R(q);
		bitset<MAX> B(string(f));
		for(int i=0;i<q;i++)
		{
			cin>>L[i]>>R[i];
		}
		reverse(all(L));
		reverse(all(R));
		// bool can = true;
		// for(int i=0;i<q;i++)
		// {
		// 	int sum = TF.sum(L[i],R[i]);
		// 	if(2*sum>(R[i]-L[i]+1))
		// 	{
		// 		for(int j=L[i];j<=R[i];j++)
		// 		{
		// 			TF.set(j,1);
		// 		}
		// 	}
		// 	else if(2*sum<(R[i]-L[i]+1))
		// 	{
		// 		for(int j=L[i];j<=R[i];j++)
		// 		{
		// 			TF.set(j,0);
		// 		}
		// 	}
		// 	else
		// 	{
		// 		can = false;
		// 		break;
		// 	}
		// 	for(int i=1;i<=n;i++)
		// 	{
		// 		cout<<TF.Tree[i+n];
		// 	}
		// 	cout<<endl;
		// }
		// for(int i=1;i<=n;i++)
		// {
		// 	cout<<TF.Tree[i+n];
		// 	if(TF.Tree[i+n]!=(s[i-1]-'0')) can = false;
		// }
		// cout<<endl;
		// if(!can) cout<<"NO"<<endl;
		// else cout<<"YES"<<endl;
	}
}	