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
	test()
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<1<<"\n";
			cout<<1<<"\n";
			cout<<1<<"\n";
			cout<<"1 1\n";
			continue;
		}
		vector<int> C;
		int curr = 1;
		map<int,int> M;
		while(curr<=n)
		{
			C.push_back(curr);
			curr*=2;
		}
		if(curr<2*n)
		{
			C.push_back(n);
		}
		cout<<C.size()<<endl;
		for(int i=0;i<C.size();i++)
		{
			M[i+1]=0;
			cout<<C[i]<<" ";
		}
		cout<<endl;
		curr = 1;
		int d = 1;
		for(int i=1;i<=n;i++)
		{
			if(curr+1>C.size())
			{
				d = i;
				break;
			}
			if(i==1)
			{
				cout<<"2\n";
				cout<<"1 1\n1 2\n";
				M[1] = 1;
				M[2] = 1;
				curr = 2;
			}
			else
			{
				cout<<"3\n";
				cout<<i<<" "<<curr<<"\n";
				M[curr]++;
				cout<<M[curr+1]+1<<" "<<curr+1<<"\n";
				M[curr+1]++;
				cout<<M[curr+1]+1<<" "<<curr+1<<"\n";
				M[curr+1]++;
				if((i&(i-1))==0) curr++;
			}
		}
		for(int i=d;i<=n;i++)
		{
			cout<<1<<"\n";
			cout<<i<<" "<<curr<<"\n";
		}
	}
}	